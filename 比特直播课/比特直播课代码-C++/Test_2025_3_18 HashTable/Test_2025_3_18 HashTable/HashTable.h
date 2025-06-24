#pragma once
#include<vector>
#include<utility>
#include <algorithm>

using namespace std;

// ��ϣ�������õ�������
// ��Щ�ӽ�2���ݴη����������Լ��ٹ�ϣ��ͻ
static const int kNumPrimes = 28;  // �������С
static const unsigned long kPrimeList[kNumPrimes] = 
{
    // ��53��ʼ��ÿ��������ԼΪǰһ����2��
    53,         97,         193,        389,        769,
    1543,       3079,       6151,       12289,      24593,
    49157,      98317,      196613,     393241,     786433,
    1572869,    3145739,    6291469,    12582917,   25165843,
    50331653,   100663319,  201326611,  402653189,  805306457,
    1610612741, 3221225473, 4294967291  // ���һ��������2^32-5
};

 /**
 * ��ȡ��С��n����С����
 * @param n ������ֵ
 * @return �������С�n����С���������n�������ֵ�򷵻����һ������
 */
inline unsigned long NextPrime(unsigned long n) 
{
    const unsigned long* first = kPrimeList;          // ��������ʼλ��
    const unsigned long* last = kPrimeList + kNumPrimes;  // ����λ��(β��ָ��)
    const unsigned long* pos = std::lower_bound(first, last, n);  // ���ֲ���

    // ���n�������������󣬷������һ�����������򷵻��ҵ���λ�õ�ֵ
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

    //���HTIterator��HashTable�໥������ϵ����ǰ������
    template<class K, class T, class KeyOFT, class Hash >
    class HashTable;

    template<class K, class T, class Ref, class Ptr, class KeyOFT, class Hash>
    struct HTIterator
    {
        typedef HashNode<T> Node;
        typedef HashTable<K, T, KeyOFT, Hash> HT;//�������� : ȱ�١�; ��(�ڡ� < ����ǰ��) ʵ������ΪHTIterator��HashTable���������Ĺ�ϵ������ʱֻ�����ϲ��ң�����Ϊ�໥����������Ҫ��ǰ���������
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
                //��ǰͰ����
                _node = _node->_next;
            }
            else
            {
                // ����һ��Ͱ�ĵ�һ���ڵ�
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
                // ������Ͱ�������ˣ�nullptrȥ��end()
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
        template<class K, class T, class Ref, class Ptr, class KeyOFT, class Hash>// ģ������Ԫ�ǵ�Ҫ����������������
        friend struct HTIterator;

        typedef HashNode<T> Node;
    public:

        typedef HTIterator<K, T, T&, T*, KeyOFT, Hash> Iterator;
        typedef HTIterator<K, T, const T&, const T*, KeyOFT, Hash> ConstIterator;

        Iterator Begin()
        {
            // �ҵ�һ����Ϊ�յ�Ͱ����ĵ�һ���ڵ�
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
            if (it != End()) return { it, false };//����false��ʾԪ���Ѵ���;
            
            //����            
            Hash hs;
            //�������ӵ�1��������
            if (_n == _tables.size())
            {
                vector<Node*> newtables(NextPrime(_tables.size() + 1), nullptr);
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    while (cur)
                    {
                        //�Ѿɱ�Ľڵ���뵽�±�
                        Node* next = cur->_next;
                        size_t hashi = hs(kot(cur->_data)) % newtables.size();
                        cur->_next = newtables[hashi];
                        newtables[hashi] = cur;//�����±�ԭʼ��˳��ᵹת����������ν����Ӱ�칦�ܣ�������ֻ�ǵ�ת����Ͱ�ڵ�����������
                        cur = next;
                    }
                    _tables[i] = nullptr;
                }
                _tables.swap(newtables);
            }
            size_t hashi = hs(kot(data)) % _tables.size();
            Node* newnode = new Node(data);
            //ѡ��ͷ�壬���ȥ��β��
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
        //vector<list<pair<K, V>>> _tables;//����һ��ʵ�ֹ�ϣͰ�ķ�ʽ�����ǲ�̫����֮���װunordered_xxxʵ�ֵ�����
        vector<Node*> _tables;// ������ԭ��һЩ�Ľṹ��ָ������
        size_t _n = 0;// ���˶�����Ч����
    };
}
