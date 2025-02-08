#define _CRT_SECURE_NO_WARNINGS

#include"string.h"

namespace LDW // �����������ռ䣬��ֹ�ͱ�׼���е� string ������ͻ
{
    const size_t string::npos = -1;

    //// ��Ԫ���������� << �� >> ��֧�ֱ�׼���������
    //ostream& string::operator<<(ostream& _cout, const string& s)
    //{

    //}
    //istream& string::operator>>(istream& _cin, string& s)
    //{

    //}
    
    string::string(const char* str) // ���캯����Ĭ�Ϲ�����ַ��� "",ȱʡд��h�����Ǳ�
        :_size(strlen(str))
    {
        _capacity = _size;
        _str = new char[_capacity + 1];
        strcpy(_str, str);
    }

    string::string(const string& s) // �������캯��
        :_size(s._size)
        ,_capacity(s._capacity)
        ,_str(new char[s._capacity + 1])
    {
        strcpy(_str, s._str);
    }

    string& string::operator=(const string& s) // ��ֵ���������
    {

    }

    string::~string() // �����������ͷŶ�̬������ڴ�
    {
        delete[] _str;
        _str = nullptr;// ��Ȼ����֮���Ѿ����ʲ���_str��,���ǻ����Ͻ���д�ȽϺ�
        _size = 0;
        _capacity = 0;
    }
    //////////////////////////////////////////////////////////////

    // ��������غ���
    string::iterator string::begin() // ����ָ���ַ������ַ��ĵ�����
    {
        return _str;
    }

    string::iterator string::end()  // ����ָ���ַ���ĩβ��\0��֮��ĵ�����
    {
        return _str + _size;
    }
    /////////////////////////////////////////////////////////////

    // �޸��ַ����ĳ�Ա����
    void string::push_back(char c) // β��,���ַ���ĩβ����ַ� c
    {
        if (_size == _capacity)// _size == _capacity������,��ѭ2����1.5���ݶ���,������ϰ��
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        }
        _str[_size++] = c;// _size�Ǹ���,���±���ʱ�����һ���ַ�����һ��λ��,��\0λ��,����ֱ�����
        _str[_size] = '\0';// ԭ����\0������,����\0��β
    }

    string& string::operator+=(char c) // ���� += �������׷���ַ� c
    {
        push_back(c);
        return *this;
    }

    void string::append(const char* str) // ׷�� C ����ַ���
    {
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        strcpy(_str + _size, str);
        _size += len;
    }

    string& string::operator+=(const char* str) // ���� += �������׷�� C ����ַ���
    {
        append(str);
        return *this;
    }

    void string::clear() // ����ַ�������
    {
        _size = 0;
        _str[0] = '\0';
    }

    void string::swap(string& s) // ������ǰ�ַ����� s ������
    {

    }

    const char* string::c_str() const // ��ȡ std::string �ڲ��� C ����ַ�����char* ���ͣ����� \0 ��β��
    {
        return _str;// �ڲ���char*�������\0��β��c�������
    }
    /////////////////////////////////////////////////////////////

    // ����������س�Ա����
    size_t string::size() const// ���ص�ǰ�ַ�������
    {

    }

    size_t string::capacity() const // ���ص�ǰ�ַ�������
    {

    }

    bool string::empty() const // �ж��ַ����Ƿ�Ϊ��
    {

    }

    void string::resize(size_t n, char c) // �����ַ���size��С������Ĳ����� c ���
    {

    }

    void string::reserve(size_t n) // Ԥ������ n ���ַ��Ĵ洢�ռ䣬����Ƶ������, ʵ����==����
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

    // ����Ԫ��
    char& string::operator[](size_t index) // ���� [] ���������ȡ index λ�õ��ַ�
    {

    }
    const char& string::operator[](size_t index) const // ���� index λ�õ��ַ��������汾��
    {

    }

    /////////////////////////////////////////////////////////////

    // ��ϵ��������أ������ַ����Ƚϣ�
    bool string::operator<(const string& s) // С�������
    {

    }
    bool string::operator<=(const string& s) // С�ڵ��������
    {

    }
    bool string::operator>(const string& s) // ���������
    {

    }
    bool string::operator>=(const string& s) // ���ڵ��������
    {

    }
    bool string::operator==(const string& s) // ���������
    {

    }
    bool string::operator!=(const string& s) // �����������
    {

    }

    /////////////////////////////////////////////////////////////

    // ���Ҳ���
    size_t string::find(char c, size_t pos = 0) const // �����ַ� c ��һ�γ��ֵ�λ��
    {

    }
    size_t string::find(const char* s, size_t pos = 0) const // �����Ӵ� s ��һ�γ��ֵ�λ��
    {

    }

    /////////////////////////////////////////////////////////////

    // �������
    string& string::insert(size_t pos, size_t n, char c) // �� pos λ�ò���n���ַ� c
    {
        assert(pos <= _size);

        if (_size + n > _capacity)
        {
            reserve(_size + n);
        }
        //Ų������
        size_t end = _size;// endָ��\0��λ��
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

    string& string::insert(size_t pos, const char* str) // �� pos λ�ò����ַ��� str
    {

    }
    /////////////////////////////////////////////////////////////

    // ɾ������
    string& string::erase(size_t pos, size_t len) // �� pos λ��ɾ�� len ���ַ�,�����ظ�Ԫ�ص���һ��λ��
    {

    }
}