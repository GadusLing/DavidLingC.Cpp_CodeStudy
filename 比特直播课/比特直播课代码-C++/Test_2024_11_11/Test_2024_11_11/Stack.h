#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

class Stack
{
public:
	void Init(int n = 0);//注意，这里给缺省参数int n = 0，缺省参数只能在声明的地方给，不能在定义那边给哦

	void Destroy(Stack* ps);

	void Push(Stack* ps, int x);

	int Top(Stack* ps);

	//...
//private:
	//这里是成员变量的 声明哈，没有开空间
	int* _arr;
	int _top;
	int _capacity;
};