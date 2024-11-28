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

