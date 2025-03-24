


#include "stack.h"
#include "queue.h"
#include "priority_queue.h"
#include <queue>
#include <iostream>

//int main()
//{
//	LDW::stack<int, list<int>> mystack;
//	LDW::queue<int, list<int>> myqueue;
//
//	for (int i = 0; i < 5; ++i) myqueue.push(i);
//
//	std::cout << "Popping out elements...";
//	while (!myqueue.empty())
//	{
//		std::cout << ' ' << myqueue.front();
//		myqueue.pop();
//	}
//	std::cout << '\n';
//
//	return 0;
//}


//bool lessFunc(int x, int y)
//{
//    return x < y;
//}

template<class T>
class Less //仿函数/函数对象   就是一个类重载了operator()
{
public:
    bool operator()(const T& x, const T& y)
    {
        return x < y;
    }
};

template<class T>
class Greater
{
public:
    bool operator()(const T& x, const T& y)
    {
        return x > y;
    }
};



int main()
{
	////那么如果同时要一个大queue和一个小queue
 //   //C的话会用函数指针
 //   bool (*ptr)(int, int) = lessFunc;
 //   //ptr 是一个函数指针。定义了一个指向函数 lessFunc 的指针，并且指定该函数指针的类型是 bool (*)(int, int)
 //   //也就是指向一个接受两个 int 参数并返回 bool 的函数  但是不好用哈

    //所以C++搞了 仿函数/函数对象   就是一个类重载了operator()
    Less<int> lessFunc;
    cout << lessFunc(1, 2) << endl;
    //cout << lessFunc.operator()(1, 2) << endl;

    Greater<int> GreaterFunc;
    cout << GreaterFunc(1, 2) << endl;



	//std::priority_queue<int> mypq;// 默认是大优先级高
	LDW::priority_queue<int> mypq1;// 大的优先级高用的是小于，小的优先级高用的大于greater<int>

    mypq1.push(30);
    mypq1.push(100);
    mypq1.push(25);
    mypq1.push(40);

    std::cout << "Popping out elements...";
    while (!mypq1.empty())
    {
        std::cout << ' ' << mypq1.top();
        mypq1.pop();
    }
    std::cout << '\n';


    LDW::priority_queue<int, vector<int>, LDW::Greater<int>> mypq2;//加了仿函数参数的

    mypq2.push(30);
    mypq2.push(100);
    mypq2.push(25);
    mypq2.push(40);

    std::cout << "Popping out elements...";
    while (!mypq2.empty())
    {
        std::cout << ' ' << mypq2.top();
        mypq2.pop();
    }
    std::cout << '\n';

    return 0;
}





