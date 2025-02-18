#pragma once

#include <iostream>              // �������������ͷ�ļ�
#include <cstring>               // ����C��׼�ַ���������������strlen��strcpy��
#include <assert.h>
#include <string.h>

using namespace std;

namespace LDW // �����������ռ䣬��ֹ�ͱ�׼���е� string ������ͻ
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const string& s);
        friend istream& operator>>(istream& _cin, string& s);
    public:
        typedef char* iterator; // ���������Ͷ��壬���ڱ����ַ���
        typedef const char* const_iterator; // ���������Ͷ���const�汾

    public:
        string(const char* str = ""); // ���캯����Ĭ�Ϲ�����ַ��� ""
        string(const string& s); // �������캯��
        //string& operator=(const string& s); // ��ֵ���������
        string& operator=(string s);// �ִ�д����ֵ���������,��ֵ����
        ~string(); // �����������ͷŶ�̬������ڴ�

        //////////////////////////////////////////////////////////////

        // ��������غ���
        iterator begin(); // ����ָ���ַ������ַ��ĵ�����
        iterator end();   // ����ָ���ַ���ĩβ��\0��֮��ĵ�����
        const_iterator begin() const;
        const_iterator end() const;

        /////////////////////////////////////////////////////////////

        // �޸��ַ����ĳ�Ա����
        void push_back(char c); // ���ַ���ĩβ����ַ� c
        string& operator+=(char c); // ���� += �������׷���ַ� c
        void append(const char* str); // ׷�� C ����ַ���
        string& operator+=(const char* str); // ���� += �������׷�� C ����ַ���
        void clear(); // ����ַ�������
        void swap(string& s); // ������ǰ�ַ����� s ������
        const char* c_str() const; // ���� C ����ַ�����char* ���ͣ����� \0 ��β��

        /////////////////////////////////////////////////////////////

        // ����������س�Ա����
        size_t size() const; // ���ص�ǰ�ַ�������
        size_t capacity() const; // ���ص�ǰ�ַ�������
        bool empty() const; // �ж��ַ����Ƿ�Ϊ��
        void resize(size_t n, char c = '\0'); // �����ַ�����С������Ĳ����� c ���
        void reserve(size_t n); // Ԥ������ n ���ַ��Ĵ洢�ռ䣬����Ƶ������

        /////////////////////////////////////////////////////////////

        // ����Ԫ��
        char& operator[](size_t index); // ���� [] ���������ȡ index λ�õ��ַ�
        const char& operator[](size_t index) const; // ���� index λ�õ��ַ��������汾��

        /////////////////////////////////////////////////////////////

        // ��ϵ��������أ������ַ����Ƚϣ�
        bool operator<(const string& s); // С�������
        bool operator<=(const string& s); // С�ڵ��������
        bool operator>(const string& s); // ���������
        bool operator>=(const string& s); // ���ڵ��������
        bool operator==(const string& s); // ���������
        bool operator!=(const string& s); // �����������

        /////////////////////////////////////////////////////////////

        // ���Ҳ���
        size_t find(char c, size_t pos = 0) const; // �����ַ� c ��һ�γ��ֵ�λ��
        size_t find(const char* s, size_t pos = 0) const; // �����Ӵ� s ��һ�γ��ֵ�λ��

        /////////////////////////////////////////////////////////////

        // �������
        string& insert(size_t pos, size_t n, char c); // �� pos λ�ò���n���ַ� c
        string& insert(size_t pos, const char* str); // �� pos λ�ò����ַ��� str

        /////////////////////////////////////////////////////////////

        // ɾ������
        string& erase(size_t pos = 0, size_t len = npos); // �� pos λ��ɾ�� len ���ַ�,�����ظ�Ԫ�ص���һ��λ��

    private:
        char* _str = nullptr; // ָ��洢�ַ����Ķ�̬����
        size_t _capacity = 0; // ��ǰ����Ŀռ��С������ null ��ֹ����
        size_t _size = 0; // ��ǰ�ַ����ĳ��ȣ������� null ��ֹ����

        const static size_t npos;
    };

    
}
