#pragma once
#include<vector>
#include<utility>
using namespace std;

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
        //һ�㸺�����ӵ�0.7���Ҿ���Ҫ�����ˣ����ܵ���������
        if (_n / _tables.size() >= 0.7)
        {

        }

        size_t hash0 = kv.first % _tables.size();//�����size��11Ŷ����ǰָ����vector<HashData<K, V>> _tablesĬ�ϸ��˸�11
        size_t hashi = hash0;
        size_t i = 1;
        //����̽��
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
        //����̽��
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
    vector<HashData<K, V>> _tables;  // �洢��ϣ�ڵ������
    size_t _n = 0;                  // ����ʵ�ʴ洢�����ݸ���
};
