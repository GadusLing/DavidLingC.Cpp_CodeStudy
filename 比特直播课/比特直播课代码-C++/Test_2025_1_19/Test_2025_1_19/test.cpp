


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
class Less //�º���/��������   ����һ����������operator()
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
	////��ô���ͬʱҪһ����queue��һ��Сqueue
 //   //C�Ļ����ú���ָ��
 //   bool (*ptr)(int, int) = lessFunc;
 //   //ptr ��һ������ָ�롣������һ��ָ���� lessFunc ��ָ�룬����ָ���ú���ָ��������� bool (*)(int, int)
 //   //Ҳ����ָ��һ���������� int ���������� bool �ĺ���  ���ǲ����ù�

    //����C++���� �º���/��������   ����һ����������operator()
    Less<int> lessFunc;
    cout << lessFunc(1, 2) << endl;
    //cout << lessFunc.operator()(1, 2) << endl;

    Greater<int> GreaterFunc;
    cout << GreaterFunc(1, 2) << endl;



	//std::priority_queue<int> mypq;// Ĭ���Ǵ����ȼ���
	LDW::priority_queue<int> mypq1;// ������ȼ����õ���С�ڣ�С�����ȼ����õĴ���greater<int>

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


    LDW::priority_queue<int, vector<int>, LDW::Greater<int>> mypq2;//���˷º���������

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





