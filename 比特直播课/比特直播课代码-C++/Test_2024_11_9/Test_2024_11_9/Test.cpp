#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using namespace std;

//// 全缺省 全部都有缺省参数
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//// 半缺省  只给一部分缺省参数  半缺省不能跳跃着传参哈，语法写时只能从右往左给实参   如Func(1, , 3)这种是不允许的
//void Func2(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//int main()
//{
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//	Func2(100);
//	Func2(100, 200);
//	Func2(100, 200, 300);
//	return 0;
//}



////函数重载
//#include <iostream>
//using namespace std;
//
//// 1参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//
//// 2参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//// 3参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//
//// 返回值不同不能作为重载条件，因为调⽤时⽆法区分，连入口都进不去，那么输出也就无意义了
////void fxx()
////{
////
////}
//// 
////int fxx()
////{
////	return 0;
////}
//
//
//// 下⾯两个函数构成重载
//// 但是f()调⽤时，会报错，存在歧义，编译器不知道调⽤谁
//void f1()
//{
//	cout << "f()" << endl;
//}
//void f1(int a = 10)
//{
//	cout << "f(int a)" << endl;
//}
//
//
//int main()
//{
//	Add(10, 20);
//	Add(10.1, 20.2);
//	f();
//	f(10);
//	f(10, 'a');
//	f('a', 10);
//	//f1();
//
//	cout << 1;
//	cout << "1111";//输出流能输出不同类型的数据，其本质就是函数重载，通过输入参数（数据类型）的不同，调用多态输出函数来实现的
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//// 用法： 类型& 引⽤别名 = 引⽤对象;
//
////引⽤和取地址的一个显著区别就是，引用不是新定义⼀个变量，⽽是给已存在变量取了⼀个别名，编译器不会为引⽤变量开辟内存空间（在语法层是这样，当然在汇编层引用其本质也是通过取地址来实现的）
//int main()
//{
//	int a = 0;
//	// 引⽤：b和c是a的别名
//	int& b = a;
//	int& c = a;
//	// 也可以给别名b取别名，d相当于还是a的别名
//
//	int& d = b;
//	++d;
//	// 这⾥取地址我们看到是⼀样的
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}
//
//
////引⽤在定义时必须初始化
////int& d;//这样是不行的，必须要表明d究竟是引用的谁
//
//
////⼀个变量可以有多个引⽤
//
//
////引⽤⼀旦引⽤⼀个实体，再不能引⽤其他实体
////int x = 10;
////d = x;//此处是赋值，而不是引用


//#include<iostream>
//using namespace std;
//
//void Swap(int& rx, int& ry)//这里注意，形参的初始化就是在调用函数传实参的时候进行的，所以这里其实引用是初始化过的
//{
//	int tmp = rx;
//	rx = ry;
//	ry = tmp;
//}
//void Swap(double& rx, double& ry)
//{
//	double tmp = rx;
//	rx = ry;
//	ry = tmp;
//}
//
//int main()
//{
//	int x = 0, y = 1;
//	cout << x << " " << y << endl;
//	Swap(x, y);//改变了引用对象就相当于改变了原对象，所以不存在传地址的说法了
//	cout << x << " " << y << endl;
//
//	double d1 = 1.1, d2 = 2.2;
//	Swap(d1, d2);//看起来像是调用了同一个函数，实际上是函数重载，不同参数匹配调到了两个同名但不同内容的Swap
//	cout << d1 << " " << d2 << endl;
//
//	return 0;
//}


#include<iostream>
#include<assert.h>
using namespace std;
typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void STInit(ST& rs, int n = 4)
{
	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
	rs.top = 0;
	rs.capacity = n;
}

//压栈
void STPush(ST& rs, STDataType x)
{
	assert(rs.a);

	// 满了，扩容
	if (rs.top == rs.capacity)
	{
		printf("扩容\n");
		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
		STDataType * tmp = (STDataType*)realloc(rs.a, newcapacity * sizeof(STDataType));

		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		rs.a = tmp;
		rs.capacity = newcapacity;
	}
	rs.a[rs.top] = x;
	rs.top++;
}

// 栈顶
// int STTop(ST& rs)//这种普通传值的方式，返回值其实是一个在寄存器或另一个栈帧中的临时对象，是个右值，无法修改，所以下面的STTop(st1) += 10;是无法实现的，但如果改成int& STTop(ST& rs)，返回的是原值的引用，就可以修改了
int& STTop(ST& rs)
{
	assert(rs.top > 0);
	return rs.a[rs.top - 1];//因为栈顶索引初始设置的是0，所以这里要-1哈，因为栈顶指向的是栈元素中最后一个有效元素的下一个位置，是个空位置，所以这里-1或者初始让栈顶就从-1开始都能解决这个问题
}

int main()
{
	// 调⽤全局的
	ST st1;
	STInit(st1);
	STPush(st1, 1);
	STPush(st1, 2);
	STPush(st1, 3);
	STPush(st1, 4);
	STPush(st1, 5);

	cout << STTop(st1) << endl;
	STTop(st1) += 10;
	cout << STTop(st1) << endl;

	return 0;
}


//#include<iostream>
//using namespace std;
//typedef struct SeqList
//{
//	int a[10];
//	int size;
//}SLT;
//// ⼀些主要⽤C代码实现版本数据结构教材中，使⽤C++引⽤替代指针传参，⽬的是简化程序，避开复杂的指针，但是很多同学没学过引⽤，导致⼀头雾⽔。
//void SeqPushBack(SLT& sl, int x)
//{
//
//}
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//}LTNode, * PNode;//这里其实套在一起用了，实际代码的意思为以下两句
//
////typedef struct ListNode LTNode//typedef结构体，将ListNode结构体简化命名为LTNode
////typedef struct ListNode* PNode//将ListNode* 结构体指针简化命名为PNode
//
//
//
//// 指针变量也可以取别名，这⾥LTNode*& phead就是给指针变量取别名
////这样就不需要⽤⼆级指针了，相对⽽⾔简化了程序
//
////void ListPushBack(LTNode** phead, int x) //二级指针的方式
////void ListPushBack(LTNode*& phead, int x) //一级指针的引用的方式
//void ListPushBack(PNode& phead, int x)  //也是一级指针引用的方式，只不过在之间typedef时，将ListNode* 结构体指针简化命名为PNode
//{
//	PNode newnode = (PNode)malloc(sizeof(LTNode));
//	newnode->val = x;
//	newnode->next = NULL;
//	if (phead == NULL)
//	{
//		phead = newnode;
//	}
//	else
//	{
//
//	}
//}
//
//int main()
//{
//	PNode plist = NULL;
//	ListPushBack(plist, 2);
//	cout << plist->val << endl;
//	return 0;
//}

//注意：C++引用不能完全替代指针，因为C++的引用无法改变指向，所以像如链表的修改，需要修改对象的指向，这种场景下，引用就无法实现，必须要用指针来实现


//int main()
//{
//	const int a = 10;
//
//	//int& ra = a;//这里就存在一个权限放大问题，当我给a取别名后，别名ra是能够被修改的状态，这显然有悖于原本a被const修饰的初衷，故报错    权限不能放大
//	const int& ra = a;//正确的写法，用const修饰别名，保证权限不改变   权限可以平移
//
//	int b = 20;
//	const int& rb = b;//权限可以缩小
//
//	int rra = a;//普通对象，不是同一块空间，是拷贝，不涉及权限问题
//	const int rrb = b;
//
//	const int* pa = &a;
//	//int* ppa = pa;//也是权限放大问题
//
//	int* pb = &b;
//	const int* ppb = pb;
//
//	return 0;
//}



//void func(int& r)
void func(const int& r)//这样+const的引用传参几乎所有类型的参数都能传了，减少拷贝，常量、运算表达式的值、不同类型转换后的值，都能传
{

}


int main()
{
	int a = 10;
	const int& ra = a;
	const int& rra = 30;

	//int& rb = a * 3;//表达式无法引用哈，运算表达式的结果是存在一个临时变量中或寄存器中的，这个临时变量具有常性，无法修改的，所以对表达式结果的引用是无法成立的

	double d = 2.2;
	int c = d;
	//int& rc = d;//这里不是因为类型不同不能引用哈，还是因为权限放大，因为类型转换中间会产生临时对象，来储存转换后的信息，临时对象具有常性，无法修改
	const int& rc = d;//加个const就行了


	int a = 10;

	func(a);
	func(10);
	func(a * 3);
	func(d);


	return 0;
}
