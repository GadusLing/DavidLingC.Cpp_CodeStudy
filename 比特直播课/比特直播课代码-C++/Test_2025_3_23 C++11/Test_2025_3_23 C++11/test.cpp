#include <iostream>
#include <vector>
using namespace std;
////
////struct Point 
////{
////    int x;
////    int y;
////};
////
////class Date 
////{
////public:
////    Date(int year = 1, int month = 1, int day = 1)
////        : year_(year)
////        , month_(month)
////        , day_(day) 
////    {
////        cout << "Date Constructor: " << year_ << "-" << month_ << "-" << day_ << endl;
////    }
////
////    Date(const Date& d)
////        : year_(d.year_)
////        , month_(d.month_)
////        , day_(d.day_) 
////    {
////        cout << "Date Copy Constructor" << endl;
////    }
////
////private:
////    int year_;
////    int month_;
////    int day_;
////};
//
////int main() 
////{
////    // C++98 风格的初始化
////    int a1[] = { 1, 2, 3, 4, 5 };  // 数组初始化
////    int a2[5] = { 0 };              // 数组全零初始化
////    Point p = { 1, 2 };             // 结构体初始化
////
////    // C++11 统一初始化语法
////    // 1. 基本类型初始化
////    int x1 = { 2 };     // 带等号的列表初始化
////    int x2{ 2 };        // 不带等号的列表初始化（推荐）
////
//////    // 2. 自定义类型初始化
//////    Date d1 = { 2025, 1, 1 };  // 拷贝构造优化（实际直接构造）
//////    const Date& d2 = { 2024, 7, 25 };  // 引用临时对象
//////
//////    // 3. 单参数初始化（支持隐式转换）
//////    Date d3 = { 2025 };  // 列表初始化
//////    Date d4 = 2025;    // C++98风格（仅单参数有效）
//////
//////    // 4. 省略等号的初始化
//////    Point p1{ 1, 2 };             // 结构体
//////    Date d6{ 2024, 7, 25 };       // 直接构造
//////    const Date& d7{ 2024, 7, 25 };// 引用临时对象
//////
//////    // 5. 容器中使用统一初始化
//////    vector<Date> v;
//////    v.push_back(d1);                  // 有名对象
//////    v.push_back(Date(2025, 1, 1));    // 匿名对象
//////    v.push_back({ 2025, 1, 1 });        // 直接列表初始化（最简洁）
//////
//////    return 0;
//////}
////
////int main() 
////{
////    // ============= 左值示例 =============
////    // 左值：可以取地址、有持久状态的对象
////
////    // 1. 指针和基本类型
////    int* p = new int(0);  // p是左值（可修改）
////    *p = 10;              // *p是左值（可修改）
////
////    int b = 1;            // b是左值
////    const int c = b;      // c是左值（不可修改）
////    cout << "左值地址示例：" << endl;
////    cout << "&c: " << &c << endl;  // 可以取地址
////
////    // 2. 字符串对象
////    string s("111111");   // s是左值
////    s[0] = 'x';           // s[0]是左值（可修改）
////    cout << "字符串首字符地址: " << (void*)&s[0] << endl << endl;
////
////    // ============= 右值示例 =============
////    // 右值：临时对象、字面量、表达式结果（不能取地址）
////    double x = 1.1, y = 2.2;
////
////    cout << "右值示例（无法取地址）：" << endl;
////    // 1. 字面量
////    10;                  // 字面量是右值
////    // &10;              // 错误：无法取地址
////
////    // 2. 表达式结果
////    x + y;               // 表达式结果是右值
////    // &(x + y);         // 错误：无法取地址
////
////    // 3. 函数返回值
////    fmin(x, y);          // 返回临时对象（右值）
////    // &fmin(x, y);      // 错误：无法取地址
////
////    // 4. 显式创建的临时对象
////    string("11111");     // 临时string对象（右值）
////    // &string("11111"); // 错误：无法取地址
////
////    // 释放动态内存
////    delete p;
////    return 0;
////}
////
//////中间一些基本语法的示范代码我就不写了，见unorder封装的后三分之一部分和c++11开头
//////直接从右值引用和移动语义部分开始写示范代码，用一个自制的string类来示范
//
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<assert.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//
//namespace LDW
//{
//    class string
//    {
//    public:
//        // 迭代器类型定义
//        typedef char* iterator;
//        typedef const char* const_iterator;
//
//        // 迭代器相关函数
//        iterator begin() { return _str; }
//        iterator end() { return _str + _size; }
//        const_iterator begin() const { return _str; }
//        const_iterator end() const { return _str + _size; }
//
//        // 构造函数
//        string(const char* str = "")
//            : _size(strlen(str)), _capacity(_size) 
//        {
//            std::cout << "string(char* str)-构造" << std::endl;
//            _str = new char[_capacity + 1];
//            strcpy(_str, str);
//        }
//
//        // 交换函数
//        void swap(string& s) 
//        {
//            std::swap(_str, s._str);
//            std::swap(_size, s._size);
//            std::swap(_capacity, s._capacity);
//        }
//
//        // 拷贝构造函数
//        string(const string& s) : _str(nullptr) 
//        {
//            std::cout << "string(const string& s) -- 拷贝构造" << std::endl;
//            reserve(s._capacity);
//            for (auto ch : s) {
//                push_back(ch);
//            }
//        }
//
//        // 移动构造函数
//        string(string&& s) 
//        {
//            std::cout << "string(string&& s) -- 移动构造" << std::endl;
//            swap(s);
//        }
//
//        // 拷贝赋值运算符
//        string& operator=(const string& s) 
//        {
//            std::cout << "string& operator=(const string& s) -- 拷贝赋值" << std::endl;
//            if (this != &s) {
//                _str[0] = '\0';
//                _size = 0;
//                reserve(s._capacity);
//                for (auto ch : s) {
//                    push_back(ch);
//                }
//            }
//            return *this;
//        }
//
//        // 移动赋值运算符
//        string& operator=(string&& s) 
//        {
//            std::cout << "string& operator=(string&& s) -- 移动赋值" << std::endl;
//            swap(s);
//            return *this;
//        }
//
//        // 析构函数
//        ~string() 
//        {
//            std::cout << "~string() -- 析构" << std::endl;
//            delete[] _str;
//            _str = nullptr;
//        }
//
//        // 下标运算符
//        char& operator[](size_t pos) 
//        {
//            assert(pos < _size);
//            return _str[pos];
//        }
//
//        // 容量相关函数
//        void reserve(size_t n) 
//        {
//            if (n > _capacity) {
//                char* tmp = new char[n + 1];
//                if (_str) {
//                    strcpy(tmp, _str);
//                    delete[] _str;
//                }
//                _str = tmp;
//                _capacity = n;
//            }
//        }
//
//        // 添加字符
//        void push_back(char ch) 
//        {
//            if (_size >= _capacity) {
//                size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//                reserve(newcapacity);
//            }
//            _str[_size] = ch;
//            ++_size;
//            _str[_size] = '\0';
//        }
//
//        // 运算符重载
//        string& operator+=(char ch) 
//        {
//            push_back(ch);
//            return *this;
//        }
//
//        // 工具函数
//        const char* c_str() const { return _str; }
//        size_t size() const { return _size; }
//
//    private:
//        char* _str = nullptr;      // 字符串数据
//        size_t _size = 0;         // 字符串长度
//        size_t _capacity = 0;     // 容量
//    };
//
//}
//
//int main() 
//{
//    LDW::string s1("xxxxx");
//    // 拷贝构造
//    LDW::string s2 = s1;
//    // 构造+移动构造，优化后直接构造
//    LDW::string s3 = LDW::string("yyyyy");
//    // 移动构造
//    LDW::string s4 = std::move(s1);
//
//    std::cout << "******************************" << std::endl;
//    return 0;
//  }

//移动构造移动赋值，右值引用移动语义部分见C++11第一课2小时部分，主要是理解性质和原理

////lambda部分
//int main()
//{
//	auto add1 = [](int x, int y)->int {return x + y; };
//	cout << add1(1, 2) << endl;
//
//	// 1、捕捉为空也不能省略
//	// 2、参数为空可以省略
//	// 3、返回值可以省略，可以通过返回对象⾃动推导
//	// 4、函数体不能省略
//
//	auto func1 = [] {cout << "hello, world!" << endl; return 10; };
//	int x = func1();
//	cout << x << endl;
//
//	return 0;
//}

/////////////////////////////////////////////////////////////
//第二堂C++11


