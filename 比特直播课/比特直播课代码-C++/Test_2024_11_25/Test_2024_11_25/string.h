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
		typedef char* iterator;
		typedef const char* const_iterator;//const�������ǵ�����const_����Ŷ

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;//����ע��end���������ص���һ��char*���͵�ָ��,���Բ���ֱ��дreturn _size,Ҫ��_str + _szie
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		//string()//�޲ι��캯��
			//	:_str(new char[1]{'\0'})//new char[1]: ��̬����һ���ַ����飬��СΪ 1�� {'\0'}: ��ʼ��Ϊ�ַ��������� '\0',�൱��ռλ��
			//	, _size(0)//_size: ��ǰ�ַ����ĳ��ȣ������������� '\0'����
			//	,_capacity(0)//_capacity: ��ǰ�ַ�������Ĵ洢�ռ��С��
			//{}

		string(const char* str = "");//ȫȱʡ
		string(size_t n, char ch);

		const char* c_str() const//�����ַ����� C ����ʾ��
		{
			return _str;//���� _str �ĵ�ַ�����ⲿ�����ַ������ݡ�
		}

		string(const string& s);

		string& operator=(const string& s);

		~string();

		void clear()
		{
			//erase();//��һ��erase������
			_str[0] = '\0';//�Լ�дҲ�ܼ�
			_size = 0;
		}

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, size_t n, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = npos);

		size_t find(char ch, size_t pos = 0);
		size_t find(const char* ch, size_t pos = 0);

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		string substr(size_t pos, size_t len = npos);

		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;
		bool operator<(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator>(const string& s) const;
		bool operator>=(const string& s) const;


	private:
		//����
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos;
	};

	//�����������ȡ,����Ϊȫ�ּǵ�
	ostream& operator<<(ostream& out, const string& s);
	ostream& operator>>(ostream& out, string& s);

	istream& getline(istream& in, string& s, char delim = '\n');


	void test_string1();
	void test_string2();
	void test_string3();
	void test_string4();
	void test_string5();
	void test_string6();


}