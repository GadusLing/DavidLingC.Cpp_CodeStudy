#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <assert.h>
using namespace std;


////inline 内联函数 其作用主要是为了对C中的宏进行优化
//#define ADD(a,b) ((a) + (b))
////为什么不能加分号? 不可以，比如在if中，多出的分号会影响编译
////为什么要加外面的括号? 宏本质是替换，不加括号如果外部还有其他的运算表达式，会有符号优先级问题
////为什么要加里面的括号? 同理，内部的替换也会有运算符优先级的问题
//
//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	//ret += 1;
//	//ret += 1;
//	//ret += 1;
//	//ret += 1;
//	//ret += 1;
//	//ret += 1;
//	//ret += 1;
//	//ret += 1;
//	//ret += 1;
//	//ret += 1;
//	//ret += 1;
//
//	return ret;
//}
//
//int main()
//{
//	//int ret = ADD(1, 2); //int ret = ((1) + (2));
//	//cout << ((1 * 2) + (2)) << endl;
//	//cout << ((1 + 2) * (2)) << endl;
//	//cout << (1 | 2 , 2 ^ 3) << endl;
//	int ret = Add(1, 2);
//	cout << Add(1, 2) << endl;
//
//	//注意：inline不建议声明和定义分离到两个⽂件，分离会导致链接错误。因为inline被展开，就没有函数地址，链接时会出现报错。
//
//	return 0;
//}


//类和对象部分(重要)

//class Date
//{
//	void Init(int year, int month, int day)
//	{
//		year = _year;
//		month = _month;
//		day = _day;
//	}
//
//	//通常为了区分类中的成员变量，会在前面加上下划线_或m(member)，具体根据不同项目或公司要求改变
//	int _year;
//	int _month;
//	int _day;
//};
//
//typedef struct ListNodeC
//{
//	struct ListNodeC* next;
//	int val;
//}LTNode;//C++同样支持C中关于struct的用法，同时也将struct升级为了类，一个明显的特点是C++中的struct是可以定义函数的，C则不行
////当然通常还是统一使用Class更为整洁
//
//struct ListNodeCPP//并且此处不再需要写typedef了，ListNodeCPP相当于类名
//{
//	void Init(int x)//你看，可以定义函数
//	{
//		next = nullptr;
//		val = x;
//	}
//	ListNodeCPP* next;
//	int val;
//};
//
//
//int main()
//{
//	LTNode node1;
//	struct ListNodeC node2;
//
//	ListNodeCPP node3;
//	Date node4;
//
//	return 0;
//}


////struct Date
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		year = _year;
//		month = _month;
//		day = _day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	void Init(int n)
//	{
//		_arr = (int*)malloc(sizeof(int) * n);
//		if (nullptr == _arr)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//
//	void Destroy(Stack* ps)
//	{
//		assert(ps);
//		if (ps->_arr != NULL)
//		{
//			free(ps->_arr);
//		}
//		ps->_arr = NULL;
//		ps->_top = ps->_capacity = 0;
//	}
//
//	void Push(Stack* ps, int x)
//	{
//		assert(ps);
//		if (ps->_top == ps->_capacity)
//		{
//			int newCapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
//			int* temp = (int*)realloc(ps->_arr, newCapacity * sizeof(int));
//			assert(temp);
//			ps->_arr = temp;
//			ps->_capacity = newCapacity;
//		}
//		ps->_arr[ps->_top++] = x;
//	}
//
//	int Top(Stack* ps)
//	{
//		assert(ps);
//		assert(ps->_top > 0);
//		return ps->_arr[ps->_top - 1];
//	}
//
//	//...
//private:
//	void CheckCapacity()
//	{
//		//... 其实像类似扩容空间检查类的函数，不期望别人随便用的，都可以放在private里，通过类中的函数调用检查，只把想给的接口放public
//	}
//
//	int* _arr;
//	int _top;
//	int _capacity;
//};
//
//
//int main()
//{
//	Date d1;
//	d1.Init(2024, 11, 11);
//
//	Stack st1;
//	st1.Init(10);//不用像C一样加名字ST区分了
//	st1.Push(&st1, 1);
//	st1.Push(&st1, 2);
//	st1.Push(&st1, 3);
//
//	//int top = st1._arr[st1._top - 1];//不支持像C一样随便访问对象了，私有的不让你随便访问，减少出错
//	int top = st1.Top(&st1);
//
//
//	return 0;
//}


//class Stack
//{
//public:
//	// 成员函数
//	void Init(int n = 4)
//	{}
//};
//
//class Queue
//{
//public:
//	// 成员函数
//	void Init(int n = 4)
//	{}
//};

//#include"Stack.h"
//
//int main()
//{
//	//这里才是定义，定义是统一定义的，类里的三个成员变量是作为对象st1的一部分被定义出来的 是对象定义也是成员变量定义
//	Stack st1;//这就叫类实例化对象
//	Stack st2;
//	Stack st3;
//
//	//Stack::_Top = 1; //这里要注意，在头文件中所设计的类成员变量是声明而非定义
//	//所以即便将它的访问限定权限由private更改为public，也不能访问，因为声明和定义最大的区别就是————是否开辟了空间，没有空间，就无法访问
//	//st1._top = 1;//这样才能访问，虽然我们不期望这样访问，因为是private
//
//	cout << sizeof(st1) << endl;
//	cout << sizeof(Stack) << endl;//注意，计算类的对象大小时，只计算成员变量，不计算成员函数
//	//Why？
//
//	st1._top = 1;
//	st1.Init();
//
//	st2._top = 2;
//	st1.Init();
//
//	//⾸先函数被编译后是⼀段指令，对象中没办法存储，这些指令存储在⼀个单独的区域(代码段)，那么对象中⾮要存储的话，只能是成员函数的指针。
//	//再分析⼀下，对象中是否有存储指针的必要呢，Stack实例化st1和st2两个对象，st1和st2都有各⾃独⽴的成员变量 _arr _top _capacity; 存储各⾃的数据，
//	//但是st1和st2的成员函数Init / Push指针却是⼀样的，是同一个函数。存储在对象中就浪费了。如果⽤Date实例化100个对象，那么成员函数指针就重复存储100次，太浪费了。
//	
//	// 这⾥需要再额外啰嗦⼀下，其实函数指针是不需要存储的，函数指针是⼀个地址，调⽤函数被编译成汇编指令[call 地址]，其实编译器在编译链接时，就要找到函数的地址，不是在运⾏时找，
//	//只有动态多态是在运⾏时找，就需要存储函数地址，这个我们以后会讲解。
//
//	return 0;
//}


////计算⼀下A / B / C实例化的对象是多⼤？
//class A
//{
//public:
//	void Print()
//	{
//		cout << _ch << endl;
//	}
//private:
//	char _ch;//1
//	int _i;//4       对齐后为8
//};
//class B
//{
//public:
//	void Print()//成员函数不算空间
//	{
//		//...
//	}//虽然没有成员变量，但给一个字节做占位符，表示空类，但 “对象存在过”，不然怎么表明这个对象被定义出来了呢
//};
//class C
//{};//同理，占位
//int main()
//{
//	A a;
//	B b;
//	C c;
//	cout << sizeof(a) << endl;
//	cout << sizeof(b) << endl;
//	cout << sizeof(c) << endl;
//	return 0;
//}


#include<iostream>
using namespace std;
class Date
{
public:
	// void Init(Date* const this, int year, int month, int day) //实际上有个this指针哦
	void Init(int year, int month, int day)
	{
		// 编译报错：error C2106 : “ = ” :左操作数必须为左值

		//this = nullptr;
		//this->_year = year;
		//this->_month = month;
		//this->_day = day; //不能在实参和形参的位置显⽰的写this指针(编译时编译器会处理)，但是可以在函数体内显⽰使⽤this指针
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	// 这⾥只是声明，没有开空间，那为什么上面Init的调用能赋值，因为实际上有个this指针，谁（哪个对象）调用，就指向谁
	int _year;
	int _month;
	int _day;
};

int main()
{
	// Date类实例化出对象d1和d2
	Date d1;
	Date d2;
	// d1.Init(&d1, 2024, 3, 31);
	d1.Init(2024, 3, 31);
	d1.Print();

	d2.Init(2024, 7, 5);
	d2.Print();

	return 0;
}






