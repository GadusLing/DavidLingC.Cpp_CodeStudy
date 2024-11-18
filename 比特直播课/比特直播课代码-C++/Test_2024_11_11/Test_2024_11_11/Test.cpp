#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


//inline 内联函数 其作用主要是为了对C中的宏进行优化
#define ADD(a,b) ((a) + (b))
//为什么不能加分号? 不可以，比如在if中，多出的分号会影响编译
//为什么要加外面的括号? 宏本质是替换，不加括号如果外部还有其他的运算表达式，会有符号优先级问题
//为什么要加里面的括号? 同理，内部的替换也会有运算符优先级的问题

inline int Add(int x, int y)
{
	int ret = x + y;
	return ret;
}

int main()
{
	int ret = ADD(1, 2); //int ret = ((1) + (2));
	cout << ((1 * 2) + (2)) << endl;
	cout << ((1 + 2) * (2)) << endl;
	cout << (1 | 2 , 2 ^ 3) << endl;
	cout << Add(1, 2) << endl;

	//注意：inline不建议声明和定义分离到两个⽂件，分离会导致链接错误。因为inline被展开，就没有函数地址，链接时会出现报错。

	return 0;
}

