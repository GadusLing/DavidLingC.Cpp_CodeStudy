#define _CRT_SECURE_NO_WARNINGS   // ����CRT��ȫ��������

#include "string.h"              // �����Զ�����ַ���ͷ�ļ������ܰ����������ȣ�

namespace LDW                   // ���������ռ�LDW�����������������ͻ
{

    // ���캯����ͨ��C����ַ�������string����
    string::string(const char* str) // ����strΪ�����C�ַ���
        :_size(strlen(str))         // C++���캯����ʼ�������߳�ʼ���б�,ֻ����_size�߳�ʼ���б�,������ߺ�����,���ⷴ��ʹ��strlen
    {
        _capacity = _size;         // ����������Ϊ��ǰ�ַ����ĳ���
        _str = new char[_capacity + 1];  // ��̬�����ڴ棬Ԥ��һ���ַ��ռ�洢������'\0'
        strcpy(_str, str);         // strcpy�´��\0
    }

    // �������캯����ͨ������string�������¶���
    string::string(const string& s) // ����sΪҪ�������ַ�������
    {
        _size = s._size;           // �����ַ�������
        _capacity = s._capacity;   // ��������
        _str = new char[_capacity + 1];  // �����µ��ڴ�ռ�
        strcpy(_str, s._str);      // ��Դ�ַ������ݸ��Ƶ��·�����ڴ���
    }

    // ��ֵ��������أ�ʵ���ַ�������֮��ĸ�ֵ����
    string& string::operator=(const string& s)
    {
        if (this != &s)            // ����Ƿ��Ը�ֵ��������ǣ���ִ�и��Ʋ���
        {
            char* temp = new char[s._capacity + 1];  // Ϊ���ַ��������ڴ�
            strcpy(temp, s._str);  // ��s���ַ������ݸ��Ƶ���ʱ�ڴ���
            delete[] _str;         // �ͷ�ԭ�����ڴ棬�����ڴ�й©
            _str = temp;           // ��_strָ��ָ���·�����ڴ�
            _size = s._size;       // �����ַ�������
            _capacity = s._capacity;  // ��������
        }
        return *this;              // ���ص�ǰ��������ã�֧����ʽ��ֵ
    }

    // �����������ͷŶ�̬������ڴ�
    string::~string()
    {
        delete[] _str;             // �ͷ��ַ����ڴ�
    }

    // ����ָ���ַ������ַ��ĵ�����
    string::iterator string::begin()
    {
        return _str;               // ��������Ϊ�ڲ���charָ�룬ָ���ַ�����ʼλ��
    }

    // ����ָ���ַ���ĩβ��һλ�õĵ�����
    string::iterator string::end()
    {
        return _str + _size;       // ����ָ��ָ���ַ���β�����λ�ã�����'\0'��
    }

    // β�壺���ַ���ĩβ׷��һ���ַ�
    void string::push_back(char c)
    {
        if (_size == _capacity)    // �����ǰ��С�Ѵﵽ�������ޣ�����Ҫ����
        {
            reserve(_capacity == 0 ? 2 : _capacity * 2);  // �������Ϊ0������Ϊ2��������������
        }
        _str[_size++] = c;         // �ڵ�ǰλ�ò����ַ�������_size����
        _str[_size] = '\0';        // ����ĩβλ����ӽ�����'\0'
    }

    // ���� += �������׷��һ���ַ����ַ���ĩβ
    string& string::operator+=(char c)
    {
        push_back(c);              // ����push_back��������ַ�
        return *this;              // ���ص�ǰ���������
    }

    // ׷�Ӻ��������ַ���ĩβ׷��һ��C����ַ���
    void string::append(const char* str)
    {
        size_t len = strlen(str);
        if (_size + len > _capacity)// ԭ���ַ���+�����ַ���>����������
        {
            reserve(_size + len);// ��Ҫ���ٿ�����.���˻���*2���Ŀ��ٷ�,��>*2������_size + len,��ʵ������
        }
        strcpy(_str + _size, str); // �ӵ�ǰ�ַ���ĩβ��ʼ�������ַ���������'\0'��
        _size += len;              // �����ַ�������
    }

    // ���� += �������׷��һ��C����ַ�������ǰ�ַ���ĩβ
    string& string::operator+=(const char* str)
    {
        append(str);               // ����append��������׷�Ӳ���
        return *this;              // ���ص�ǰ���������
    }

    // ����ַ��������ַ���������Ϊ��
    void string::clear()
    {
        _size = 0;                 // �����ַ�������Ϊ0
        _str[0] = '\0';            // ����һ���ַ���Ϊ����������ʾ���ַ���
    }

    // ����������������ǰ�ַ�������һ�ַ������ڲ�����
    void string::swap(string& s)
    {
        std::swap(_str, s._str);       // �����ڲ��ַ�ָ��
        std::swap(_size, s._size);     // �����ַ�������
        std::swap(_capacity, s._capacity);  // ��������
    }

    // ����C����ַ���ָ�룬���ڼ���C�ӿ�
    const char* string::c_str() const
    {
        return _str;               // �����ڲ��洢���ַ�����
    }

    // �����ַ����ĳ���
    size_t string::size() const
    {
        return _size;              // ���ص�ǰ�洢���ַ�����������'\0'��
    }

    // �����ַ���������
    size_t string::capacity() const
    {
        return _capacity;          // ���ص�ǰ������ڴ�����
    }

    // �ж��ַ����Ƿ�Ϊ��
    bool string::empty() const
    {
        return _size == 0;         // ������Ϊ0�����ַ���Ϊ��
    }

    // �ı��ַ�����С����nС�ڵ�ǰ��С��ضϣ�����������ַ�c
    void string::resize(size_t n, char c)
    {
        if (n < _size)             // ���Ŀ���СС�ڵ�ǰ��С
        {
            _size = n;             // ���´�СΪn
            _str[n] = '\0';        // ��λ��n��ӽ��������ض��ַ���
        }
        else                       // ���Ŀ���С���ڵ�ǰ��С
        {
            if (n > _capacity)     // ���n���ڵ�ǰ����
            {
                reserve(n);        // ���ݵ�n
            }
            memset(_str + _size, c, n - _size);  // ���ַ�c����_size��n������
            _size = n;             // ���´�СΪn
            _str[_size] = '\0';    // ����ĩβ��ӽ�����
        }
    }

    // Ԥ���ڴ�ռ䣺��n���ڵ�ǰ���������·����ڴ棬�������κβ���
    void string::reserve(size_t n)
    {
        if (n > _capacity)         // ֻ�е�������������ڵ�ǰ����ʱreserve������,reserve��������,Ҳ���ı�ԭ_size
        {
            char* temp = new char[n + 1];  // +1 Ԥ��\0
            strcpy(temp, _str);    // ����ǰ�ַ������Ƶ����ڴ���
            delete[] _str;         // �ͷž��ڴ�
            _str = temp;           // �����ڲ��ַ�ָ��
            _capacity = n;         // ��������
        }
    }

    // �����±�����������޸İ汾��������ָ��λ�õ��ַ�����
    char& string::operator[](size_t index)
    {
        return _str[index];        // ֱ�ӷ����ַ������ж�Ӧλ�õ�Ԫ������
    }

    // �����±�������������汾��������ָ��λ�õ��ַ���������
    const char& string::operator[](size_t index) const
    {
        return _str[index];        // ���ض�Ӧλ�õ��ַ������������޸�
    }

    // ����С������������ֵ���Ƚ������ַ���
    bool string::operator<(const string& s)
    {
        return strcmp(_str, s._str) < 0;  // ����ǰ�ַ���С��s�򷵻�true
    }

    // ����С�ڵ�������������ֵ���Ƚ������ַ���
    bool string::operator<=(const string& s)
    {
        return strcmp(_str, s._str) <= 0; // ����ǰ�ַ���С�ڻ����s�򷵻�true
    }

    // ���ش�������������ֵ���Ƚ������ַ���
    bool string::operator>(const string& s)
    {
        return strcmp(_str, s._str) > 0;  // ����ǰ�ַ�������s�򷵻�true
    }

    // ���ش��ڵ�������������ֵ���Ƚ������ַ���
    bool string::operator>=(const string& s)
    {
        return strcmp(_str, s._str) >= 0; // ����ǰ�ַ������ڻ����s�򷵻�true
    }

    // ���ص�����������ж������ַ��������Ƿ����
    bool string::operator==(const string& s)
    {
        return strcmp(_str, s._str) == 0; // ��������ַ�����ȫ��ͬ�򷵻�true
    }

    // ���ز�������������ж������ַ��������Ƿ����
    bool string::operator!=(const string& s)
    {
        return strcmp(_str, s._str) != 0; // ��������ַ������ڲ����򷵻�true
    }

    // �����ַ������ַ����д�posλ�ÿ�ʼ�����ַ�c�ĵ�һ�γ���λ��
    size_t string::find(char c, size_t pos) const
    {
        for (size_t i = pos; i < _size; ++i)  // ��pos��ʼ�������ַ���ĩβ
        {
            if (_str[i] == c) return i; // ���ҵ��ַ�c�򷵻�������
        }
        return -1;                // ���δ�ҵ�������-1��ע�⣺-1ת��Ϊsize_tͨ��Ϊ����ֵ��
    }

    // �������ַ��������ַ����д�posλ�ÿ�ʼ���ҵ�һ�γ������ַ���s��λ��
    size_t string::find(const char* s, size_t pos) const
    {
        const char* found = strstr(_str + pos, s);  // ʹ��strstr�������ַ���
        return found ? found - _str : -1;  // ����ҵ����������������򷵻�-1
    }

    // ���뵥���ַ�����ָ��λ��pos�����ַ�c
    string& string::insert(size_t pos, char c)
    {
        if (pos > _size) pos = _size;  // �������λ�ó����ַ������ȣ���λ�õ���Ϊĩβ
        resize(_size + 1);         // �����ַ�����С��Ϊ���ַ��ڳ��ռ�
        memmove(_str + pos + 1, _str + pos, _size - pos);  // ��posλ�ú���ַ�����һ��λ��
        _str[pos] = c;             // ��posλ�ò����ַ�c
        return *this;              // ���ص�ǰ�ַ������������
    }

    // ����C����ַ�������ָ��λ��pos�����ַ���str
    string& string::insert(size_t pos, const char* str)
    {
        size_t len = strlen(str);  // ��ȡҪ�����ַ����ĳ���
        if (pos > _size) pos = _size;  // �������λ�ó�����ǰ���ȣ������Ϊĩβ
        resize(_size + len);       // �����ַ�����С��Ϊ������ַ��ڳ��ռ�
        memmove(_str + pos + len, _str + pos, _size - pos - len);  // ��posλ�ú���ַ�������ƣ�Ϊ�������ڳ�λ��
        memcpy(_str + pos, str, len);  // �����ַ������Ƶ�posλ��
        return *this;              // ���ص�ǰ���������
    }

    // ɾ��������ɾ����posλ�ÿ�ʼ��len���ַ���������ɾ��λ�õ���һ��λ��
    string& string::erase(size_t pos, size_t len)
    {
        assert(pos < _size);  // ����pos���ɳ�����Χ
        if (pos + len > _size) len = _size - pos;  // ���ɾ�����ȳ���ʣ���ַ��������lenΪ��ɾ�����ַ���
        memmove(_str + pos, _str + pos + len, _size - pos - len + 1);  // ��ɾ���������ַ�ǰ�Ƹ���ɾ������ͬʱ����'\0'
        _size -= len;              // �����ַ�������
        return *this;         // ����ָ��ɾ����ʼλ�õĵ�����
    }

    // �������������������ַ�������������������
    std::ostream& operator<<(std::ostream& _cout, const string& s)
    {
        _cout << s._str;           // ���ַ������ݲ��뵽�����
        return _cout;              // �����������֧����ʽ���
    }

    // ��������������������������ж�ȡ�ַ���������ֵ��string����
    std::istream& operator>>(std::istream& _cin, string& s)
    {
        char buffer[1000];         // ����һ���������洢������ַ�������������볤�Ȳ�����999��
        _cin >> buffer;            // ���������ж�ȡһ�����ʵ�������
        s = buffer;                // ʹ�ø�ֵ����������������ݸ���string����
        return _cin;               // ������������֧����ʽ����
    }
}
