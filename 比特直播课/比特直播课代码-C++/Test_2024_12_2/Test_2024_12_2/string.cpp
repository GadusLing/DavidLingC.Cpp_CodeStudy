#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

class string

{
public:

	string(const char* str = "")
	{
		_str = new char[strlen(str) + 1];// ����һ��str�������ù���,��ônewһ��strlen(str) + 1��С�Ŀռ�,��ס\0
		strcpy(_str, str);// �������������ݵ��¿ռ�,�ܴ�ͳ��д��,����Ա�ֶ����ƿռ�
	}

	string(const string& s)
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	string& operator=(const string& s)
	{

	}
	~string()
	{
		delete[] _str;
		_str = nullptr;
	}

private:

	char* _str;

};

///* ����һ: string�Ĵ�ͳ��ʵ�� */
//
//namespace LDW
//{
//    class string
//    {
//    public:
//        // ���캯��
//        string(const char* str = "")
//        {
//            // ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
//            if (nullptr == str)
//            {
//                assert(false);
//                return;
//            }
//            _str = new char[strlen(str) + 1];
//            strcpy(_str, str);
//        }
//
//        // �������캯��
//        string(const string& s)
//            : _str(new char[strlen(s._str) + 1])
//        {
//            strcpy(_str, s._str);
//        }
//
//        // ��ֵ�����
//        string& operator=(const string& s)
//        {
//            if (this != &s)
//            {
//                delete[] _str;
//                _str = new char[strlen(s._str) + 1];
//                strcpy(_str, s._str);
//            }
//            return *this;
//        }
//
//        // ��������
//        ~string()
//        {
//            delete[] _str;
//            _str = nullptr;
//        }
//
//    private:
//        char* _str;
//    };
//}
//
///* ������: String����ʱ���󽻻��ִ��� */
//
//namespace LDW
//{
//    class string
//    {
//    public:
//        // ���캯�� ����strΪ�յ�����
//        string(const char* str = "")
//        {
//            // ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
//            if (nullptr == str)
//            {
//                assert(0);
//                return;
//            }
//            _str = new char[strlen(str) + 1];
//            strcpy(_str, str);
//        }
//
//        // �������캯�� ͨ����ʱ����Ľ�����ʽ���п�������
//        string(const string& s)
//            : _str(nullptr)
//        {
//            string strTmp(s._str);
//            swap(_str, strTmp._str);
//        }
//
//        // ��ֵ����� ͨ����ʱ����Ľ�����ʽ����ʵ��
//        string& operator=(const string& s)
//        {
//            if (this != &s)
//            {
//                string strTmp(s);
//                swap(_str, strTmp._str);
//            }
//            return *this;
//        }
//
//        // ��������, ��_str��Ϊ��ʱ�Ž����ͷŹ������������鷽ʽ�����ͷ�
//        ~string()
//        {
//            delete[] _str;
//            _str = nullptr;
//        }
//
//    private:
//        char* _str;
//    };
//}