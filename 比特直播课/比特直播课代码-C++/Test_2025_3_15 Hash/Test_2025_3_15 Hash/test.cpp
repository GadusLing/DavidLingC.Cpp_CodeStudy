#define _CRT_SECURE_NO_WARNINGS

#include <unordered_set>
#include <unordered_map>
#include <set>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int test_set2() 
{
    const size_t N = 1000000;
    unordered_set<int> us;
    set<int> s;
    vector<int> v;
    v.reserve(N);

    srand(time(0));

    // ���ɲ�������
    for (size_t i = 0; i < N; ++i) 
    {
        // v.push_back(rand());      // N�ϴ�ʱ���ظ�ֵ�Ƚ϶�
        v.push_back(rand() + i);    // �ظ�ֵ�����
        // v.push_back(i);           // û���ظ�������
    }

    // ����set��������
    size_t begin1 = clock();
    for (auto e : v) 
    {
        s.insert(e);
    }
    size_t end1 = clock();
    cout << "set insert: " << end1 - begin1 << " ms" << endl;

    // ����unordered_set��������
    size_t begin2 = clock();
    us.reserve(N);  // Ԥ����ռ��������
    for (auto e : v) 
    {
        us.insert(e);
    }
    size_t end2 = clock();
    cout << "unordered_set insert: " << end2 - begin2 << " ms" << endl;

    // ����set��������
    int m1 = 0;
    size_t begin3 = clock();
    for (auto e : v) 
    {
        auto ret = s.find(e);
        if (ret != s.end()) 
        {
            ++m1;
        }
    }
    size_t end3 = clock();
    cout << "set find: " << end3 - begin3 << " ms -> " << m1 << " matches" << endl;

    // ����unordered_set��������
    int m2 = 0;
    size_t begin4 = clock();
    for (auto e : v) 
    {
        auto ret = us.find(e);
        if (ret != us.end()) 
        {
            ++m2;
        }
    }
    size_t end4 = clock();
    cout << "unordered_set find: " << end4 - begin4 << " ms -> " << m2 << " matches" << endl;

    // ���Ԫ������
    cout << "set size: " << s.size() << endl;
    cout << "unordered_set size: " << us.size() << endl << endl;

    // ����setɾ������
    size_t begin5 = clock();
    for (auto e : v) 
    {
        s.erase(e);
    }
    size_t end5 = clock();
    cout << "set erase: " << end5 - begin5 << " ms" << endl;

    // ����unordered_setɾ������
    size_t begin6 = clock();
    for (auto e : v) 
    {
        us.erase(e);
    }
    size_t end6 = clock();
    cout << "unordered_set erase: " << end6 - begin6 << " ms" << endl << endl;

    return 0;
}

int main() 
{
    test_set2();
    return 0;
}