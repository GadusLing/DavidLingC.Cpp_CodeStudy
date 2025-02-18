#define _CRT_SECURE_NO_WARNINGS

#include"string.h"

namespace LDW // 这里用命名空间，防止和标准库中的 string 产生冲突
{
    const size_t string::npos = -1;

    // 友元函数，重载 << 和 >> 以支持标准输入输出流
    ostream& operator<<(ostream& _cout, const string& s)
    {
        for (auto ch : s)
        {
            _cout << ch;
        }
        return _cout;
    }
    istream& operator>>(istream& _cin, string& s)
    {
        //char ch;
        //_cin >> ch; // 这样获取不到空格和\n
        s.clear();// 调用 string 类的 clear() 方法清空 s 字符串，确保每次读取之前字符串是空的
        char buff[1024];
        int i = 0;

        char ch = _cin.get();// 要这样获取.get() 方法从输入流 _cin 中读取一个字符并存储在 ch 变量中
        while (ch != ' ' && ch != '\n' && _cin)// 从输入流中读取字符，直到遇到空格或换行符为止
        {
            //s += ch;// 当前读取的字符 ch 添加到字符串 s 的末尾
            //_cin >> ch;
            buff[i++] = ch;
            if (i == 1023)
            {
                buff[1023] = '\0';
                s += buff;
                i = 0;
            }
            ch = _cin.get();// 再次调用 get() 读取下一个字符并赋值给 ch，继续判断是否为空格或换行符
        }
        if (i > 0)
        {
            buff[i] = '\0';
            s += buff;
        }
        return _cin;
    }
    
    // 构造函数，默认构造空字符串 "",缺省写在h声明那边
    string::string(const char* str) 
        :_size(strlen(str))
    {
        _capacity = _size;
        _str = new char[_capacity + 1];
        strcpy(_str, str);
    }

    // 拷贝构造
    string::string(const string& s)
        //    :_size(s._size)
        //    ,_capacity(s._capacity)
        //    ,_str(new char[s._capacity + 1])
        //{
        //    strcpy(_str, s._str);
        //} // 传统写法
    {
        string tmp(s._str);
        swap(tmp);
    }

    // 赋值运算符重载, 用一个string替换原本的字符串
    //string& string::operator=(const string& s) 
    //{
    //    if (this != &s)
    //    {
    //        string temp(s);
    //        swap(temp);
    //    }
    //    return *this;
    //}
    string& string::operator=(string s) // 最现代的写法,这里用值传递
    {
        swap(s);
        return *this;
    }


    // 析构函数，释放动态分配的内存
    string::~string() 
    {
        delete[] _str;
        _str = nullptr;// 虽然析构之后已经访问不到_str了,但是还是严谨的写比较好
        _size = 0;
        _capacity = 0;
    }

    // 迭代器相关函数
    string::iterator string::begin() // 返回指向字符串首字符的迭代器
    {
        return _str;
    }

    string::iterator string::end()  // 返回指向字符串末尾（\0）之后的迭代器
    {
        return _str + _size;
    }

    string::const_iterator string::begin() const // 返回指向字符串首字符的迭代器
    {
        return _str;
    }

    string::const_iterator string::end() const // 返回指向字符串末尾（\0）之后的迭代器
    {
        return _str + _size;
    }


    // 修改字符串的成员函数
    // 尾插,在字符串末尾添加字符 c
    void string::push_back(char c) 
    {
        if (_size == _capacity)// _size == _capacity则扩容,遵循2倍或1.5扩容都可,看个人习惯
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        }
        _str[_size++] = c;// _size是个数,做下标数时是最后一个字符的下一个位置,即\0位置,所以直接添加
        _str[_size] = '\0';// 原本的\0被盖了,补个\0收尾
    }

    // 重载 += 运算符，追加字符 c
    string& string::operator+=(char c) 
    {
        push_back(c);
        return *this;
    }
    // 追加 C 风格字符串
    void string::append(const char* str)
    {
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        strcpy(_str + _size, str);
        _size += len;
    }
    // 重载 += 运算符，追加 C 风格字符串
    string& string::operator+=(const char* str)
    {
        append(str);
        return *this;
    }
    // 清空字符串内容
    void string::clear()
    {
        _size = 0;
        _str[0] = '\0';
    }
    // 交换当前字符串与 s 的内容
    void string::swap(string& s)
    {
        std::swap(_str, s._str);
        std::swap(_size, s._size);
        std::swap(_capacity, s._capacity);
    }

    // 获取 std::string 内部的 C 风格字符串（char* 类型，包含 \0 结尾）
    const char* string::c_str() const
    {
        return _str;// 内部的char*数组就是\0结尾的c风格数组
    }

    // 容量管理相关成员函数
    // 返回当前字符串长度 这哥仨其实可以搞成内联效率更高
    size_t string::size() const
    {
        return _size;
    }
    // 返回当前字符串容量
    size_t string::capacity() const
    {
        return _capacity;
    }
    // 判断字符串是否为空
    bool string::empty() const
    {
        return _size == 0;
    }
    // 调整字符串size大小，多出的部分用 c 填充
    void string::resize(size_t n, char c)
    {
        if (n <= _size)
        {
            _str[n] = '\0';
            _size = n;
        }
        else
        {
            if (n > _capacity)
            {
                reserve(n);
            }
            memset(_str + _size, c, n - _size); // memset(起始地址, 填充字符, 填充长度)
            // (_str + _size)：从原字符串的末尾开始填充     c：用指定的字符 c 填充    (n - _size)：需要填充的字符数。
            _size = n;
            _str[_size] = '\0';
        }
    }
    // 预留至少 n 个字符的存储空间，避免频繁扩容, 实际上==扩容
    void string::reserve(size_t n)
    {
        if (n > _capacity)
        {
            char* temp = new char[n + 1];
            strcpy(temp, _str);
            delete[] _str;
            _str = temp;
            _capacity = n;
        }
        return;
    }

    // 访问元素
    char& string::operator[](size_t index) // 重载 [] 运算符，获取 index 位置的字符
    {
        assert(index < _size);
        return _str[index];
    }
    const char& string::operator[](size_t index) const // 访问 index 位置的字符（常量版本）
    {
        assert(index < _size);
        return _str[index];
    }

    // 关系运算符重载（用于字符串比较）
    bool string::operator<(const string& s)
    {
        return strcmp(_str, s._str) < 0;// 直接复用C语言库的strcmp
    }
    bool string::operator<=(const string& s)
    {
        return (*this < s) || (*this == s);
    }
    bool string::operator>(const string& s)
    {
        return !(*this <= s);
    }
    bool string::operator>=(const string& s)
    {
        return !(*this < s);
    }
    bool string::operator==(const string& s)
    {
        return strcmp(_str, s._str) == 0;// 直接复用C语言库的strcmp
    }
    bool string::operator!=(const string& s)
    {
        return !(*this == s);
    }

    // 查找操作
    size_t string::find(char c, size_t pos) const // 查找字符 c 第一次出现的位置
    {
        for (size_t i = pos; i < _size; i++)
        {
            if (_str[i] == c)
            {
                return i;
            }
        }
        return npos;
    }
    size_t string::find(const char* s, size_t pos) const // 查找子串 s 第一次出现的位置
    {
        const char* p = strstr(_str + pos, s);// 库里的strstr用的BF算法（Brute Force暴力算法）,两个串匹配,后面的串在前面的串里面匹配上了就返回对应的指针，没匹配上就返回空指针
        //实际上还有一些字符串匹配的比如BM算法，都相对成熟，真要用的时候就CV一下就完事了
        if (p == nullptr)
        {
            return npos;
        }
        else
        {
            return p - _str;// p是匹配上的位置,减去开始位置_str就得到下标
        }
    }

    // 插入操作
     // 在 pos 位置插入n个字符 c
    string& string::insert(size_t pos, size_t n, char c)
    {
        assert(pos <= _size);
        assert(n > 0);

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
        return *this;// 返回自身引用，支持链式调用
    }

    // 在 pos 位置插入字符串 str
    string& string::insert(size_t pos, const char* str)
    {
        assert(pos <= _size);// 确保插入位置合法，pos 不能超过当前字符串长度
        size_t n = strlen(str);// 获取待插入字符串的长度

        //if (_size + n > _capacity)// 如果当前容量不足以容纳新字符串，扩容
        //{
        //    reserve(_size + n);// 扩展容量，使其至少能容纳新字符串
        //}
        ////挪动数据
        //size_t end = _size;// 定义一个变量 end，初始化为当前字符串的大小 _size。end 将指向字符串末尾的 \0 字符
        //while (end >= pos)// 从原字符串的末尾开始，依次将字符向后移动，以腾出足够的空间来插入新字符串。循环条件是 end 大于等于插入位置 pos。
        //{
        //    _str[end + n] = _str[end];// 将字符 _str[end] 复制到位置 end + n，也就是将字符从 end 到 pos 之间的数据挪动 n 个位置。
        //    --end;// end 向前移动，继续处理下一个字符。
        //}
        insert(pos, n, 'x');// 换一种思路,复用上面的insert先都插成x,然后再把要插入的str覆盖上去,少写好多行
        for (size_t i = 0; i < n; i++)
        {
            _str[pos + i] = str[i];
        }
        return *this;// 返回自身引用，支持链式调用
    }

    // 删除操作
    string& string::erase(size_t pos, size_t len) // 从 pos 位置删除 len 个字符,并返回该元素的下一个位置
    {
        assert(pos <= _size);// 确保插入位置合法，pos 不能超过当前字符串长度
        if (len >= _size - pos)// 如果要删的字符个数大于等于原字符串里从pos开始剩下的字符个数,就删完就算了
        {
            _str[pos] = '\0';//从pos位置开始删,所以直接把pos位置置为\0
            _size = pos;// _size表示有效字符的下一位,也即\0处
        }
        else
        {
            size_t end = pos + len;// 有效字符最后一个
            while (end < _size)
            {

                _str[end - len] = _str[end];
                ++end;
            }
            _size -= len;
        }
        return *this;
    }
}