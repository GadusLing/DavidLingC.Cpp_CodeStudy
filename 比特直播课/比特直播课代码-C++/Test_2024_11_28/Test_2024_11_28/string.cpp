#define _CRT_SECURE_NO_WARNINGS

#include"string.h"

namespace LDW // �����������ռ䣬��ֹ�ͱ�׼���е� string ������ͻ
{
    const size_t string::npos = -1;

    // ��Ԫ���������� << �� >> ��֧�ֱ�׼���������
    ostream& operator<<(ostream& _cout, const string& s)
    {
        for (auto ch : s)
        {
            cout << ch;
        }
    }
    istream& operator>>(istream& _cin, string& s)
    {

    }
    
    // ���캯����Ĭ�Ϲ�����ַ��� "",ȱʡд��h�����Ǳ�
    string::string(const char* str) 
        :_size(strlen(str))
    {
        _capacity = _size;
        _str = new char[_capacity + 1];
        strcpy(_str, str);
    }

    // ��������
    string::string(const string& s)
        :_size(s._size)
        ,_capacity(s._capacity)
        ,_str(new char[s._capacity + 1])
    {
        strcpy(_str, s._str);
    }

    // ��ֵ���������, ��һ��string�滻ԭ�����ַ���
    string& string::operator=(const string& s) 
    {
        if (this != &s)
        {
            string temp(s);
            this->swap(temp);
        }
        return *this;
    }

    // �����������ͷŶ�̬������ڴ�
    string::~string() 
    {
        delete[] _str;
        _str = nullptr;// ��Ȼ����֮���Ѿ����ʲ���_str��,���ǻ����Ͻ���д�ȽϺ�
        _size = 0;
        _capacity = 0;
    }


    // ��������غ���
    string::iterator string::begin() // ����ָ���ַ������ַ��ĵ�����
    {
        return _str;
    }

    string::iterator string::end()  // ����ָ���ַ���ĩβ��\0��֮��ĵ�����
    {
        return _str + _size;
    }


    // �޸��ַ����ĳ�Ա����
    // β��,���ַ���ĩβ����ַ� c
    void string::push_back(char c) 
    {
        if (_size == _capacity)// _size == _capacity������,��ѭ2����1.5���ݶ���,������ϰ��
        {
            reserve(_capacity == 0 ? 4 : _capacity * 2);
        }
        _str[_size++] = c;// _size�Ǹ���,���±���ʱ�����һ���ַ�����һ��λ��,��\0λ��,����ֱ�����
        _str[_size] = '\0';// ԭ����\0������,����\0��β
    }

    // ���� += �������׷���ַ� c
    string& string::operator+=(char c) 
    {
        push_back(c);
        return *this;
    }
    // ׷�� C ����ַ���
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
    // ���� += �������׷�� C ����ַ���
    string& string::operator+=(const char* str)
    {
        append(str);
        return *this;
    }
    // ����ַ�������
    void string::clear()
    {
        _size = 0;
        _str[0] = '\0';
    }
    // ������ǰ�ַ����� s ������
    void string::swap(string& s) 
    {

    }
    // ��ȡ std::string �ڲ��� C ����ַ�����char* ���ͣ����� \0 ��β��
    const char* string::c_str() const
    {
        return _str;// �ڲ���char*�������\0��β��c�������
    }


    // ����������س�Ա����
    // ���ص�ǰ�ַ�������
    size_t string::size() const
    {

    }
    // ���ص�ǰ�ַ�������
    size_t string::capacity() const
    {

    }
    // �ж��ַ����Ƿ�Ϊ��
    bool string::empty() const
    {

    }
    // �����ַ���size��С������Ĳ����� c ���
    void string::resize(size_t n, char c)
    {

    }
    // Ԥ������ n ���ַ��Ĵ洢�ռ䣬����Ƶ������, ʵ����==����
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
    }


    // ����Ԫ��
    char& string::operator[](size_t index) // ���� [] ���������ȡ index λ�õ��ַ�
    {

    }
    const char& string::operator[](size_t index) const // ���� index λ�õ��ַ��������汾��
    {

    }


    // ��ϵ��������أ������ַ����Ƚϣ�
    bool string::operator<(const string& s)
    {

    }
    bool string::operator<=(const string& s)
    {

    }
    bool string::operator>(const string& s)
    {

    }
    bool string::operator>=(const string& s)
    {

    }
    bool string::operator==(const string& s)
    {

    }
    bool string::operator!=(const string& s)
    {

    }


    // ���Ҳ���
    size_t string::find(char c, size_t pos = 0) const // �����ַ� c ��һ�γ��ֵ�λ��
    {

    }
    size_t string::find(const char* s, size_t pos = 0) const // �����Ӵ� s ��һ�γ��ֵ�λ��
    {

    }


    // �������
     // �� pos λ�ò���n���ַ� c
    string& string::insert(size_t pos, size_t n, char c)
    {
        assert(pos <= _size);
        assert(n > 0);

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
        return *this;// �����������ã�֧����ʽ����
    }

    // �� pos λ�ò����ַ��� str
    string& string::insert(size_t pos, const char* str)
    {
        assert(pos <= _size);// ȷ������λ�úϷ���pos ���ܳ�����ǰ�ַ�������
        size_t n = strlen(str);// ��ȡ�������ַ����ĳ���

        //if (_size + n > _capacity)// �����ǰ�����������������ַ���������
        //{
        //    reserve(_size + n);// ��չ������ʹ���������������ַ���
        //}
        ////Ų������
        //size_t end = _size;// ����һ������ end����ʼ��Ϊ��ǰ�ַ����Ĵ�С _size��end ��ָ���ַ���ĩβ�� \0 �ַ�
        //while (end >= pos)// ��ԭ�ַ�����ĩβ��ʼ�����ν��ַ�����ƶ������ڳ��㹻�Ŀռ����������ַ�����ѭ�������� end ���ڵ��ڲ���λ�� pos��
        //{
        //    _str[end + n] = _str[end];// ���ַ� _str[end] ���Ƶ�λ�� end + n��Ҳ���ǽ��ַ��� end �� pos ֮�������Ų�� n ��λ�á�
        //    --end;// end ��ǰ�ƶ�������������һ���ַ���
        //}
        insert(pos, n, 'x');// ��һ��˼·,���������insert�ȶ����x,Ȼ���ٰ�Ҫ�����str������ȥ,��д�ö���
        for (size_t i = 0; i < n; i++)
        {
            _str[pos + i] = str[i];
        }
        _size += n;
        return *this;// �����������ã�֧����ʽ����
    }

    // ɾ������
    string& string::erase(size_t pos, size_t len) // �� pos λ��ɾ�� len ���ַ�,�����ظ�Ԫ�ص���һ��λ��
    {
        assert(pos <= _size);// ȷ������λ�úϷ���pos ���ܳ�����ǰ�ַ�������
        len = pos + len <= _size ? len : _size - pos;// len�ı߽���ൽ���һ���ַ�,������������Ҳֻ��Ѻ���ɾ�������
        for (size_t i = 0; pos + i + len < _size; i++)
        {
            _str[pos + i] = _str[pos + i + len];
        }
        _size -= len;
        return *this;
    }
}