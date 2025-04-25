#pragma once

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int testset()
{
	//// set默认去重 + 升序排序(默认走的搜索树中序--左根右，所以出来是升序)
	////set<int> s;
 //   set<int, greater<int>> s;// 通过仿函数控制成降序
	//s.insert(5);
	//s.insert(2);
	//s.insert(7);
	//s.insert(5);

	////set<int>::iterator it = s.begin();
	//auto it = s.begin();
	//while (it != s.end())
	//{
 //       // error C3892: “it”: 不能给常量赋值
 //       // *it = 1; // 这里的迭代器key值不可修改，因为改了树结构就乱了
 //       cout << *it << " ";
 //       ++it;
 //   }
 //   cout << endl;

 //   // 插⼊⼀段initializer_list列表值，已经存在的值插⼊失败
 //   s.insert({ 2,8,3,9 });
 //   for (auto e : s)
 //   {
 //       cout << e << " ";
 //   }
 //   cout << endl;

 //   set<string> strset = { "Sort", "insert", "add" };// 大写字母的ASCII码更靠前，小一些，与小写的差值是32，所以改了s为S，排到前面去了
 //   for (auto& e : strset)
 //   {
 //       cout << e << " ";
 //   }
 //   cout << endl;

 //   // 关于set_Find和算法库Find的区别

 //   //主要在效率上，算法库的是暴力查找，从头++遍历到尾 O(N)
 //   auto it1 = find(s.begin(), s.end(), 3);

 //   //set的find用的搜索树搜索，效率是O(logN)
 //   auto it2 = s.find(3);

 //   //100万的数据量O(N)要找100万次，O(logN)只用大概20次
 //   //10亿的数据量O(N)要找10亿次，O(logN)只用大概30次


	//return 0;



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//set<int> s = { 4,2,7,2,8,5,9 };
	//for (auto e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//// 删除最⼩值
	//s.erase(s.begin());//搜索树里面最左（开始）的节点肯定是最小的
	//for (auto e : s)
	//{
	//	cout << e << " ";
	//}

 //   // 直接删除x
 //   int x;
 //   cin >> x;
 //   int num = s.erase(x);
 //   if (num == 0)// 这里删除失败为什么不用bool值要用0？因为要和multi树版本结合起来，multi里可能有多个这个值，这里就会返回值的计数，为0才能确认是不存在
 //   {
 //       cout << x << "不存在！" << endl;
 //   }
 //   for (auto e : s)
 //   {
 //       cout << e << " ";
 //   }
 //   cout << endl;

 //   // 直接查找在利⽤迭代器删除x
 //   cin >> x;
 //   auto pos = s.find(x);// 这里必须要保证find获取的是个有效的迭代器    s.find(x) 会在集合中查找 x 
 //   //如果找到了，find 返回一个指向该元素的 迭代器。如果没找到，返回的是 s.end()，即“超出集合范围”的迭代器。
 //   if (pos != s.end())// 所以这里要做判断，看找到的是啥迭代器
 //   {
 //       s.erase(pos);
 //   }
 //   else
 //   {
 //       cout << x << "不存在！" << endl;
 //   }
 //   for (auto e : s)
 //   {
 //       cout << e << " ";
 //   }
 //   cout << endl;

 //   // count()开发中通常也会被用来判断set中存不存在该元素，
 //   // 利⽤count间接实现快速查找，非multi树中set去重了，不是0就是1

 //   cin >> x;
 //   if (s.count(x))
 //   {
 //       cout << x << "在！" << endl;
 //   }
 //   else
 //   {
 //       cout << x << "不存在！" << endl;
 //   }
 //   // multi的count怎么实现呢？先调find()，我们先前说了find查找不是找从根开始递归找的第一个，找到了就返回
 //   // 而是整个递归完，找中序的第一个返回(最左边那个)，那么只要找到x值中序的第一个，剩下的计数只用往后++即可
 //   // 这也是find()设计成返回中序第一个的意义


 //   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//// 插入一些数据：10 20 30 40 50 60 70 80 90
	//std::set<int> myset({ 10, 20, 35, 40, 50, 65, 70, 80, 90 });

	//// 输出原始集合
	//for (auto e : myset)
	//	cout << e << " ";
	//cout << endl;

	//// 查找 [30, 60] 区间对应的迭代器范围 [itlow, itup) 
	//// 注意这里删除的区间是在迭代器上是左闭右开的，比如30-60是删除30 40 50 60
	//// 迭代器对应的是30 和 70
	//// 某些情况比如没有30 和 70，只有35 和 65   就会删除35 40 50
	//// 对应的迭代器是35 和 65， 注意迭代器关系
	//auto itlow = myset.lower_bound(30);  // 返回 >= 30 的第一个元素
	//auto itup = myset.upper_bound(60);  // 返回 > 60 的第一个元素

	//// 删除区间 [30, 60] 的所有元素
	//myset.erase(itlow, itup);

	//// 输出删除后的集合
	//for (auto e : myset)
	//	cout << e << " ";
	//cout << endl;


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//multiset部分
	// 与 set 不同的是，multiset 允许元素重复，且会自动排序
	multiset<int> s = { 4, 2, 7, 2, 4, 8, 4, 5, 4, 9 };

	// 输出 multiset 中的所有元素（会自动按升序排列）
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 查找元素 x，multiset 中 x 可能出现多次
	// find 返回的是中序遍历顺序中第一个等于 x 的位置
	int x;
	cin >> x;

	auto pos = s.find(x);
	while (pos != s.end() && *pos == x)
	{
		cout << *pos << " ";
		++pos;
	}
	cout << endl;

	// count 会返回 x 在 multiset 中的出现次数
	cout << s.count(x) << endl;

	// erase(x) 会删除 multiset 中所有等于 x 的元素
	s.erase(x);

	// 输出删除后的 multiset
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;


	return 0;

}