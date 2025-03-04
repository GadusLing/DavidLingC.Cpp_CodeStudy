#define _CRT_SECURE_NO_WARNINGS


#include"vector.h"


//int main()
//{
//	vector<int> v1 = { 1,-2,30,4,5 };
//	list<int> lt1 = { 1,2,3,4,5 };
//
//	vector<string> v2;
//	vector<vector<int>> v3;
//
//	string name1 = "张三";
//	v2.push_back(name1);//有名对象
//
//	v2.push_back(string("李四"));//匿名对象
//
//	v2.push_back("王五");//隐式类型转换
//	
//	for (const auto& e : v2)// 范围for这样引用写更健壮，避免传值要深拷贝代价太大
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//int x;
//	//cin >> x;
//	////vector<int>::iterator it1 = find(v1.begin(), v1.end(), x);
//	//auto it1 = find(v1.begin(), v1.end(), x);
//	//if (it1 != v1.end())
//	//{
//	//	cout << x << "找到了" << endl;
//	//}
//
//	//cin >> x;
//	////vector<int>::iterator it1 = find(v1.begin(), v1.end(), x);
//	//auto it2 = find(lt1.begin(), lt1.end(), x);
//	//if (it2 != lt1.end())
//	//{
//	//	cout << x << "找到了" << endl;
//	//}
//
//	sort(v1.begin(), v1.end());//sort默认升序,底层是快排,严格来说是自省排序
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//降序呢?涉及到仿函数,具体之后会讲,这里先拿来用
//	// 默认less
//	//greater <int> gt;
//	//sort(v1.begin(), v1.end(), gt);
//	sort(v1.begin(), v1.end(), greater<int>());
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	//迭代器也分类型的,单向双向随机的,支持++,支持++--,支持+N - N
//	//sort(lt1.begin(), lt1.end());
//	//像list的迭代器就是不支持sort的
//
//
//	return 0;
//}



void func(const LDW::vector<int>& v)// 很多时候会有这种情况，传参过来用了const引用之后
{
	//for (size_t i = 0; i < v.size(); ++i)// 范围for遍历编译会不通过
	//{
	//	//v[i]++; //不能修改哦，因为是返回的是const别名
	//	cout << v[i] << " ";//因为此处的[]接收参数是普通对象，const对象无法传给普通对象，所以需要额外增加一份const [] 见vector.h
	//}
	//cout << endl;

	//////int* const it = v.begin();
	////const LDW::vector<int>::iterator it = v.begin();// const在左边是修饰迭代器本身，我们要const迭代器的目的并不是让迭代器本身不能修改，而是要内容不能修改，
	//// //所以const迭代器并非是在普通迭代器左边加上const就完事了，而是要额外实现重载一份，命名上以const_iterator来区分
	////while (it != v.end())
	////{
	////	cout << *it << " ";
	////	++it;
	////}


	//LDW::vector<int>::const_iterator it = v.begin();// 这样就完成了，不是在左边加const
	//while (it != v.end())
	//{
	//	//*int += 5;
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;


	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

}



//int main()
//{
//	LDW::vector<int> v1;
//	LDW::vector<double> v2;
//
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//
//	func(v1);
//
//
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	//v1[i]
//	//v1.operator[](i);
//
//	//int a[10];
//	//a[i];  *(a+i)
//
//	//std::vector<int> v;
//	//cout << typeid(std::vector<int>::iterator).name() << endl;
//	//cout << typeid(std::vector<int>::const_iterator).name() << endl;
//	//cout << typeid(std::vector<int>::reverse_iterator).name() << endl;
//	//cout << typeid(std::vector<int>::const_reverse_iterator).name() << endl;
//
//
//	return 0;
//}//2025,明年再见




//int main()
//{
//	LDW::vector<int> v1;
//
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	//v1.push_back(5);// 有时候会遇到一些迭代器失效的问题，比如这里注释掉5，引发迭代器失效，那么基本可以断定和扩容有关系
//
//	int i = 0;
//	cin >> i;
//	auto it = v1.begin() + i;
//	// insert 之后，默认的迭代器都失效了，不要使用
//	v1.insert(it, 10);// 像这种情况下，这个it也是失效的迭代器
//
//
//
//	func(v1);
//	v1.insert(v1.begin(), 10);
//
//	func(v1);
//	v1.erase(v1.begin() + 3);
//	func(v1);
//
//
//
//
//
//
//	return 0;
//}

//int main()
//{
//	LDW::vector<int> v1;
//
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//
//	//例子：现在要求删除所有的偶数
//	auto it = v1.begin();
//	while (it != v1.end())
//	{
//		if (*it % 2 == 0)
//		{
//			v1.erase(it); // 要使用 erase 返回的迭代器来更新it，不然只有v1.erase(it)，eease后it会被判定为迭代器失效
//		}
//		else // 只有在不删除元素时才递增迭代器
//		{
//			++it; 
//		}
//	}
//
//	func(v1);
//
//	return 0;
//}

//int main()
//{
//	LDW::vector<int> v1;
//
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);
//	func(v1);
//
//
//
//	v1.resize(7, 10);
//	func(v1);
//
//	v1.resize(17, 20);
//	func(v1);
//
//	v1.resize(5);
//	func(v1);
//
//	LDW::vector<int> v2;
//	v2.resize(100, 1);
//	func(v2);
//
//
//
//	return 0;
//}


//int main()
//{
//	LDW::vector<int> v1;
//
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);
//
//	//LDW::vector<int> v2(v1);
//	LDW::vector<int> v2 = v1;// 这个也是拷贝构造哈，只要用一个对象去初始化另外一个对象，都叫做拷贝构造
//	func(v2);
//
//	LDW::vector<int> v3;
//	v3.resize(100, 1);
//	v1 = v3;
//	func(v1);
//
//
//	return 0;
//}

//int main()
//{
//	LDW::vector<string> v1;
//
//	v1.push_back("111111111111111111111");
//	v1.push_back("111111111111111111111");
//	v1.push_back("111111111111111111111");
//	v1.push_back("111111111111111111111");
//	v1.push_back("111111111111111111111");// 为啥第5行就茸了呢？应该是扩容的问题
//
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


//int main()
//{
//	
//	LDW::vector<int> v1 = { 1,2,3,4,5,6 };// C++11 之后的初始化方式————initializer_list
//	// 上面其实是单参数构造 通过= 的隐式类型转换
//	//LDW::vector<int> v2({ 1,2,3,4,5,6 });
//    // 下面的是传initializer_list的参
//
//
//
//	//auto il = { 1,2,3,4,5,6 };
//	////原理上和
//	//int a[] = { 1,2,3,4,5,6 };// 很像
//	//cout << typeid(il).name() << endl;
//	//cout << il.begin() << endl;// 这里可以看出差别，initializer_list实际是在栈上开的空间
//	//cout << a << endl;// 和这些栈上开的数组地址接近
//	//const char* str = "hello world";// 而这种const常量位于常量区，地址相隔很远
//	//cout << (void*)str << endl;
//
//
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//
//	LDW::vector<int> v1 = { 1,2,3,4,5,6 };
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	LDW::vector<int> v2(v1.begin() + 1, v1.end() - 1);
//	for (const auto& e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	string s1("hello world");
//	LDW::vector<int> v3(s1.begin(), s1.end());
//
//	for (const auto& e : v3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	int a[] = { 10,2,30,4,55,6 };
//	LDW::vector<int> v4(a, a + 6);// 迭代器区间是可以传数组这样的原生指针的哦，因为迭代器模拟的就是指针的行为，所以原生指针就更可以当成迭代器了
//	for (const auto& e : v4)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	
//	sort(v4.begin(), v4.end()); // sort能对容器的迭代器区间排序
//	for (const auto& e : v4)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	sort(a, a + 6);
//	for (const auto& e : a) // sort也能对指针数组排序
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}

int main()
{

	LDW::vector<double> v1(10, 0.1);
	for (const auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	LDW::vector<int> v2(10, 1);// C2100错误，类型匹配不对，匹配到vector(InputIterator first, InputIterator last)上了，因为他们更合适
	for (const auto& e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	LDW::vector<size_t> v3(10ULL, 1ULL);// ULL表示size_t
	for (const auto& e : v3)
	{
		cout << e << " ";
	}
	cout << endl;



	return 0;
}


