#define _CRT_SECURE_NO_WARNINGS

#include"string.h"

namespace LDW // 这里用命名空间，防止和标准库中的 string 产生冲突
{
    const size_t string::npos = -1;

    //// 友元函数，重载 << 和 >> 以支持标准输入输出流
    //ostream& string::operator<<(ostream& _cout, const string& s)
    //{

    //}
    //istream& string::operator>>(istream& _cin, string& s)
    //{

    //}
    
    string::string(const char* str) // 构造函数，默认构造空字符串 "",缺省写在h声明那边
        :_size(strlen(str))
    {
        _capacity = _size;
        _str = new char[_capacity + 1];
        strcpy(_str, str);
    }

    string::string(const string& s) // 拷贝构造函数
        :_size(s._size)
        ,_capacity(s._capacity)
        ,_str(new char[s._capacity + 1])
    {
        strcpy(_str, s._str);
    }

    string& string::operator=(const string& s) // 赋值运算符重载
    {

    }

    string::~string() // 析构函数，释放动态分配的内存
    {
        delete[] _str;
        _str = nullptr;// 虽然析构之后已经访问不到_str了,但是还是严谨的写比较好
        _size = 0;
        _capacity = 0;
    }
    //////////////////////////////////////////////////////////////

    // 迭代器相关函数
    string::iterator string::begin() // 返回指向字符串首字符的迭代器
    {
        return _str;
    }

    string::iterator string::end()  // 返回指向字符串末尾（\0）之后的迭代器
    {
        return _str + _size;
    }
    /////////////////////////////////////////////////////////////

    // 修改字符串的成员函数
    void string::push_back(char c) // 尾插,在字符串末尾添加字符 c
    {
        if (_size == _capacity)// _size == _capacity则扩容,遵循2倍或1.5扩容都可,看个人习惯
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        }
        _str[_size++] = c;// _size是个数,做下标数时是最后一个字符的下一个位置,即\0位置,所以直接添加
        _str[_size] = '\0';// 原本的\0被盖了,补个\0收尾
    }

    string& string::operator+=(char c) // 重载 += 运算符，追加字符 c
    {
        push_back(c);
        return *this;
    }

    void string::append(const char* str) // 追加 C 风格字符串
    {
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        strcpy(_str + _size, str);
        _size += len;
    }

    string& string::operator+=(const char* str) // 重载 += 运算符，追加 C 风格字符串
    {
        append(str);
        return *this;
    }

    void string::clear() // 清空字符串内容
    {
        _size = 0;
        _str[0] = '\0';
    }

    void string::swap(string& s) // 交换当前字符串与 s 的内容
    {

    }

    const char* string::c_str() const // 获取 std::string 内部的 C 风格字符串（char* 类型，包含 \0 结尾）
    {
        return _str;// 内部的char*数组就是\0结尾的c风格数组
    }
    /////////////////////////////////////////////////////////////

    // 容量管理相关成员函数
    size_t string::size() const// 返回当前字符串长度
    {

    }

    size_t string::capacity() const // 返回当前字符串容量
    {

    }

    bool string::empty() const // 判断字符串是否为空
    {

    }

    void string::resize(size_t n, char c) // 调整字符串size大小，多出的部分用 c 填充
    {

    }

    void string::reserve(size_t n) // 预留至少 n 个字符的存储空间，避免频繁扩容, 实际上==扩容
    {
        if (n > _capacity)
        {
            char* temp = new char[n + 1];
            strcpy(temp, _str);
            delete[] _str;
            _str = temp;
            _capacity = n;
        }
    }

    /////////////////////////////////////////////////////////////

    // 访问元素
    char& string::operator[](size_t index) // 重载 [] 运算符，获取 index 位置的字符
    {

    }
    const char& string::operator[](size_t index) const // 访问 index 位置的字符（常量版本）
    {

    }

    /////////////////////////////////////////////////////////////

    // 关系运算符重载（用于字符串比较）
    bool string::operator<(const string& s) // 小于运算符
    {

    }
    bool string::operator<=(const string& s) // 小于等于运算符
    {

    }
    bool string::operator>(const string& s) // 大于运算符
    {

    }
    bool string::operator>=(const string& s) // 大于等于运算符
    {

    }
    bool string::operator==(const string& s) // 等于运算符
    {

    }
    bool string::operator!=(const string& s) // 不等于运算符
    {

    }

    /////////////////////////////////////////////////////////////

    // 查找操作
    size_t string::find(char c, size_t pos = 0) const // 查找字符 c 第一次出现的位置
    {

    }
    size_t string::find(const char* s, size_t pos = 0) const // 查找子串 s 第一次出现的位置
    {

    }

    /////////////////////////////////////////////////////////////

    // 插入操作
    string& string::insert(size_t pos, size_t n, char c) // 在 pos 位置插入n个字符 c
    {
        assert(pos <= _size);

        if (_size + n > _capacity)
        {
            reserve(_size + n);
        }
        //挪动数据
        size_t end = _size;// end指向\0的位置
        while (end >= pos)
        {
            _str[end + n] = _str[end];
            --end;
        }
        for (size_t i = 0; i < n; i++)
        {
            _str[pos + i] = c;
        }
        _size += n;
    }

    string& string::insert(size_t pos, const char* str) // 在 pos 位置插入字符串 str
    {

    }
    /////////////////////////////////////////////////////////////

    // 删除操作
    string& string::erase(size_t pos, size_t len) // 从 pos 位置删除 len 个字符,并返回该元素的下一个位置
    {

    }
}