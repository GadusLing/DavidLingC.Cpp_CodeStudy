#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace LDWT
{
	const size_t string::npos = -1;

	string::string(size_t n, char ch)
		:_str(new char[n + 1])
		,_size(n)
		,_capacity(n)
	{
		for (size_t i = 0; i < n; i++)
		{
			_str[i] = ch;
		}
		_str[_size] = '\0';
	}

	string::string(const char* str)//ȫȱʡ
		:_size(strlen(str))//ʹ�� strlen ���㴫���ַ����ĳ��ȣ������������� '\0'�������� _size��
	{
		_capacity = _size;//��ʼ�� _capacity Ϊ _size��ȷ���㹻�Ĵ洢�ռ䡣
		_str = new char[strlen(str) + 1];//��̬�����ڴ棬��СΪ�ַ������ȼ� 1��Ϊ������ '\0' ���ռ䣩
		strcpy(_str, str);//ʹ�� strcpy ���ַ������ݴ� str ���Ƶ� _str��
	}

	//string::string(const string& s)//��������,��ͳд��
	//{
	//	_str = new char[s._capacity + 1];
	//	strcpy(_str, s._str);
	//	_size = s._size;
	//	_capacity = s._capacity;
	//}	
	
	void string::swap(string& s)//�ִ�д��
	{
		std::swap(_str, s._str);//Ҫ��std����Ϊ����˳���Ǿֲ�-ȫ�֣����Ѿֲ��Լ����Լ�����ƥ�䲻�ϣ�������Ҫ��std�����swap
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	string::string(const string& s)//��������,�ִ�д��
	{
		string tmp(s._str);
		swap(tmp);
	}

	//string& string::operator=(const string& s)//��ֵ  "="���� �����
	//{
	//	if (this != &s)//��ֹһЩ�����Լ����Լ���ֵ,�������Ͱ��Լ��Ŀռ�delete��
	//	{
	//		//�ִ�д��
	//		string tmp(s._str);
	//		swap(tmp);

	//		//��ͳд��
	//		//delete[] _str;
	//		//_str = new char[s._capacity + 1];//ʱ�̼�ס���ռ�+1��,��Ϊcapacity������\0
	//		//strcpy(_str, s._str);
	//		//_size = s._size;
	//		//_capacity = s._capacity;
	//	}
	//	return *this;
	//}	
	
	string& string::operator=(string s)//�����ĸ�ֵ�ִ�д��
	{//û����const���� ���ǲ��ô�ֵ���ε��ÿ��������������������ʱ����
		swap(s);
		return *this;
	}


	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			cout << "reserve:" << n << endl;
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size + 1 > _capacity)
		{
			//���� 
			string::reserve(_size == 0 ? 4 : _capacity * 2);
		}

		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			//����
			size_t newCapacity = 2 * _capacity;
			if (_size + len > 2 * _capacity)
			{
				newCapacity = _size + len;
			}

			reserve(newCapacity);
		}
		strcpy(_str + _size, str);
		_size += len;
	}

	string& string::operator+=(char ch)
	{
		string::push_back(ch);
		return *this;
	}

	string& string::operator+=(const char* str)
	{
		string::append(str);
		return *this;
	}

	void string::insert(size_t pos, size_t n, char ch)
	{
		assert(pos <= _size);
		assert(n > 0);
		if (_size + n > _capacity)//��鵱ǰ���� _capacity �Ƿ��㹻���ɲ������ַ������ȡ��������������Ҫ���ݡ�
		{
			//����
			size_t newCapacity = 2 * _capacity;
			if (_size + n > 2 * _capacity)
			{
				newCapacity = _size + n;
			}

			reserve(newCapacity);
		}
		//Ų������
		//int end = _size;//end ��ʼ��Ϊ�ַ��������һ���ַ����� _size��ʵ�ʴ洢Ϊ '\0' ��λ�ã���
		//while (end >= (int)pos)//ǿתΪint�Ƚ�,��������Զ�ת��Ϊsize_t�Ƚ϶�������Խ�����
		//{
		//	_str[end + n] = _str[end]; //������ end ���ַ��ƶ��� end + n ��λ�ã�Ϊ�²�����ַ��ڳ��ռ䡣
		//	--end;//end ��ǰ�ƶ���
		//}

		size_t end = _size + n;
		while (end > pos + n - 1)//��ֹԽ������
		{
			_str[end] = _str[end - n];
			--end;
		}

		for (size_t i = 0; i < n; ++i)
		{
			_str[pos + i] = ch;
		}
		_size += n;

	/*	string tmp(n, ch);
		insert(pos, tmp.c_str());*/

	}

	void string::insert(size_t pos, const char* str)
	{
		//assert(pos <= _size);

		//size_t n = strlen(str);
		//if (_size + n > _capacity)//��鵱ǰ���� _capacity �Ƿ��㹻���ɲ������ַ������ȡ��������������Ҫ���ݡ�
		//{
		//	//����
		//	size_t newCapacity = 2 * _capacity;
		//	if (_size + n > 2 * _capacity)
		//	{
		//		newCapacity = _size + n;
		//	}

		//	reserve(newCapacity);
		//}

		//size_t end = _size + n;
		//while (end > pos + n - 1)
		//{
		//	_str[end] = _str[end - n];
		//	--end;
		//}

		//for (size_t i = 0; i < n; ++i)
		//{
		//	_str[pos + i] = str[i];
		//}
		//_size += n;

		size_t n = strlen(str);
		insert(pos, n, 'x');//�������Ӧ�������ַ�
		for (size_t i = 0; i < n; ++i)//�͵���ch insertһ�����߼�,ֻ�Ƕ���һ�鸲��
		{
			_str[pos + i] = str[i];
		}
		
	}
	//����Ա����֮һ:����Ҫ���Լ��ĳ������ð�̲���,����
	void string::erase(size_t pos, size_t len)
	{
		if (len >= _size - pos)//Ҫɾ���ַ��������ڵ�����Ч�ַ�����
		{
			//ɾ����
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			size_t end = pos + len;
			while (end <= _size)
			{
				_str[end - len] = _str[end];
				++end;
			}
			_size -= len;
		}
	}

	size_t string::find(char ch, size_t pos)
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}

	size_t string::find(const char* str, size_t pos)
	{
		const char* p = strstr(_str + pos, str);
		if (p == nullptr)
		{
			return npos;
		}
		else
		{
			return p - _str; //ָ������õ���������֮������Ԫ�صĸ�����Ҳ�����±���,�������±�ķ�ʽ�����
		}
	}

	string string::substr(size_t pos, size_t len)
	{
		size_t leftlen = _size - pos;
		if (len > leftlen)
		{
			len = leftlen;
		}
		string tmp;
		tmp.reserve(len);

		for (size_t i = pos; i < pos + len; i++)//����ע����pos+lenŶ
		{
			tmp += _str[i];
		}
		return tmp;//ֵ����Ҫ�ÿ�������Ŷ,Ҫд������Ȼ�ᱨ��,��Ȼ���������»��Ż�,��Ҫע������ʵ���﷨�ϵĴ���
	}

	bool string::operator==(const string& s) const
	{
		return strcmp(_str, s._str) == 0;
	}

	bool string::operator!=(const string& s) const
	{
		return !(*this == s);
	}

	bool string::operator<(const string& s) const
	{
		return strcmp(_str, s._str) < 0;
	}

	bool string::operator<=(const string& s) const
	{
		return (*this < s || *this == s);
	}

	bool string::operator>(const string& s) const 
	{
		return !(*this <= s);
	}

	bool string::operator>=(const string& s) const
	{
		return !(*this < s);
	}

	ostream& operator<<(ostream& out, const string& s)//������,����Ϊȫ�ּǵ�
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s) //����ȡ
	{
		s.clear();

		const size_t N = 1024;
		char buff[N];//��һ�λ�����,����̴��˷ѿռ�,������Ҳ��Ӵ������ʼ����,����Ƶ������
		int i = 0;
		char ch;
		//in >> ch; //std::cin �� scanf ����Ϊ����,��Ĭ������»��Զ������ո񡢻��з��Լ������հ��ַ�,���¶�������ֹ��������ֹ����,�������ﲻ����>>
		ch = in.get();//��get��һ��һ���ַ���ȥ��,���Ծ��ܶ�����ֹ����
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}

	istream& getline(istream& in, string& s, char delim)
	{
		s.clear();

		const size_t N = 1024;
		char buff[N];
		int i = 0;
		char ch;
		ch = in.get();
		while (ch != delim)//������ֹ��ȱʡ��\n,����get��һ���ַ�һ���ַ�ȥ��,����\n�ᱻ���\��n,��ʱ�����ڿ���̨��ӡ������,������س�
			//�ͻᱻ����\n���з�
		{
			buff[i++] = ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}


	void test_string1()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		string s2;
		cout << s2.c_str() << endl;

		s1 += ' ';
		s1 += '+';
		s1 += "hello world";
		cout << s1.c_str() << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.insert(11, 3, 'x');
		cout << s1.c_str() << endl;

		s1.insert(6, 3, 'x');
		cout << s1.c_str() << endl;

		s1.insert(0, 3, 'x');
		cout << s1.c_str() << endl;

		string s2("hello world");
		cout << s2.c_str() << endl;

		s2.insert(11, "yyy");
		cout << s2.c_str() << endl;

		s2.insert(6, "yyy");
		cout << s2.c_str() << endl;

		s2.insert(0, "yyy");
		cout << s2.c_str() << endl;

	}

	void test_string3()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.erase(6, 2);
		cout << s1.c_str() << endl;

		s1.erase(6, 20);
		cout << s1.c_str() << endl;

		s1.erase(3);
		cout << s1.c_str() << endl;

		string s2("hello helleoo");
		cout << s2.find('e') << endl;
		cout << s2.find("helle") << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i]++;
			cout << s1[i] << " ";
		}
		cout << endl;

		string::iterator it = s1.begin();//�������ķ�ʽ������
		while (it != s1.end())//��Ȼֻ�еײ��������ʱ��,�����������������Ŀ�����ô���
		{
			cout << *it++ << " ";
		}
		cout << endl;

		for (auto e : s1)//֧�ֵ�������֧�ַ�ΧforŶ
		{
			cout << e << " ";
		}
		cout << endl;

		const string s2("hello world");
		for (auto e : s2)//����const�Ĵ���ʵ�ַ�Χfor��Ҫ��const�ĵ�����Ŷ,���֮ǰû��ʵ��const������,����ͻᱨ��
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_string5()
	{
		string s1("hello world");

		string sub1 = s1.substr(6, 3);
		cout << sub1.c_str() << endl;

		string sub2 = s1.substr(6, 300);
		cout << sub2.c_str() << endl;

		string sub3 = s1.substr(6);
		cout << sub3.c_str() << endl;

		string s2("hello ldwxxxxxxxxxxxxxxxxxxx");
		s1 = s2;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		s1 = s1;
		cout << s1.c_str() << endl;
	}

	void test_string6()
	{
		//string s1("hello world");
		//string s2("hello dw");

		//cout << s1 << endl;
		//cout << s2 << endl;

		//string s3;
		//cin >> s3;
		//cout << s3 << endl;
		
		string s1, s2;
		cin >> s1 >> s2;
		cout << s1 << endl;
		cout << s2 << endl;

		string s3;
		//getline(cin, s3,'\n');
		getline(cin, s3, '!');
		cout << s3 << endl;
	}
	void test_string7()
	{
		string s1("111111111111");
		string s2(s1);
		cout << s1 << endl;
		cout << s2 << endl;

		const string s3("2222222222222222222222222");
		s1 = s3;
		cout << s3 << endl;
		cout << s1 << endl;


	}

}














