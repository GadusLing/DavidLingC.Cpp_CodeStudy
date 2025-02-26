#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <assert.h>
#include <string>

using namespace std;


//实现string类的接口，并完成测试，要求利用深拷贝和深赋值实现
class string

{
public:

	string(const char* str = "")// 构造
	{
		_str = new char[strlen(str) + 1];// 传了一个str过来调用构造,那么new一个strlen(str) + 1大小的空间,记住\0
		strcpy(_str, str);// 拷贝参数的内容到新空间,很传统的写法,程序员手动控制空间
	}

	string(const string& s)// 拷贝
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	string& operator=(const string& s)// 赋值(深)
	{
		if (this != &s)// 避免自己给自己赋值
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}
	~string()
	{
		delete[] _str;
		_str = nullptr;
	}

private:

	char* _str;

};

/* 方法一: string的传统版实现 */

namespace LDW
{
    class string
    {
    public:
        // 构造函数
        string(const char* str = "")
        {
            // 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
            if (nullptr == str)
            {
                assert(false);
                return;
            }
            _str = new char[strlen(str) + 1];
            strcpy(_str, str);
        }

        // 拷贝构造函数
        string(const string& s)
            : _str(new char[strlen(s._str) + 1])
        {
            strcpy(_str, s._str);
        }

        // 赋值运算符
        string& operator=(const string& s)
        {
            if (this != &s)
            {
                delete[] _str;
                _str = new char[strlen(s._str) + 1];
                strcpy(_str, s._str);
            }
            return *this;
        }

        // 析构函数
        ~string()
        {
            delete[] _str;
            _str = nullptr;
        }

    private:
        char* _str;
    };
}

/* 方法二: String的临时对象交换现代版 */

namespace LDW
{
    class string
    {
    public:
        // 构造函数 考虑str为空的情形
        string(const char* str = "")
        {
            // 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
            if (nullptr == str)
            {
                assert(0);
                return;
            }
            _str = new char[strlen(str) + 1];
            strcpy(_str, str);
        }

        // 拷贝构造函数 通过临时对象的交换方式进行拷贝构造
        string(const string& s)
            : _str(nullptr)
        {
            string strTmp(s._str);
            swap(_str, strTmp._str);
        }

        // 赋值运算符 通过临时对象的交换方式进行实现
        string& operator=(const string& s)
        {
            if (this != &s)
            {
                string strTmp(s);
                swap(_str, strTmp._str);
            }
            return *this;
        }

        // 析构函数, 当_str不为空时才进行释放工作并且以数组方式进行释放
        ~string()
        {
            delete[] _str;
            _str = nullptr;
        }

    private:
        char* _str;
    };
}