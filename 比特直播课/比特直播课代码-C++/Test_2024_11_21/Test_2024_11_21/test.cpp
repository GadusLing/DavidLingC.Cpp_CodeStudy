#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//void Test()
//{
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);
//	// 动态申请3个int类型的空间
//	int* ptr6 = new int[3];
//	//C++11之后支持多对象初始化
//	int* ptr7 = new int[10] {1, 2, 3};//后7个默认给0
//
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//	delete[] ptr7;
//
//}
//////这里浅浅演示一下抛异常的问题，主要用作了解，后面会详细讲关于异常的问题
////double Divide(int a, int b)
////{
////	try//；利用try catch来捕获异常，这里只要大概知道这样处理就好了，详细的异常之后会讲
////	{
////		if (b == 0)
////		{
////			string s("Divide by zero condition!");
////			throw s;//抛异常可以抛出一个任意类型的信息，这里就抛了一个string
////		}
////		else 
////		{
////			return ((double)a / (double)b);
////		}
////	}
////	catch (int errid)
////	{
////		cout << errid << endl;
////	}
////	return 0;
////}
//
//class A
//{
//public:
//	A(int a = 0, int b = 0)
//		:_a(a)
//		,_b(b)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//	int _b;
//
//};
//
//
//
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));//对于内置类型而言，malloc和new的区别不大，但还是推荐使用new方法，因为
//	A* p2 = new A(1);//对于自定义类型而言，new除了开空间，还会调用自定义类型的构造函数 
//	free(p1);
//	delete p2;//delete除了释放空间，还会调用自定义类型的析构函数
//	
//	A* p5 = (A*)malloc(sizeof(A) * 10);//如果要坚持写malloc，那我还需要通过循环Init函数来一个个初始化
//	//for (size_t i = 0; i < length; i++)//瞅瞅，多麻烦，别人new都给你封装好了
//	//{
//	//	p5->Init();
//	//}
//	A* p6 = new A[10];//如果有多个对象，会多次调用构造与析构
//	free(p5);
//	delete []p6;
//
//	//new这里还要注意一个问题，new会自动调用默认构造，我们知道默认构造有三类————系统提供的空函数体，起调用作用（双栈队列）、无参的、全缺省的
//	//当没有默认构造可调时，会报错，但是，new是可以传参的
//	
//	A* p7 = new A(1);//你看，单个对象可以传初始化值的，相当于传参
//
//	////多个对象可以这样干
//	//A a1(1), a2(2), a3(3);
//	//A* p8 = new A[10]{ a1,a2,a3 };
//
//	////但是C++还支持
//	//A* p8 = new A[3]{ A(1),A(2),A(3) };//1.匿名对象
//	//A* p8 = new A[3]{ 1,2,3 };//2.单参数构造函数支持隐式类型转换，1，2，3构造临时对象，再拷贝构造给给A[3]，然后编译器会将该过程优化为直接构造，之前在编译器优化中讲过
//
//	////那如果多个对象多参呢？
//	//A* p7 = new A{ 1,2 };//多参这个不变,用花括号，不要用圆括号（，（1，2）这是逗号表达式，取最后的结果了
//	//A* p8 = new A[3]{ {1,1},{2,2},{3,3} };//多个对象多参数也支持隐式类型转换！用花括号
//
//	////那如果写的创建10个呢？
//	A * p8 = new A[10]{ {1,1},{2,2},{3,3} };//不行的哈，自定义类型没有默认构造是不行的，因为后面不写满如果是内置类型会用0来初始化，但如果自定义，你还没有默认构造，没办法用0初始化，不知道给谁
//
//	delete p7;
//	delete[]p8;
//
//	//总之，与malloc和free最大的区别就是，new，delete会调构造和默认构造
//	
//
//	return 0;
//}
////////////////////////////////////////////////////
// 
//operator new与operator delete部分
//这俩函数不是对new和delete的重载哈，就是两个全局的库函数

//class A
//{
//public:
//	A(int a = 0, int b = 0)
//		:_a(a)
//		,_b(b)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//
//int main()
//{
//	//A* p2 = (A*)operator new(sizeof(A));
//	//operator delete(p2);
//	//这里用operator new delete其实就相当于用了malloc free的接口
//
//	//这里主要想讲的是new 和 delete的底层实际上是调用了malloc 和 free 加上调用构造和析构
//	//operator new delete用了抛异常而不是C风格的直接返回空（错误码）
//	
//	//核心操作:operator new + 构造函数
//	A* p2 = new A(1, 1);
//	A* p3 = new A[10];
//
//	//核心操作:析构函数 + operator delete
//	delete p2;
//	delete[] p3;
//
//	return 0;
//}
////////////////////////////////////////////////////////////////////////////////

//各种释放空间的匹配问题
//class A
//{
//public:
//	A(int a = 0, int b = 0)
//		:_a(a)
//		,_b(b)
//	{
//		cout << "A():" << this << endl;
//	}
//	//~A()
//	//{
//	//	cout << "~A():" << this << endl;
//	//}
//private:
//	int _a;
//	int _b;
//};
//
//int main()
//{
//	//A* p5 = (A*)malloc(sizeof(A) * 10);
//	//delete p5;
//
//
//	//int* p6 = (int*)malloc(sizeof(int) * 10);
//	//delete p6;
//
//	//int* p7 = new int[10];//这里会发生内存泄露吗？实际上不会
//	//delete p7;//这里对内置类型操作实际上就是malloc 和 free套了一层皮
//
//	A* p8 = new A[10];//但是这样会出错
//	delete p8;
//
//	//**用来存个数** p7***********申请的80个字节的空间**************
//
//	// 那么是怎么一回事儿呢，实际上在处理自定义类型时，delete需要调用多次析构
//	//那么如何获取到需要调多少次呢？于是C++设计使用new[]在所申请的这块空间之前会多几个字节，比如上述例子申请80，实际上会申请84
//	//前面4个用来存放所申请对象空间的个数，后面80才是所需的空间，p7指针也是从这里开始
//	//有多少个对象就调用多少次析构，所以delete[]实际上每次都会从图上p7的部分开始往前读4个字节寻找次数，然后再从后调用析构以及释放空间
//	//那么如果使用delete而非delete[]来释放，delete里面并没用存对象个数这种设定，因为它默认就是给单个对象使用的，此时就出问题了
//	//此时有两个问题，第一个问题是析构函数次数没调够，delete只会调一次析构，只要析构涉及资源释放就会内存泄漏；二是delete没有读对象个数的设定，所以它默认会从p7指针位置直接开始释放
//	//而内存释放是不支持从中间某一段开始释放的，故报错
//
//
//	//那么当我把上面类中的析构函数给注释掉，会发生什么呢？不会报错了
//	//因为这个时候编译器进行了优化
//	//编译器看到A类没有显示实现析构函数，而自己默认生成的也没有释放什么资源，所以干脆就不调用了，也不用记录调用次数了
//
//	
//	//new delete的匹配更多的是在构造和析构问题的匹配上，和内存泄露倒没有很大的关系
//	//所以核心点，底层的东西很复杂，不要去乱匹配，蹦出一些问题,要是显示写了析构呢？要是有些编译器没优化呢？所以一定要匹配
//
//	return 0;
//}
/////////////////////////////////////////////////

//进入模板的内容


////模板的原理是啥呢？
////模板函数 -> 泛型/任意类型
////template<typename T>
//template<class T>//也可以用class，因为都是定义类型嘛，在某些特殊的地方这两个关键词才有区别，以后会讲
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//
//int main()
//{
//	int x = 1, y = 2;
//	Swap(x, y);
//
//	double m = 1.1, n = 2.2;
//	Swap(m, n);
//
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0, int b = 0)
//		:_a(a)
//		,_b(b)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//
//template<typename T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//template<typename T>
//T* func(size_t n)//参数里面不带T，无法推断T是什么，所以要在调用那边显示实例化
//{
//	return new T[n];
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	//推演实例化
//	cout << Add(a1, a2) << endl;
//	cout << Add(d1, d2) << endl;
//
//	//cout << Add(a1, d2) << endl;//交叉使用，类型匹配不上的话会报错哦
//	//因为推导T参数的时候会产生矛盾，编译器不知道到底你要int还是double
//
//	//解决方案有这样几种
//	//1.强转
//	cout << Add(a1, (int)d2) << endl;
//	cout << Add((double)a1, d2) << endl;
//	//但是强转精度可能会丢失，浮点数嘛，10 + 20 和 10.0 + 20.2
//
//	//2.上述都是推演实例化，我们还可以显示实例化
//	cout << Add<int>(a1, d2) << endl;
//	cout << Add<double>(a1, d2) << endl;//当然也会有警告，因为丢精度嘛
//	//func(10);//这样是不行的哦，函数那边接收不到你到底要什么类型
//
//	func<A>(10);//不明确T类型的时候用显示实例化
//
//
//	return 0;
//}
//////////////////////////////////////////////


//template<typename T>
//T Add(const T& left, const T& right)
//{
//	cout << "T" << endl;
//	return left + right;
//}
////二者可以同时存在，并且优先使用普通函数，没有才会去调模板(有现成吃现场，开销小)
//int Add(int left, int right)
//{
//	cout << "int" << endl;
//	return left + right;
//}
//
//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1.1, 2) << endl;//此时还是调用了intAdd哦，直接强转了
//	cout << Add<double>(1.1, 2) << endl;//这样的话也会强制用T模板生成double类型函数了
//
//	return 0;
//}
////////////////////////////////////////////////

////专门处理int的加法函数
//int Add(int left, int right)
//{
//	cout << "int" << endl;
//	return left + right;
//}
////通用加法函数
//template<typename T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	cout << "T" << endl;
//	return left + right;
//}
//
////当有现成的普通函数，但存在参数更匹配的模板函数时，会选择更匹配的
//int main()
//{
//	Add(1, 2);
//	Add(1, 2.2);
//
//	return 0;
//}
////////////////////////////////////////////////

//typedef int STDataType 可以换成 template<typename T>
//然后用 Stack<int> ST1;
//      Stack<Double> ST2; 来统一构造不同类型的栈了





