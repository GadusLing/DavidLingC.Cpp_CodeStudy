#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace LDWT
{
	const size_t string::nops = -1;

	string::string(const char* str)//ȫȱʡ
		:_size(strlen(str))//ʹ�� strlen ���㴫���ַ����ĳ��ȣ������������� '\0'�������� _size��
	{
		_capacity = _size;//��ʼ�� _capacity Ϊ _size��ȷ���㹻�Ĵ洢�ռ䡣
		_str = new char[strlen(str) + 1];//��̬�����ڴ棬��СΪ�ַ������ȼ� 1��Ϊ������ '\0' ���ռ䣩
		strcpy(_str, str);//ʹ�� strcpy ���ַ������ݴ� str ���Ƶ� _str��
	}

	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size + 1 > _capacity)
		{
			//���� 
			string::reserve(_size == 0 ? 4 : _capacity * 2);
		}

		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			//����
			size_t newCapacity = 2 * _capacity;
			if (_size + len > 2 * _capacity)
			{
				newCapacity = _size + len;
			}

			reserve(newCapacity);
		}
		strcpy(_str + _size, str);
		_size += len;
	}

	string& string::operator+=(char ch)
	{
		string::push_back(ch);
		return *this;
	}

	string& string::operator+=(const char* str)
	{
		string::append(str);
		return *this;
	}

	void string::insert(size_t pos, size_t n, char ch)
	{
		assert(pos <= _size);
		if (_size + n > _capacity)//��鵱ǰ���� _capacity �Ƿ��㹻���ɲ������ַ������ȡ��������������Ҫ���ݡ�
		{
			//����
			size_t newCapacity = 2 * _capacity;
			if (_size + n > 2 * _capacity)
			{
				newCapacity = _size + n;
			}

			reserve(newCapacity);
		}
		//Ų������
		size_t end = _size;//end ��ʼ��Ϊ�ַ��������һ���ַ����� _size��ʵ�ʴ洢Ϊ '\0' ��λ�ã���
		while (end >= pos)
		{
			_str[end + n] = _str[end]; //������ end ���ַ��ƶ��� end + n ��λ�ã�Ϊ�²�����ַ��ڳ��ռ䡣
			--end;//end ��ǰ�ƶ���
		}

		for (size_t i = 0; i < n; ++i)
		{
			_str[pos + i] = ch;
		}
		_size += n;
	}

	void string::insert(size_t pos, const char* str)
	{


	}

	void string::erase(size_t pos, size_t len)
	{


	}

	void test_string1()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		string s2;
		cout << s2.c_str() << endl;

		s1 += ' ';
		s1 += '+';
		s1 += "hello world";
		cout << s1.c_str() << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.insert(6, 3, 'x');
		cout << s1.c_str() << endl;
	}
}