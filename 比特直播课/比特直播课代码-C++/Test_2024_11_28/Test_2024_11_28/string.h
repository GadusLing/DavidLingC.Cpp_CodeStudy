#pragma once

#include <iostream>              // 包含输入输出流头文件
#include <cstring>               // 包含C标准字符串操作函数，如strlen、strcpy等
#include <assert.h>
#include <string.h>

using namespace std;

namespace LDW // 这里用命名空间，防止和标准库中的 string 产生冲突
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const string& s);
        friend istream& operator>>(istream& _cin, string& s);
    public:
        typedef char* iterator; // 迭代器类型定义，用于遍历字符串
        typedef const char* const_iterator; // 迭代器类型定义const版本

    public:
        string(const char* str = ""); // 构造函数，默认构造空字符串 ""
        string(const string& s); // 拷贝构造函数
        //string& operator=(const string& s); // 赋值运算符重载
        string& operator=(string s);// 现代写法赋值运算符重载,传值传参
        ~string(); // 析构函数，释放动态分配的内存

        //////////////////////////////////////////////////////////////

        // 迭代器相关函数
        iterator begin(); // 返回指向字符串首字符的迭代器
        iterator end();   // 返回指向字符串末尾（\0）之后的迭代器
        const_iterator begin() const;
        const_iterator end() const;

        /////////////////////////////////////////////////////////////

        // 修改字符串的成员函数
        void push_back(char c); // 在字符串末尾添加字符 c
        string& operator+=(char c); // 重载 += 运算符，追加字符 c
        void append(const char* str); // 追加 C 风格字符串
        string& operator+=(const char* str); // 重载 += 运算符，追加 C 风格字符串
        void clear(); // 清空字符串内容
        void swap(string& s); // 交换当前字符串与 s 的内容
        const char* c_str() const; // 返回 C 风格字符串（char* 类型，包含 \0 结尾）

        /////////////////////////////////////////////////////////////

        // 容量管理相关成员函数
        size_t size() const; // 返回当前字符串长度
        size_t capacity() const; // 返回当前字符串容量
        bool empty() const; // 判断字符串是否为空
        void resize(size_t n, char c = '\0'); // 调整字符串大小，多出的部分用 c 填充
        void reserve(size_t n); // 预留至少 n 个字符的存储空间，避免频繁扩容

        /////////////////////////////////////////////////////////////

        // 访问元素
        char& operator[](size_t index); // 重载 [] 运算符，获取 index 位置的字符
        const char& operator[](size_t index) const; // 访问 index 位置的字符（常量版本）

        /////////////////////////////////////////////////////////////

        // 关系运算符重载（用于字符串比较）
        bool operator<(const string& s); // 小于运算符
        bool operator<=(const string& s); // 小于等于运算符
        bool operator>(const string& s); // 大于运算符
        bool operator>=(const string& s); // 大于等于运算符
        bool operator==(const string& s); // 等于运算符
        bool operator!=(const string& s); // 不等于运算符

        /////////////////////////////////////////////////////////////

        // 查找操作
        size_t find(char c, size_t pos = 0) const; // 查找字符 c 第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const; // 查找子串 s 第一次出现的位置

        /////////////////////////////////////////////////////////////

        // 插入操作
        string& insert(size_t pos, size_t n, char c); // 在 pos 位置插入n个字符 c
        string& insert(size_t pos, const char* str); // 在 pos 位置插入字符串 str

        /////////////////////////////////////////////////////////////

        // 删除操作
        string& erase(size_t pos = 0, size_t len = npos); // 从 pos 位置删除 len 个字符,并返回该元素的下一个位置

    private:
        char* _str = nullptr; // 指向存储字符串的动态数组
        size_t _capacity = 0; // 当前分配的空间大小（包含 null 终止符）
        size_t _size = 0; // 当前字符串的长度（不包含 null 终止符）

        const static size_t npos;
    };

    
}
