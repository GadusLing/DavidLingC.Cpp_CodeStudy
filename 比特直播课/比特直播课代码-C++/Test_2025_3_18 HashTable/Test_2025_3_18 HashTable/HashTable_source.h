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


namespace open_address
{
    enum State
    {
        EXIST,   // ��ʾ��λ��������
        EMPTY,   // ��ʾ��λ��Ϊ��
        DELETE   // ��ʾ��λ�������ѱ�ɾ��
    };

    template<class K, class V>
    struct HashData
    {
        pair<K, V> _kv;       // �洢��ֵ��
        State _state = EMPTY;  // ��ʼ״̬ΪEMPTY //����̽������£�ӳ�������Ȼ�Ĵ�λ�����ɾ��ĳЩλ�õ����ݣ���̽�⣬�Կ�Ϊ�����������ͻ���������ڱ���ȴ̽�ⲻ�������
        //������Ҫ���һ��״̬����״̬Ϊ����ɾ����ʱ����Ȼ������ң�ֻ��ͬʱ���ա����ҡ�Kֵ==��Ӧλ�á���ȷ���ˣ�Ŷ��֮ǰȷʵû�����������3_15 map��set�ķ�װ 02:57:00 ����
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
            //һ�㸺�����ӵ�0.7���Ҿ���Ҫ�����ˣ����ܵ���������
            if ((double)_n / (double)_tables.size() >= 0.7)
            {
                //vector<HashData<K, V>> _newtables(_tables.size() * 2);
                //for (size_t i = 0; i < _tables.size(); i++)
                //{
                //    if (_tables[i].state == EXIST)
                //    {
                //        //...�ֶ�������
                //    }
                //}

                //�ִ�д�� ���ã��Ҳ��Լ�д����д�ˣ��һ�����
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
            Hash hs;//�÷º�������string or double�����޷��Ƚϵ�����
            size_t hash0 = hs(kv.first) % _tables.size();//�����size��11Ŷ����ǰָ����vector<HashData<K, V>> _tablesĬ�ϸ��˸�11
            size_t hashi = hash0;
            size_t i = 1;
            //����̽��
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
            //����̽��
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
        vector<HashData<K, V>> _tables;  // �洢��ϣ�ڵ������
        size_t _n = 0;                  // ����ʵ�ʴ洢�����ݸ���
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

            //����            
            Hash hs;
            //�������ӵ�1��������
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
                //���Ǻ�ֱ�Ӷ�ַ����ͬ���ǣ�����������ô�ͳ�Ĳ��뷽ʽ������ǳ�����Ϊ��֮ǰ�Ĳ��뷽ʽ��
                //�¿��ռ�������ֱ�Ӹ��Ƶ�������ֱ��ǳ�������ɣ�����ϣͰ����һ����������ÿ�������Լ��ڲ�Ҳ���пռ��
                //������� ������insert����ôҲ����ζ���Ǵ����½ڵ�ռ䡢����+�ͷ�ԭ�ڵ�ռ䣬
                //����ԭ����10000���ڵ㣬����֮���20000���ý����������ͷ�ԭ�ڵ㣬����һ�¾���ȥ��
                //������õĽ����ʽ����ֱ�Ӱ�ԭ��Ľڵ��õ����ݺ���±��ϡ��������ı�ָ��ָ��
                vector<Node*> newtables(NextPrime(_tables.size() + 1), nullptr);
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    while (cur)
                    {
                        //�Ѿɱ�Ľڵ���뵽�±�
                        Node* next = cur->_next;
                        size_t hashi = hs(cur->_kv.first) % newtables.size();
                        cur->_next = newtables[hashi];
                        newtables[hashi] = cur;//�����±�ԭʼ��˳��ᵹת����������ν����Ӱ�칦�ܣ�������ֻ�ǵ�ת����Ͱ�ڵ�����������
                        cur = next;
                    }
                    _tables[i] = nullptr;
                }
                _tables.swap(newtables);
            }
            size_t hashi = hs(kv.first) % _tables.size();
            Node* newnode = new Node(kv);
            //ѡ��ͷ�壬���ȥ��β��
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
        //vector<list<pair<K, V>>> _tables;//����һ��ʵ�ֹ�ϣͰ�ķ�ʽ�����ǲ�̫����֮���װunordered_xxxʵ�ֵ�����
        vector<Node*> _tables;// ������ԭ��һЩ�Ľṹ��ָ������
        size_t _n = 0;// ���˶�����Ч����
    };
}
