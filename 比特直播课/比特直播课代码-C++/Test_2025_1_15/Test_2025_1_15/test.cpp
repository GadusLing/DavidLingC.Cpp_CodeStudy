
#include "list.h"

void test_list1()
{
	list<int> lt1;// 模板类型构造，用int构造一个list
	lt1.push_back(1);// 支持尾插
	lt1.push_back(2);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

	list<int>::iterator it = lt1.begin();// 支持迭代器遍历
	while (it != lt1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (const auto& e : lt1)// 支持范围for
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>lt2 = { 10,2,30,5 };// 支持initializer list初始化 
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_list2()
{
	list<int> lt1;// 模板类型构造，用int构造一个list
	lt1.push_back(1);// 支持尾插
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

	lt1.assign(2, 1);// 把lt1变成10个1，多的删除，少的扩容插入，反正最后维持成10个1

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;


}

struct A
{
public:
	A(int a1 = 1, int a2 = 1)
		:_a1(a1)
		,_a2(a2)
	{}


	int _a1;
	int _a2;

};


void test_list3()
{
	list<int> lt1;
	lt1.push_back(1);// emplace_back 和push_back从功能上看来基本一致
	lt1.push_back(2);// 当list<int> lt1;实例化int之后，push_back只能插入实例化的T类型，即int,或者能隐式类型转换为int的类型

	lt1.emplace_back(3);// emplace_back这里也基本类似
	lt1.emplace_back(0.5);

	//但是在面对复杂类型，比如我们构造一个struct A
	//在创建A对象时，push_back有以下几种方式
	list<A> lt2;
	A aa1(2, 2);// 1.定义一个aa1对象
	lt2.push_back(aa1);// 然后传对象
	lt2.push_back(A(2, 2));// 2.匿名对象
	lt2.push_back({ 2, 2 });// 隐式类型转换initializer list转换为A对象

	//emplace_back 有以下几种用法
	lt2.emplace_back(aa1);// 1.传对象
	lt2.emplace_back(A(2, 2));// 2.匿名对象

	//lt2.emplace_back({ 2, 2 });emplace_back没办法这样用，因为push_back的参数是确定的，在这里是A，编译器可以推导
	//而emplace_back是模板，参数类型是不确定的，不能推导，所以initializer list的参数传过去没办法用，不知道怎么用

	lt2.emplace_back(2, 2);// 3.但是emplace_back可以这样用，因为是模板，可变参数，所以直接把参数传过去，
						   // 像push_back实际上是先用这边的比如{ 2, 2 }参数去构造了一个A，然后再把构造好的A走拷贝构造去给给链表里的push_back当参数
						   // 这里直接把两个(2, 2)传给了emplace_back可变参数，没有构造A再拷贝构造去传递，而是通过参数包最后直接在容器末尾原地构造了
	                       // 所以这种方式会更高效, 之后在C++11阶段还会再讲这一部分，现在可以先记住结论

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_list4()
{
	list<int>lt1 = { 10,6,30,5,6,8,9,6 };
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
	
	lt1.remove(100);// 如果我想remove删除一个没有的值会不会报错呢？ 不会的
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.remove(5);//
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.remove(6);// 但是remove相比于erase有个特点，会删除所有的6,erase是删除某一位置的一个或一个迭代器区间
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list5()
{
	list<int>lt1 = { 10,6,30,5,6,8,9,6 };
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	//sort(lt1.begin(), lt1.end());// 关于sort，算法库里面有个sort为啥list里面还要自己写一个sort
								 // 因为算法库里的在list这边用不了，算法库的sort用了迭代器的-x功能，而list迭代器支持++ --，但是不支持-x的
	                             // 很简单的原理，类数组的连续空间，其中的迭代器可以相互-，代价很低就能获取有效的空间
								 // 但链表并非连续物理空间，相互-也得不到有效的地址空间，只能让迭代器不停找next or prv去获取数据，效率极低
								 // 单向迭代器 ++ 
								 // 双向迭代器 ++/--
								 // 随机迭代器 ++/-- /+x /-x
								 // 类似forward_list中的迭代器就是单项迭代器 (forward_iterator)
								 // 像list map set 中的迭代器就是双项迭代器 (bidirectional_iterator)
								 // vector string 中的迭代器是随机迭代器 (random_access_iterator)
	// 算法对于迭代器是有类型要求的！！！！
	// 一般会在手册参数部分写清楚，比如InputIterator 就是要求传单项，至于为什么这里不是forward_iterator，这和早期C++设计迭代器时的一个父子关系体系有关，之后再研究
	// 反正只需要明确类似算法一般都会写清楚需要的是InputIterator / BidirectionalIterator 还是 RandomAccessIterator
	// 里面还存在一个父子关系，就是比如需要Input的场景，传Bid 和 Ran也是可以用的，Bid的场景 传 Ran也行，但是Ran的场景不可以用Inp 和 Bid； Ran > Bid > forward > Inp = Outp(抽象类)

	//算法库底层是快排自省排序，所以要用+ -随机访问，也正是因为不支持，所以list自己要搞个sort
	
	// < 升序
	lt1.sort();// 链表的sort是用的归并排序
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	// > 若要降序排列，这里会用到仿函数
	lt1.sort(greater<int>());// 整一个greater<int>()匿名对象, 之后会详细讲仿函数，不用着急，先看看怎么用
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	// list的sort实际开发中除非样本量比较小，不然能不用就不用，性能特别拉跨，release下比快排差了2-3倍的效率
	// 100万数据量的情况下，甚至不如把list的数据copy到vector，vector.sort完再assign回list，效率都比list自己的sort高
}

void test_list6()
{
	list<int>lt1 = { 10,6,6,30,5,6,8,8,9,6 };
	
	lt1.sort();// 因为unique是去重连续元素，所以经常和sort一起搭配使用，排完再去重

	lt1.unique();//unique会把挨在一起（连续的）的重复元素去重
	// 底层就是快慢指针去重，从1开始遇到不一样的把快的元素插到慢的那边。慢的再后移

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list7()
{
	list<int>lt1 = { 1,2,3,30,5,6,8,8,9,6 };

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	// 通过splice把自己的1移动到尾部
	lt1.splice(lt1.end(), lt1, lt1.begin());
	for (auto e : lt1)
	{
		cout << e << " ";
	}

}

void test_LDWlist1()
{
	LDW::list<int>lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);
	lt1.push_back(6);

	LDW::list<int>::iterator it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}

void Print(const LDW::list<int>& lt)
{	//Print 函数的参数是 const LDW::list<A>& lt，所以这里lt.begin();必须是const迭代器的版本
	LDW::list<int>::const_iterator it1 = lt.begin();
	while (it1 != lt.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

}

void RPrint(const LDW::list<int>& lt)
{
	LDW::list<int>::const_reverse_iterator it1 = lt.rbegin();
	while (it1 != lt.rend())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}

void test_LDWlist2()
{
	//LDW::list<A> lt1;
	//lt1.push_back({ 1,1 });
	//lt1.push_back({ 2,2 });
	//lt1.push_back({ 3,3 });
	//lt1.push_back({ 4,4 });


	//LDW::list<A>::iterator it1 = lt1.begin();
	//while (it1 != lt1.end())
	//{
	//	//cout << (*it1)._a1 << ":" << (*it1)._a2 << endl;
	//	cout << it1->_a1 << ":" << it1->_a2 << endl; // 支持(*it1)._a1 的 . 就要支持->，所以->也得重载一份
	//	//本来应该是两个箭头，编译器为了可读性省略了一个
	//	//it->->_a1
	//	//it.operator->()->_a1
	//	++it1;
	//}
	//cout << endl;

	LDW::list<int> lt2;
	lt2.push_back(1);
	lt2.push_back(2);
	lt2.push_back(3);
	lt2.push_back(4);
	lt2.push_back(5);
	lt2.push_back(6);

	Print(lt2);
	cout << typeid(vector<int>::iterator).name() << endl;
}

void test_LDWlist4()
{


	LDW::list<int> lt2;
	lt2.push_back(1);
	lt2.push_back(2);
	lt2.push_back(3);
	lt2.push_back(4);
	lt2.push_back(5);
	lt2.push_back(6);
	Print(lt2);

	LDW::list<int> lt3(lt2);

	lt2.clear();

	Print(lt2);

	Print(lt3);

	LDW::list<int> lt4 = { 10,20,30,40 };
	//lt4.push_back(10);
	//lt4.push_back(20);
	//lt4.push_back(30);
	//lt4.push_back(40);

	lt2 = lt4;
	Print(lt4);



}

void test_LDWlist_Ritertor1()
{
	LDW::list<int> lt2;
	lt2.push_back(1);
	lt2.push_back(2);
	lt2.push_back(3);
	lt2.push_back(4);
	lt2.push_back(5);
	lt2.push_back(6);
	RPrint(lt2);

	LDW::list<int> lt3(lt2);

	lt2.clear();

	RPrint(lt2);

	RPrint(lt3);

	LDW::list<int> lt4 = { 10,20,30,40 };

	lt2 = lt4;
	RPrint(lt4);
}

int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();
	//test_list5();
	//test_list6();
	//test_list7();
	//test_LDWlist1();
	//test_LDWlist2();
	//test_LDWlist4();
	test_LDWlist_Ritertor1();





	return 0;
}