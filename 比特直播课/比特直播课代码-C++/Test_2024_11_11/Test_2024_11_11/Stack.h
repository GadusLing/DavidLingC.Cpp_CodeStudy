#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

class Stack
{
public:
	void Init(int n = 0);//ע�⣬�����ȱʡ����int n = 0��ȱʡ����ֻ���������ĵط����������ڶ����Ǳ߸�Ŷ

	void Destroy(Stack* ps);

	void Push(Stack* ps, int x);

	int Top(Stack* ps);

	//...
//private:
	//�����ǳ�Ա������ ��������û�п��ռ�
	int* _arr;
	int _top;
	int _capacity;
};