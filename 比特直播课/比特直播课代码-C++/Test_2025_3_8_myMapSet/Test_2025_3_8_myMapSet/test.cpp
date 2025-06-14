#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//#include"RBTree.h"
//using namespace std;
//
//
//// 测试1：常规测试用例和双旋场景测试
//void TestRBTree1()
//{
//    RBTree<int, int> t;
//
//    // 常规测试用例
//    int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//
//    // 特殊的带有双旋场景的测试用例
//    //int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//
//    for (auto e : a)
//    {
//        t.Insert({ e, e });
//    }
//
//    t.InOrder();
//    cout << "Is balanced: " << t.IsBalanceTree() << endl;//C++ 的 cout 默认会将 bool 值打印为 1
//}
//
//// 测试2：大规模随机数据测试
//void TestRBTree2()
//{
//    const int N = 10000000;
//    vector<int> v;
//    v.reserve(N);
//    srand(time(0));
//
//    // 生成随机测试数据
//    for (size_t i = 0; i < N; i++)
//    {
//        v.push_back(rand() + i);
//    }
//
//    // 测试插入性能
//    size_t begin2 = clock();
//    RBTree<int, int> t;
//    for (auto e : v)
//    {
//        t.Insert(make_pair(e, e));
//    }
//    size_t end2 = clock();
//
//    cout << "Insert time: " << end2 - begin2 << " ms" << endl;
//    cout << "Is balanced: " << t.IsBalanceTree() << endl;
//
//}
//
//int main()
//{
//    cout << "----- Test 1 -----" << endl;
//    TestRBTree1();
//
//    cout << "\n----- Test 2 -----" << endl;
//    TestRBTree2();
//
//    return 0;
//}

// myset 和 mymap部分

#include<iostream>
#include"myset.h"
#include"mymap.h"

void Print(const LDW::set<int>& s)
{
	for (auto& e : s)
	{
		//e++;
		cout << e << " ";
	}
	cout << endl;
}


void testmyset()
{
	LDW::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(8);
	s.insert(8);
	s.insert(36);
	s.insert(-6);

	LDW::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto& e : s)
	{
		//e++;
		cout << e << " ";
	}
	cout << endl;

	Print(s);

	it = s.end();
	while (it != s.begin())
	{
		--it;
		cout << *it << " ";
	}
	cout << endl;

}

void testmymap()
{
	LDW::map<string, string> dict;
	dict.insert({"sort", "排序"});
	dict.insert({"hello", "你好"});
	dict.insert({"world", "世界"});
	dict.insert({"David", "大伟"});
	dict.insert({"best", "最牛"});

	LDW::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	dict["insert"];
	dict["left"] = "左边、剩余";
	for (auto& e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}
}


int main()
{
	testmyset();
	testmymap();

	return 0;
}