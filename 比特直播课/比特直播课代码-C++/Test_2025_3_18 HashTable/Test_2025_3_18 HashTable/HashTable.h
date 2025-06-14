#pragma once
#include<vector>
#include<utility>
using namespace std;

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

template<class K, class V>
class HashTable
{
public:
    HashTable()
        :_n(0)
        ,_tables(11)
    {}

    bool Insert(const pair<K, V>& kv)
    {
        //一般负载因子到0.7左右就需要扩容了，不能等满了再扩
        if (_n / _tables.size() >= 0.7)
        {

        }

        size_t hash0 = kv.first % _tables.size();//这里的size是11哦，先前指定了vector<HashData<K, V>> _tables默认给了个11
        size_t hashi = hash0;
        size_t i = 1;
        //线性探测
        while (_tables[hashi]._state == EXIST)
        {
            hashi = (hashi + i) % _tables.size();
            ++i;
        }
        _tables[hashi]._kv = kv;
        _tables[hashi]._state = EXIST;
        ++_n;

        return true;
    }

    HashData<K, V>* Find(const K& key)
    {

        size_t hash0 = kv.first % _tables.size();
        size_t hashi = hash0;
        size_t i = 1;
        //线性探测
        while (_tables[hashi]._state != EMPTY)
        {
            if (_tables[hashi]._kv.firstt == key)
            {
                return hashi;
            }

            hashi = (hashi + i) % _tables.size();
            ++i;
        }
        return nullptr;
    }


private:
    vector<HashData<K, V>> _tables;  // 存储哈希节点的数组
    size_t _n = 0;                  // 表中实际存储的数据个数
};
