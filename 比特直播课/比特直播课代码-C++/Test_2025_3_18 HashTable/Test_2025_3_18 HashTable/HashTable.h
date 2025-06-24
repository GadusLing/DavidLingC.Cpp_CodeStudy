#pragma once
#include<vector>
#include<utility>
#include <algorithm>

using namespace std;

// 哈希表扩容用的素数表
// 这些接近2的幂次方的素数可以减少哈希冲突
static const int kNumPrimes = 28;  // 素数表大小
static const unsigned long kPrimeList[kNumPrimes] = 
{
    // 从53开始，每个素数大约为前一个的2倍
    53,         97,         193,        389,        769,
    1543,       3079,       6151,       12289,      24593,
    49157,      98317,      196613,     393241,     786433,
    1572869,    3145739,    6291469,    12582917,   25165843,
    50331653,   100663319,  201326611,  402653189,  805306457,
    1610612741, 3221225473, 4294967291  // 最后一个素数是2^32-5
};

 /**
 * 获取不小于n的最小素数
 * @param n 输入数值
 * @return 素数表中≥n的最小素数，如果n超过最大值则返回最后一个素数
 */
inline unsigned long NextPrime(unsigned long n) 
{
    const unsigned long* first = kPrimeList;          // 素数表起始位置
    const unsigned long* last = kPrimeList + kNumPrimes;  // 结束位置(尾后指针)
    const unsigned long* pos = std::lower_bound(first, last, n);  // 二分查找

    // 如果n比所有素数都大，返回最后一个素数；否则返回找到的位置的值
    return pos == last ? *(last - 1) : *pos;
}


template<class K>
struct HashFunc
{
    size_t operator()(const K& key)
    {
        return (size_t)key;
    }
};

template<>
struct HashFunc<string>
{
    size_t operator()(const string& key)
    {
        size_t hashi = 0;
        for (auto ch : key)
        {
            hashi *= 131;
            hashi += ch;
        }
        return hashi;
    }
};

namespace hash_bucket
{
    template<class T>
    struct HashNode
    {
        T _data;
        HashNode<T>* _next;

        HashNode(const T& data)
            :_data(data)
            ,_next(nullptr)
        {
        }
    };

    //解决HTIterator和HashTable相互依赖关系，用前置声明
    template<class K, class T, class KeyOFT, class Hash >
    class HashTable;

    template<class K, class T, class Ref, class Ptr, class KeyOFT, class Hash>
    struct HTIterator
    {
        typedef HashNode<T> Node;
        typedef HashTable<K, T, KeyOFT, Hash> HT;//这里会出现 : 缺少“; ”(在“ < ”的前面) 实际是因为HTIterator和HashTable存在依赖的关系，编译时只会向上查找，但因为相互依赖，所以要用前置声明解决
        typedef HTIterator<K, T, Ref, Ptr, KeyOFT, Hash> Self;

        Node* _node;
        const HT* _ht;

        HTIterator(Node* node,const HT* ht)
            :_node(node)
            ,_ht(ht)
        {}

        Ref operator*()
        {
            return _node->_data;
        }

        Ptr operator->()
        {
            return &_node->_data;
        }

        Self& operator++()
        {
            if (_node->_next)
            {
                //当前桶迭代
                _node = _node->_next;
            }
            else
            {
                // 找下一个桶的第一个节点
                KeyOFT kot;
                Hash hs;
                size_t hashi = hs(kot(_node->_data)) % _ht->_tables.size();
                ++hashi;
                while (hashi < _ht->_tables.size())
                {
                    if (_ht->_tables[hashi])
                    {
                        _node = _ht->_tables[hashi];
                        break;
                    }
                    else
                    {
                        ++hashi;
                    }
                }
                // 当所有桶都走完了，nullptr去做end()
                if (hashi == _ht->_tables.size())
                {
                    _node = nullptr;
                }
            }
            return *this;
        }

        bool operator!=(const Self& s)
        {
            return _node != s._node;
        }

        bool operator==(const Self& s)
        {
            return _node == s._node;
        }

    };


    template<class K, class T, class KeyOFT, class Hash>
    class HashTable
    {
        template<class K, class T, class Ref, class Ptr, class KeyOFT, class Hash>// 模板类友元记得要把声明参数都带上
        friend struct HTIterator;

        typedef HashNode<T> Node;
    public:

        typedef HTIterator<K, T, T&, T*, KeyOFT, Hash> Iterator;
        typedef HTIterator<K, T, const T&, const T*, KeyOFT, Hash> ConstIterator;

        Iterator Begin()
        {
            // 找第一个不为空的桶里面的第一个节点
            for (size_t i = 0; i < _tables.size(); ++i)
            {
                if (_tables[i])
                {
                    return Iterator(_tables[i], this);
                }
            }
            return End();
        }

        Iterator End()
        {
            return Iterator(nullptr, this);
        }

        ConstIterator Begin() const
        {
            for (size_t i = 0; i < _tables.size(); ++i)
            {
                if (_tables[i])
                {
                    return ConstIterator(_tables[i], this);
                }
            }
            return End();
        }

        ConstIterator End() const
        {
            return ConstIterator(nullptr, this);
        }


        HashTable(size_t size = NextPrime(0))
            :_tables(size, nullptr)
        {}

        ~HashTable()
        {
            for (size_t i = 0; i < _tables.size(); i++)
            {
                Node* cur = _tables[i];
                while (cur)
                {
                    Node* next = cur->_next;
                    delete cur;
                    cur = next;
                }
                _tables[i] = nullptr;
            }
        }

        pair<Iterator, bool> Insert(const T& data)
        {
            KeyOFT kot;
            Iterator it = Find(kot(data));
            if (it != End()) return { it, false };//这里false表示元素已存在;
            
            //扩容            
            Hash hs;
            //负载因子到1，再扩容
            if (_n == _tables.size())
            {
                vector<Node*> newtables(NextPrime(_tables.size() + 1), nullptr);
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    while (cur)
                    {
                        //把旧表的节点插入到新表
                        Node* next = cur->_next;
                        size_t hashi = hs(kot(cur->_data)) % newtables.size();
                        cur->_next = newtables[hashi];
                        newtables[hashi] = cur;//换到新表原始的顺序会倒转，但是无所谓，不影响功能，甚至不只是倒转，连桶内的数量都变了
                        cur = next;
                    }
                    _tables[i] = nullptr;
                }
                _tables.swap(newtables);
            }
            size_t hashi = hs(kot(data)) % _tables.size();
            Node* newnode = new Node(data);
            //选用头插，免得去找尾又
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;
            ++_n;
            return { {newnode, this}, true };
        }

        Iterator Find(const K& key)
        {
            KeyOFT kot;
            Hash hs;
            size_t hashi = hs(key) % _tables.size();
            Node* cur = _tables[hashi];
            while (cur)
            {
                if (kot(cur->_data) == key)
                {
                    return Iterator(cur, nullptr);
                }
                cur = cur->_next;
            }
            return End();
        }

        bool Erase(const K& key)
        {
            KeyOFT kot;
            Hash hs;
            size_t hashi = hs(key) % _tables.size();
            Node* prev = nullptr;
            Node* cur = _tables[hashi];
            while (cur)
            {
                if (kot(cur->_data) == key)
                {
                    if (prev == nullptr)
                    {
                        _tables[hashi] = cur->_next;
                    }
                    else
                    {
                        prev->_next = cur->_next;
                    }
                    --_n;
                    delete cur;
                    return true;
                }
                prev = cur;
                cur = cur->_next;
            }
            return false;
        }

    private:
        //vector<list<pair<K, V>>> _tables;//这是一种实现哈希桶的方式，但是不太利于之后封装unordered_xxx实现迭代器
        vector<Node*> _tables;// 所以用原生一些的结构，指针数组
        size_t _n = 0;// 存了多少有效数据
    };
}
