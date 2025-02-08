#define _CRT_SECURE_NO_WARNINGS   // 禁用CRT安全函数警告

#include "string.h"              // 包含自定义的字符串头文件（可能包含类声明等）

namespace LDW                   // 定义命名空间LDW，避免与其他代码冲突
{

    // 构造函数：通过C风格字符串构造string对象
    string::string(const char* str) // 参数str为输入的C字符串
        :_size(strlen(str))         // C++构造函数初始化尽量走初始化列表,只利用_size走初始化列表,其余的走函数体,避免反复使用strlen
    {
        _capacity = _size;         // 将容量设置为当前字符串的长度
        _str = new char[_capacity + 1];  // 动态分配内存，预留一个字符空间存储结束符'\0'
        strcpy(_str, str);         // strcpy会拷贝\0
    }

    // 拷贝构造函数：通过已有string对象构造新对象
    string::string(const string& s) // 参数s为要拷贝的字符串对象
    {
        _size = s._size;           // 拷贝字符串长度
        _capacity = s._capacity;   // 拷贝容量
        _str = new char[_capacity + 1];  // 分配新的内存空间
        strcpy(_str, s._str);      // 将源字符串内容复制到新分配的内存中
    }

    // 赋值运算符重载：实现字符串对象之间的赋值操作
    string& string::operator=(const string& s)
    {
        if (this != &s)            // 检查是否自赋值，如果不是，则执行复制操作
        {
            char* temp = new char[s._capacity + 1];  // 为新字符串分配内存
            strcpy(temp, s._str);  // 将s的字符串内容复制到临时内存中
            delete[] _str;         // 释放原来的内存，避免内存泄漏
            _str = temp;           // 将_str指针指向新分配的内存
            _size = s._size;       // 更新字符串长度
            _capacity = s._capacity;  // 更新容量
        }
        return *this;              // 返回当前对象的引用，支持链式赋值
    }

    // 析构函数：释放动态分配的内存
    string::~string()
    {
        delete[] _str;             // 释放字符串内存
    }

    // 返回指向字符串首字符的迭代器
    string::iterator string::begin()
    {
        return _str;               // 迭代器即为内部的char指针，指向字符串开始位置
    }

    // 返回指向字符串末尾下一位置的迭代器
    string::iterator string::end()
    {
        return _str + _size;       // 返回指针指向字符串尾部后的位置（不含'\0'）
    }

    // 尾插：在字符串末尾追加一个字符
    void string::push_back(char c)
    {
        if (_size == _capacity)    // 如果当前大小已达到容量上限，则需要扩容
        {
            reserve(_capacity == 0 ? 2 : _capacity * 2);  // 如果容量为0，则设为2，否则容量翻倍
        }
        _str[_size++] = c;         // 在当前位置插入字符，并将_size递增
        _str[_size] = '\0';        // 在新末尾位置添加结束符'\0'
    }

    // 重载 += 运算符：追加一个字符到字符串末尾
    string& string::operator+=(char c)
    {
        push_back(c);              // 调用push_back函数添加字符
        return *this;              // 返回当前对象的引用
    }

    // 追加函数：在字符串末尾追加一个C风格字符串
    void string::append(const char* str)
    {
        size_t len = strlen(str);
        if (_size + len > _capacity)// 原本字符数+插入字符数>容量则扩容
        {
            reserve(_size + len);// 需要多少开多少.有人会用*2倍的开辟法,若>*2倍则用_size + len,其实都还行
        }
        strcpy(_str + _size, str); // 从当前字符串末尾开始复制新字符串（包括'\0'）
        _size += len;              // 更新字符串长度
    }

    // 重载 += 运算符：追加一个C风格字符串到当前字符串末尾
    string& string::operator+=(const char* str)
    {
        append(str);               // 调用append函数进行追加操作
        return *this;              // 返回当前对象的引用
    }

    // 清空字符串：将字符串内容置为空
    void string::clear()
    {
        _size = 0;                 // 重置字符串长度为0
        _str[0] = '\0';            // 将第一个字符设为结束符，表示空字符串
    }

    // 交换函数：交换当前字符串和另一字符串的内部数据
    void string::swap(string& s)
    {
        std::swap(_str, s._str);       // 交换内部字符指针
        std::swap(_size, s._size);     // 交换字符串长度
        std::swap(_capacity, s._capacity);  // 交换容量
    }

    // 返回C风格字符串指针，用于兼容C接口
    const char* string::c_str() const
    {
        return _str;               // 返回内部存储的字符数组
    }

    // 返回字符串的长度
    size_t string::size() const
    {
        return _size;              // 返回当前存储的字符数（不包含'\0'）
    }

    // 返回字符串的容量
    size_t string::capacity() const
    {
        return _capacity;          // 返回当前分配的内存容量
    }

    // 判断字符串是否为空
    bool string::empty() const
    {
        return _size == 0;         // 若长度为0，则字符串为空
    }

    // 改变字符串大小：若n小于当前大小则截断，大于则填充字符c
    void string::resize(size_t n, char c)
    {
        if (n < _size)             // 如果目标大小小于当前大小
        {
            _size = n;             // 更新大小为n
            _str[n] = '\0';        // 在位置n添加结束符，截断字符串
        }
        else                       // 如果目标大小大于当前大小
        {
            if (n > _capacity)     // 如果n大于当前容量
            {
                reserve(n);        // 扩容到n
            }
            memset(_str + _size, c, n - _size);  // 用字符c填充从_size到n的区域
            _size = n;             // 更新大小为n
            _str[_size] = '\0';    // 在新末尾添加结束符
        }
    }

    // 预留内存空间：若n大于当前容量则重新分配内存，否则不做任何操作
    void string::reserve(size_t n)
    {
        if (n > _capacity)         // 只有当请求的容量大于当前容量时reserve才扩容,reserve不会缩容,也不改变原_size
        {
            char* temp = new char[n + 1];  // +1 预留\0
            strcpy(temp, _str);    // 将当前字符串复制到新内存中
            delete[] _str;         // 释放旧内存
            _str = temp;           // 更新内部字符指针
            _capacity = n;         // 更新容量
        }
    }

    // 重载下标运算符（可修改版本）：返回指定位置的字符引用
    char& string::operator[](size_t index)
    {
        return _str[index];        // 直接返回字符数组中对应位置的元素引用
    }

    // 重载下标运算符（常量版本）：返回指定位置的字符常量引用
    const char& string::operator[](size_t index) const
    {
        return _str[index];        // 返回对应位置的字符，但不允许修改
    }

    // 重载小于运算符：按字典序比较两个字符串
    bool string::operator<(const string& s)
    {
        return strcmp(_str, s._str) < 0;  // 若当前字符串小于s则返回true
    }

    // 重载小于等于运算符：按字典序比较两个字符串
    bool string::operator<=(const string& s)
    {
        return strcmp(_str, s._str) <= 0; // 若当前字符串小于或等于s则返回true
    }

    // 重载大于运算符：按字典序比较两个字符串
    bool string::operator>(const string& s)
    {
        return strcmp(_str, s._str) > 0;  // 若当前字符串大于s则返回true
    }

    // 重载大于等于运算符：按字典序比较两个字符串
    bool string::operator>=(const string& s)
    {
        return strcmp(_str, s._str) >= 0; // 若当前字符串大于或等于s则返回true
    }

    // 重载等于运算符：判断两个字符串内容是否相等
    bool string::operator==(const string& s)
    {
        return strcmp(_str, s._str) == 0; // 如果两个字符串完全相同则返回true
    }

    // 重载不等于运算符：判断两个字符串内容是否不相等
    bool string::operator!=(const string& s)
    {
        return strcmp(_str, s._str) != 0; // 如果两个字符串存在差异则返回true
    }

    // 查找字符：在字符串中从pos位置开始查找字符c的第一次出现位置
    size_t string::find(char c, size_t pos) const
    {
        for (size_t i = pos; i < _size; ++i)  // 从pos开始遍历到字符串末尾
        {
            if (_str[i] == c) return i; // 若找到字符c则返回其索引
        }
        return -1;                // 如果未找到，返回-1（注意：-1转换为size_t通常为极大值）
    }

    // 查找子字符串：在字符串中从pos位置开始查找第一次出现子字符串s的位置
    size_t string::find(const char* s, size_t pos) const
    {
        const char* found = strstr(_str + pos, s);  // 使用strstr查找子字符串
        return found ? found - _str : -1;  // 如果找到，返回索引；否则返回-1
    }

    // 插入单个字符：在指定位置pos插入字符c
    string& string::insert(size_t pos, char c)
    {
        if (pos > _size) pos = _size;  // 如果插入位置超过字符串长度，则将位置调整为末尾
        resize(_size + 1);         // 调整字符串大小，为新字符腾出空间
        memmove(_str + pos + 1, _str + pos, _size - pos);  // 将pos位置后的字符后移一个位置
        _str[pos] = c;             // 在pos位置插入字符c
        return *this;              // 返回当前字符串对象的引用
    }

    // 插入C风格字符串：在指定位置pos插入字符串str
    string& string::insert(size_t pos, const char* str)
    {
        size_t len = strlen(str);  // 获取要插入字符串的长度
        if (pos > _size) pos = _size;  // 如果插入位置超过当前长度，则调整为末尾
        resize(_size + len);       // 调整字符串大小，为插入的字符腾出空间
        memmove(_str + pos + len, _str + pos, _size - pos - len);  // 将pos位置后的字符整体后移，为新内容腾出位置
        memcpy(_str + pos, str, len);  // 将新字符串复制到pos位置
        return *this;              // 返回当前对象的引用
    }

    // 删除操作：删除从pos位置开始的len个字符，并返回删除位置的下一个位置
    string& string::erase(size_t pos, size_t len)
    {
        assert(pos < _size);  // 断言pos不可超出范围
        if (pos + len > _size) len = _size - pos;  // 如果删除长度超出剩余字符，则调整len为可删除的字符数
        memmove(_str + pos, _str + pos + len, _size - pos - len + 1);  // 将删除区域后的字符前移覆盖删除区域，同时包括'\0'
        _size -= len;              // 更新字符串长度
        return *this;         // 返回指向删除起始位置的迭代器
    }

    // 重载输出流运算符：将字符串内容输出到输出流中
    std::ostream& operator<<(std::ostream& _cout, const string& s)
    {
        _cout << s._str;           // 将字符串内容插入到输出流
        return _cout;              // 返回输出流以支持链式输出
    }

    // 重载输入流运算符：从输入流中读取字符串，并赋值给string对象
    std::istream& operator>>(std::istream& _cin, string& s)
    {
        char buffer[1000];         // 定义一个缓冲区存储输入的字符（假设最大输入长度不超过999）
        _cin >> buffer;            // 从输入流中读取一个单词到缓冲区
        s = buffer;                // 使用赋值运算符将缓冲区内容赋给string对象
        return _cin;               // 返回输入流以支持链式输入
    }
}
