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

    // 生成测试数据
    for (size_t i = 0; i < N; ++i) 
    {
        // v.push_back(rand());      // N较大时，重复值比较多
        v.push_back(rand() + i);    // 重复值相对少
        // v.push_back(i);           // 没有重复，有序
    }

    // 测试set插入性能
    size_t begin1 = clock();
    for (auto e : v) 
    {
        s.insert(e);
    }
    size_t end1 = clock();
    cout << "set insert: " << end1 - begin1 << " ms" << endl;

    // 测试unordered_set插入性能
    size_t begin2 = clock();
    us.reserve(N);  // 预分配空间提高性能
    for (auto e : v) 
    {
        us.insert(e);
    }
    size_t end2 = clock();
    cout << "unordered_set insert: " << end2 - begin2 << " ms" << endl;

    // 测试set查找性能
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

    // 测试unordered_set查找性能
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

    // 输出元素数量
    cout << "set size: " << s.size() << endl;
    cout << "unordered_set size: " << us.size() << endl << endl;

    // 测试set删除性能
    size_t begin5 = clock();
    for (auto e : v) 
    {
        s.erase(e);
    }
    size_t end5 = clock();
    cout << "set erase: " << end5 - begin5 << " ms" << endl;

    // 测试unordered_set删除性能
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