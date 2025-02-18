#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <string>

using namespace std;

class string

{
public:

	string(const char* str = "")
	{

	}

	string(const string& s);

	string& operator=(const string& s);

	~string();

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

