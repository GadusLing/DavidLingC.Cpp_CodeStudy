//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>	
//#include <array>	// C++11
//#include <vector>
//#include "Date.h"
//using namespace std;
//
////#define N 10
//
//template <class T, size_t N = 10>
//// 到C++11，非模板参数的主要都是供整形使用，用来定义数组大小和一些整形数据
//class mystack
//{
//public:
//	// ...
//private:
//	T _a[N];
//	int _top;
//};
//
//
////int main()
////{
////	mystack<int, 10> s1;        // 10
////	mystack<int> s2;        // 10
////	mystack<double, 200> s3;     // 200
////
////
////
////	return 0;
////}
//
////// 接下来讲讲array 静态数组，实际使用中STL的array并不好用
////int main()
////{
////	array<int, 10> a1;
////	array<int, 100> a2;
////	//两种数组对比，两者之间最大的区别就是array检查数组越界非常敏感，而C语言风格的数组的越界检查是一种抽查，不敏感
////	int arr1[10];
////	int arr2[100];
////
////	//是怎实现的呢？C语言数组检查实际上是在数组尾部设置一个标识，当访问到标识时，就会报错，
////	//但设置的标识根据不同操作系统和编译器不同，可能会有所不同，而且过度越界也不会检查出来
////	//比如只设置了两个标识，但是访问了十个，就不会报错
////	//但array则会通过参数部分的模板参数，比如上面的10，来检查数组越界，只要[]内访问的下标超过了模板参数的值，就会报错
////
////	//但是除了这个优势之外，array并不好用，作为一个静态数组，它会占用栈空间
////	//而栈空间和堆空间不同，栈空间并不大，Window下，栈的大小是2MB，Linux下，默认栈空间大小为8MB
////	//所以如果数组过大，就会导致栈溢出
////	//而且array所谓的检测越界，vector也能做到
////	//vector<int> v1(10, 0);  还能更方便的初始化
////
////	return 0;
////}
//
//
//// 接下来讲讲函数模板的特化
//// 函数模板的特化，就是对函数模板的一个特殊化处理
//template <class T>
//bool Less(const T& left,const T& right)
//{
//	return left < right;
//}
//
////特化(不能单独存在，要在原模板存在的基础上实现)
//template<>
////bool Less<Date*>(Date*& left, Date*& right)// 这个const的的位置要搞清楚
////bool Less<Date*>(const Date*& left, const Date*& right)// 这个const不是修饰left的，而是修饰*left，和上面对不上
//// const在*（指针）的左边，修饰的都是*指针指向的内容
//
//
////*右边的const修饰指针本身
//bool Less<Date*>(Date* const & left, Date* const & right)//所以要这样写，修饰left
//{
//	return *left < *right;// 这样比的就不是指针了，而是指针指向的对象，解引用之后的日期
//}
////所以不推荐搞 函数模板的特化，写法很复杂，还不如用下面那种
//
//
//////那么新增一个思路，我能不能直接写个指针做参数类型的函数呢？反正都重载，可以和模板共存
////bool Less(Date* left, Date* right)
////{
////	return *left < *right;// 看起来也不错哦，而且符合规则
////}
//////所以两个方式都能使用，但是特化有它自己的使用场景
//
//
////int main()
////{
////	cout << Less(1, 2) << endl;//可以比较，结果正确
////
////	Date d1(2025, 7, 7);
////	Date d2(2025, 7, 8);
////	cout << Less(d1, d2) << endl;
////
////	cout << Less(new Date(2025, 3, 7), new Date(2025, 3, 8)) << endl;// 这里结果会不断变化，因为比的是new返回的指针，错误
////	// 所以我们要在原模板的基础上，对指针类型进行特化
////
////
////	return 0;
////}
//
//
////但是类模板的特化是推荐使用的
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//// 正常的类模板想特殊处理某个数据类型，是不能通过写一个普通类，普通类内部改对应的数据类型来实现的
//// 因为普通类根本就不存在传模板参数的概念，没有传参自动匹配类型的说法
//// 类模板是需要显式实例化的，而函数模板为什么可以通过写一个普通函数重载来实现特殊匹配和处理?
//// 因为函数是不需要显式实例化的，是通过参数类型匹配的
////所以，类模板如果想要特殊处理就需要写对应的特化类
//
//
//template<>
//class Data<int*, int*>
//{
//public:
//	Data() { cout << "Data<int*, int*>" << endl; }
////private:
////	int* _d1;
////	int* _d2;
//};
//
////特化还分为全特化、偏特化，上面这种属于全特化
//
//// 这种就是偏特化，有些地方也叫半特化
//template<class T1>
//class Data<T1, int>// 第二个参数用int的，会优先匹配这个
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//private:
//		T1 _d1;
//		int _d2;
//};
//
//template<>
//class Data<int, int>
//{
//public:
//	Data() { cout << "Data<int, int>" << endl; }
//};// 特化之间也有参数匹配的优先级，比如两个参数都是int，就优先走这个了
//
//// 偏特化不仅仅指特化部分参数，还包括对参数更进一步限制的版本
//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////两个参数偏特化为引用类型
//template <typename T1, typename T2>
//class Data <T1&, T2&>// 引用也行
//{
//public:
//	Data()
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//};
//
//template <typename T1, typename T2>
//class Data <T1&, T2*>// 一个引用一个指针也行
//{
//public:
//	Data()
//	{
//		cout << "Data<T1&, T2*>" << endl;
//	}
//};
//
//
//int main()
//{
//	Data<int, int> d1;
//	Data<int*, int*> d2;
//	Data<int, char> d3;
//	Data<char, int> d4;
//	Data<char*, char*> d5;
//	Data<char&, int&> d6;
//	Data<char&, int*> d7;
//
//
//	return 0;
//}


// 接下来讲讲模板的分离编译
// 分离编译，就是将声明和实现分开，声明放在.h文件中，实现放在.cpp文件中
// 现代工程中一般都是这样做的，最主要的原因是为了方便维护和管理
// 但是模板的分离编译，有一个问题，就是模板的实现和声明必须在同一个文件中，否则会报错
// 为啥呢？要搞清楚这个问题，首先要知道编译器的编译过程
// 
// 编译器的编译过程分为四个步骤：预处理、编译、汇编、链接
// 1、预处理 //展开头文件、宏替换、条件编译、去掉注释   Func.i  Test.i   
// 2、编译 //检查语法，生成汇编代码    Func.s Test.s
// 3、汇编 //把汇编代码转成二进制机器码    Func.o Test.o
// 4. 链接 //合并成可执行程序，链接函数地址等
// 
// 在编译阶段，调用某个函数就是call指令，call函数地址，但是此时是一个类似call func(?)这样的一个过程，地址是未知的
// 此时只有声明没有定义的话，会在链接阶段去寻找定义部分的函数地址，
// 因为那么多文件你要挨个去找，编译会非常慢，为了编译速度，所以此时函数地址是 ？未知，只是记录了一下
// 然后到了链接阶段，链接器会去找函数的定义，找到了那声明和定义就链接成功，
// 在汇编阶段，目标文件会生产一个全局的符号表，链接成功函数的地址就会在符号表里记录下来，func: 0x123456 类似的
// 如果最后都找不到就链接失败
// 
// 
// 而模板为什么不能分离？普通函数会被编译成指令，因为他们的声明中信息清晰，也不需要推测类型，只需要最后能匹配到函数地址就行
// 而模板函数需要显示实例化，光凭.h里面那个声明连T是什么类型都推测不出来
// 只有test.cpp里面调用了func1<int>(100)这样的实例化才能推测出T是要实例化成int类型


#include "func.h"
//int main()
//{
//	func1(100);
//	func2(200);
//
//	return 0;
//}


#include <vector>
#include <list>

//void Print(const vector<int>& v)
//{
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//-----------------------------------------------------------------------------------
//template <class T>
//void Print(const vector<T>& v)
//{
//	//typename vector<T>::const_iterator it = v.begin();
//	auto it = v.begin();
//	// vector<T>::const_iterator是一个类型，但编译器在解析模板时可能无法确定这一点。
//	// 为了明确告诉编译器这是一个类型，我们需要在前面加上typename关键字
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//// 原因是什么呢？因为比如vector<int>是一个实例化好了的类型，确定是int，可以用::const_iterator来取到里面的内嵌类型/成员类型
//// 但是vector<T>是一个模板，T是一个未知类型，那成员类型/内嵌类型都可以用::类域符号来取，静态成员变量也可以
//// 但是问题是编译器不知道vector<T>::const_iterator是一个类型还是一个静态成员变量
//// 
//// 类型：定义变量、函数返回类型或参数类型的标识符。例如 int, std::string，
//// 或类中通过 typedef 或 using 定义的别名（如 const_iterator）。
//
//// 静态成员变量：属于类的全局变量，所有实例共享同一份数据。例如：
////class MyClass 
////{
////public:
////	static int static_member; // 静态成员变量
////};
//
//
////template<typename T>
////void foo() 
////{
////T::const_iterator* ptr; // 这是什么？
////}
//
////编译器可能有两种解释：
////类型：如果 const_iterator 是类型，则 T::const_iterator* ptr 表示声明一个指针变量 ptr。
//
////静态成员变量：如果 const_iterator 是静态成员变量，则 T::const_iterator* ptr 表示计算静态变量与 ptr 的乘积。
//
////由于存在歧义，C++默认假定依赖模板参数的名称是静态成员变量（而非类型），除非用 typename 显式声明。
//
//// 所以需要加上typename来告诉编译器这是一个类型
////或者你也可以用auto来代替，auto会自动推导类型
//-----------------------------------------------------------------------------------
// 最后还能像这样改成一个模板函数，Container可以传入任意类型的容器了
template <class Container>
void Print(const Container& con)
{
	typename Container::const_iterator it = con.begin();
	//auto it = con.begin();
	while (it != con.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


int main()
{
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	Print(v1);

	vector<double> v2 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	Print(v2);// 这里会报错，因为vector<int>和vector<double>是两个不同的类型，所以不能直接传入

	list<double> lt1 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	Print(lt1);


	return 0;
}
