#pragma once

#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>


//ģ��ʵ��һ���򻯵�string��


namespace LDWT//����һ�������ռ� LDWT�����ڽ��ڲ�����������������룬��ֹ������ͻ��
{
	class string
	{
	public:
		//string()//�޲ι��캯��
			//	:_str(new char[1]{'\0'})//new char[1]: ��̬����һ���ַ����飬��СΪ 1�� {'\0'}: ��ʼ��Ϊ�ַ��������� '\0',�൱��ռλ��
			//	, _size(0)//_size: ��ǰ�ַ����ĳ��ȣ������������� '\0'����
			//	,_capacity(0)//_capacity: ��ǰ�ַ�������Ĵ洢�ռ��С��
			//{}

		string(const char* str = "");//ȫȱʡ

		const char* c_str() const//�����ַ����� C ����ʾ��
		{
			return _str;//���� _str �ĵ�ַ�����ⲿ�����ַ������ݡ�
		}

		~string();

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, size_t n, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = nops);

	private:
		//����
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t nops;
	};

	void test_string1();
	void test_string2();
}