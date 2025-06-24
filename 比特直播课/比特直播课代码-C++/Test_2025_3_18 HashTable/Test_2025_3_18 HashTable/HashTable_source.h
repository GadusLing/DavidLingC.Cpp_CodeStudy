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


namespace open_address
{
    enum State
    {
        EXIST,   // 表示该位置有数据
        EMPTY,   // 表示该位置为空
        DELETE   // 表示该位置数据已被删除
    };

    template<class K, class V>
    struct HashData
    {
        pair<K, V> _kv;       // 存储键值对
        State _state = EMPTY;  // 初始状态为EMPTY //线性探测情况下，映射会有自然的错位，如果删除某些位置的数据，再探测，以空为条件结束，就会产生明明在表内却探测不到的情况
        //所以需要添加一个状态，当状态为“被删除”时，依然会向后找，只有同时“空”并且“K值==对应位置”才确认了，哦，之前确实没有这个数，见3_15 map和set的封装 02:57:00 部分
    };

    template<class K, class V, class Hash = HashFunc<K>>
    class HashTable
    {
    public:
        HashTable(size_t size = NextPrime(0))
            :_n(0)
            , _tables(size)
        {}
        ~HashTable()
        {

        }

        bool Insert(const pair<K, V>& kv)
        {
            //一般负载因子到0.7左右就需要扩容了，不能等满了再扩
            if ((double)_n / (double)_tables.size() >= 0.7)
            {
                //vector<HashData<K, V>> _newtables(_tables.size() * 2);
                //for (size_t i = 0; i < _tables.size(); i++)
                //{
                //    if (_tables[i].state == EXIST)
                //    {
                //        //...手动遍历法
                //    }
                //}

                //现代写法 复用，我不自己写，你写了，我换过来
                //HashTable<K, V> newHT(_tables.size() * 2);
                HashTable<K, V, Hash> newHT(NextPrime(_tables.size() + 1));
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    if (_tables[i]._state == EXIST)
                    {
                        newHT.Insert(_tables[i]._kv);
                    }
                }
                _tables.swap(newHT._tables);
            }
            Hash hs;//用仿函数处理string or double类型无法比较的问题
            size_t hash0 = hs(kv.first) % _tables.size();//这里的size是11哦，先前指定了vector<HashData<K, V>> _tables默认给了个11
            size_t hashi = hash0;
            size_t i = 1;
            //线性探测
            while (_tables[hashi]._state == EXIST)
            {
                hashi = (hashi + i) % _tables.size();
                ++i;
            }
            _tables[hashi]._kv = kv ;
            _tables[hashi]._state = EXIST;
            ++_n;

            return true;
        }

        HashData<K, V>* Find(const K& key)
        {
            Hash hs;
            size_t hash0 = hs(key) % _tables.size();
            size_t hashi = hash0;
            size_t i = 1;
            //线性探测
            while (_tables[hashi]._state != EMPTY)
            {
                if (_tables[hashi]._kv.first == key && _tables[hashi]._state != DELETE)
                {
                    return &_tables[hashi];
                }

                hashi = (hashi + i) % _tables.size();
                ++i;
            }
            return nullptr;
        }

        bool Erase(const K& key)
        {
            HashData<K, V>* ret = Find(key);
            if (ret)
            {
                ret->_state = DELETE;
                return true;
            }
            else return false;
        }

    private:
        vector<HashData<K, V>> _tables;  // 存储哈希节点的数组
        size_t _n = 0;                  // 表中实际存储的数据个数
    };
}

namespace hash_bucket
{
    template<class K, class V>
    struct HashNode
    {
        pair<K, V> _kv;
        HashNode<K, V>* _next;

        HashNode(const pair<K, V>& kv)
            :_kv(kv)
            ,_next(nullptr)
        {
        }
    };

    template<class K, class V, class Hash = HashFunc<K>>
    class HashTable
    {
        typedef HashNode<K, V> Node;
    public:
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

        bool Insert(const pair<K, V>& kv)
        {
            if (Find(kv.first)) return false;

            //扩容            
            Hash hs;
            //负载因子到1，再扩容
            if (_n == _tables.size())
            {
               /* HashTable<K, V> newHT(NextPrime(_tables.size() + 1));
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    while (cur)
                    {
                        newHT.Insert(cur->_kv);
                        cur = cur->_next;
                    }
                }
                _tables.swap(newHT._tables);*/
                //但是和直接定址法不同的是，这里如果采用传统的插入方式开销会非常大，因为在之前的插入方式中
                //新开空间后把数据直接复制到新区域，直接浅拷贝即可，而哈希桶中是一个个的链表，每个链表自己内部也是有空间的
                //如果扩容 拷贝调insert，那么也就意味着是创建新节点空间、交换+释放原节点空间，
                //假设原来有10000个节点，扩容之后变20000还得交换，还得释放原节点，开销一下就上去了
                //所以最好的解决方式就是直接把原表的节点拿到扩容后的新表上————改变指针指向
                vector<Node*> newtables(NextPrime(_tables.size() + 1), nullptr);
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    while (cur)
                    {
                        //把旧表的节点插入到新表
                        Node* next = cur->_next;
                        size_t hashi = hs(cur->_kv.first) % newtables.size();
                        cur->_next = newtables[hashi];
                        newtables[hashi] = cur;//换到新表原始的顺序会倒转，但是无所谓，不影响功能，甚至不只是倒转，连桶内的数量都变了
                        cur = next;
                    }
                    _tables[i] = nullptr;
                }
                _tables.swap(newtables);
            }
            size_t hashi = hs(kv.first) % _tables.size();
            Node* newnode = new Node(kv);
            //选用头插，免得去找尾又
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;
            ++_n;
            return true;
        }

        Node* Find(const K& key)
        {
            Hash hs;
            size_t hashi = hs(key) % _tables.size();
            Node* cur = _tables[hashi];
            while (cur)
            {
                if (cur->_kv.first == key)
                {
                    return cur;
                }
                cur = cur->_next;
            }
            return nullptr;
        }

        bool Erase(const K& key)
        {
            Hash hs;
            size_t hashi = hs(key) % _tables.size();
            Node* prev = nullptr;
            Node* cur = _tables[hashi];
            while (cur)
            {
                if (cur->_kv.first == key)
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
