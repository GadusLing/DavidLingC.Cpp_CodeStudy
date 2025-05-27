
#include "AVLTree.h"

// 测试1：常规测试用例和双旋场景测试
void TestAVLTree1()
{
    AVLTree<int, int> t;

    // 常规测试用例
     int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

    // 特殊的带有双旋场景的测试用例
    //int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

    for (auto e : a)
    {
        t.Insert({ e, e });
    }

    t.InOrder();
    cout << "Is balanced: " << t.IsBalanceTree() << endl;
}

// 测试2：大规模随机数据测试
void TestAVLTree2()
{
    const int N = 100000;
    vector<int> v;
    v.reserve(N);
    srand(time(0));

    // 生成随机测试数据
    for (size_t i = 0; i < N; i++)
    {
        v.push_back(rand() + i);
    }

    // 测试插入性能
    size_t begin2 = clock();
    AVLTree<int, int> t;
    for (auto e : v)
    {
        t.Insert(make_pair(e, e));
    }
    size_t end2 = clock();

    cout << "Insert time: " << end2 - begin2 << " ms" << endl;
    cout << "Is balanced: " << t.IsBalanceTree() << endl;
    cout << "Height: " << t.Height() << endl;
    cout << "Size: " << t.Size() << endl;

    // 测试查找性能
    size_t begin1 = clock();
    // 查找确定存在的值
    // for (auto e : v) { t.Find(e); }

    // 查找随机值
    for (size_t i = 0; i < N; i++)
    {
        t.Find((rand() + i));
    }
    size_t end1 = clock();

    cout << "Find time: " << end1 - begin1 << " ms" << endl;
}

int main()
{
    cout << "----- Test 1 -----" << endl;
    TestAVLTree1();

    cout << "\n----- Test 2 -----" << endl;
    TestAVLTree2();

    return 0;
}