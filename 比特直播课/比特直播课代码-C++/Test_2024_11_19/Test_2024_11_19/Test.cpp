#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//class A
//{
//public:
//	static int _scount;//假设是共有的情况，可以在外面访问
//
//private:
//	//类里面声明，但不能在类定义，因为static是全局的
//	//static int _scount;
//
//};
//
////在类外面初始化，声明和定义分离
//int A::_scount = 0;
//
//
//
//int main()
//{
//
//	cout << sizeof(A) << endl;//静态成员变量并不在这个类内部，而是存在静态区，所以不计算它的大小
//	cout << A::_scount << endl;
//	A aa1;
//	A aa2;
//
//	cout << aa1._scount << endl;
//	cout << aa2._scount << endl;
//
//
//	static int l = 0;//此时它不属于main，而是属于全局，static变量是放在静态区，属于所有对象共享的
//
//	return 0;
//}
////////////////////////////////////////////////////////////////

//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//
//	A(const A& t)
//	{
//		++_scount;
//	}
//
//	~A()
//	{
//		--_scount;
//	}
//
//	static int GetACount()
//	{
//		//++_a1;//static成员函数没有this指针所以无法访问
//		return _scount;
//	}
//private:
//	// 类⾥⾯声明
//	static int _scount;
//
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//// 类外⾯初始化
//int A::_scount = 0;
//
//int main()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//	cout << a1.GetACount() << endl;
//	// 编译报错：error C2248 : “A::_scount” :⽆法访问private成员(在“A”类中声明)
//	//cout << A::_scount << endl;
//
//	return 0;
//}
///////////////////////////////////////////////////////

//class Sum//构造函数的解法，通过静态变量与静态成员函数是全局共享的特性，调用n次构造并累加static的数字以获取结果
//{
//public:
//    Sum()
//    {
//        _ret += _count;
//        _count++;
//    }
//    static int GetRet()
//    {
//        return _ret;
//    }
//private:
//    static int _count;
//    static int _ret;
//};
//
//int Sum::_count = 1;
//int Sum::_ret = 0;
//
//class Solution
//{
//public:
//    int Sum_Solution(int n)
//    {
//        //Sum a[n];//VS不支持变长数组
//        Sum* a = new Sum[n];//通过new来解决空间问题
//        delete[] a;//记得释放避免内存泄漏
//        return Sum::GetRet();
//    }
//};
//
//int main()
//{
//    int n = 100;
//    Solution solution;//static静态成员函数能够通过::直接调用因为它是全局的，而普通类成员函数只能通过实例化对象进行调用，static没有this，而普通成员函数有this
//    cout << solution.Sum_Solution(n) << endl;
//
//    return 0;
//}
//////////////////////////////////////////////////////////
//内部类

//class A
//{
//private:
//	static int _k;//静态成员变量不属于类的具体实例，而是所有实例共享的，因此不占用类实例的空间。
//	int _h = 1;
//
//public:
//	class B // B默认就是A的友元，刘备
//	{
//    public:
//        void foo(const A& a)
//        {
//            cout << _k << endl;          //OK
//            cout << a._h << endl;        //OK
//        }
//
//        int _b1 = 1;
//        int _b2 = 1;
//    };
//};
//
//int A::_k = 1;
//
//int main()
//{
//    cout << sizeof(A) << endl;//内部类 B 是逻辑上定义在类 A 内的一个独立类，它的定义不会影响 A 类的大小。它只是收到了访问作用域的限制
//    A::B b;//这里就受类域的限制
//    A aa;
//    b.foo(aa);
//    return 0; 
//}
////////////////////////////////////////////////
//匿名对象
//class A
//{
//public:
//    A(int a = 0)
//        :_a(a)
//    {
//        cout << "A(int a)" << endl;
//    }
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//private:
//    int _a;
//};
//
//class Solution 
//{
//public:
//    int Sum_Solution(int n) 
//    {
//        //...
//        return n;
//    }
//};
//
//void func1(int i = 0)
//{
//
//}
//
////void func2(const A& aa = A())
//void func2(const A& aa = A(10))//自定义类型匿名对象做缺省参数
//{
//
//}
//
//int main()
//{
//    A aa1;
//    A aa2(2);
//    // 不能这么定义对象，因为编译器⽆法识别下⾯是⼀个函数声明，还是对象定义
//    // A aa1();
//    
//    // 但是我们可以这么定义匿名对象，匿名对象的特点不⽤取名字，
//    // 但是他的⽣命周期只有这⼀⾏，我们可以看到下⼀⾏他就会⾃动调⽤析构函数
//    A();
//    A(1);
//
//    A& ref1 = aa1;
//
//    //cosnt引用会延长匿名对象的生命周期，匿名对象跟着引用走，ref2销毁匿名对象才会销毁
//    const A& ref2 = A();
//
//    // 匿名对象在这样场景下就很好⽤，当然还有⼀些其他使⽤场景，这个我们以后遇到了再说
//    Solution().Sum_Solution(10);
//
//    return 0;
//}
//////////////////////////////////////////////////////////////////
//编译器优化
//class A
//{
//public:
//    A(int a = 0)
//        :_a1(a)
//    {
//        cout << "A(int a)" << endl;
//    }
//    A(const A& aa)
//        :_a1(aa._a1)
//    {
//        cout << "A(const A& aa)" << endl;
//    }
//    A& operator=(const A& aa)
//    {
//        cout << "A& operator=(const A& aa)" << endl;
//        if (this != &aa)
//        {
//            _a1 = aa._a1;
//        }
//        return *this;
//    }
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//
//private:
//    int _a1 = 1;
//};
//
//A f2()
//{
//    A aa;
//    return aa;
//}
//
//int main()
//{
//    A aa2;
//    aa2 = f2();
//
//
//    return 0;
//}
//
//
//
////A f2()
////{
////    A aa;
////    return aa;
////}
////
////int main()
////{
////    // 返回时⼀个表达式中，连续拷⻉构造+拷⻉构造->优化⼀个拷⻉构造（vs2019）
////    // ⼀些编译器会优化得更厉害，进⾏跨⾏合并优化，直接变为构造。（vs2022）
////    f2();
////    cout << endl;
////}
//
////void f1(A aa)
////{
////
////}
////
////int main()
////{
////    //A aa1(1);
////    //f1(aa1);
////
////    f1(1);
////    f1(A(1));
////
////    return 0;
////}
//
////int main()
////{
////    A aa1 = 1;//类型转换会产生临时变量 //隐式类型，连续构造+拷⻉构造->优化为直接构造
////    //原本应该是用1先拷贝构造一个A，再穿给aa1构造
////
////    A aa2(1);//直接构造
////
////    return 0;
////}

////////////////////////////////////////////////////////////
//内存管理

