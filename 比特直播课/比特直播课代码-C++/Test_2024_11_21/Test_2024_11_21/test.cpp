#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


void Test()
{
	// ��̬����һ��int���͵Ŀռ�
	int* ptr4 = new int;
	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
	int* ptr5 = new int(10);
	// ��̬����3��int���͵Ŀռ�
	int* ptr6 = new int[3];
	//C++11֮��֧�ֶ�����ʼ��
	int* ptr7 = new int[10] {1, 2, 3};//��7��Ĭ�ϸ�0

	delete ptr4;
	delete ptr5;
	delete[] ptr6;
	delete[] ptr7;

}
////����ǳǳ��ʾһ�����쳣�����⣬��Ҫ�����˽⣬�������ϸ�������쳣������
//double Divide(int a, int b)
//{
//	try//������try catch�������쳣������ֻҪ���֪����������ͺ��ˣ���ϸ���쳣֮��ὲ
//	{
//		if (b == 0)
//		{
//			string s("Divide by zero condition!");
//			throw s;//���쳣�����׳�һ���������͵���Ϣ�����������һ��string
//		}
//		else 
//		{
//			return ((double)a / (double)b);
//		}
//	}
//	catch (int errid)
//	{
//		cout << errid << endl;
//	}
//	return 0;
//}



int main()
{
	Test();

	return 0;
}