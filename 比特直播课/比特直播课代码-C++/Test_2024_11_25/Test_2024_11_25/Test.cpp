#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


#include<string>
#include<assert.h>
#include<list>

namespace LDW
{
	class string
	{
	public:
		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

	private:
		char _buff[16];
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}


void test_string1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	//string s4(s2, 6, 1000);
	string s4(s2, 6);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	//1.�±� + []
	for (size_t i = 0; i < s2.size(); i++)
	{
		s2[i] += 1;
		//�ȼ� s2.operator[](i) += 1;
	}

	for (size_t i = 0; i < s2.length(); i++)//size lengthЧ����һ���ģ���ʷ����ԭ�����ȿ�����ʱ��д����length������������֮��Ͷ���size�ˣ��˽�һ�¼���
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	const string s5("xxxxxxx");
	//s5[0] = 'y';//string::operator[] �������������ӿڣ�һ��������ͨ�ģ�һ����const�ģ��������const������ã����ǲ����޸����ݵ�


	cout << s2.size() << endl;//size������\0
	//2.������
	//string::iterator it = s2.begin();//beginָ���һ�����ݵ�λ�ã�endָ�����һ��������һ��λ��
	auto it = s2.begin();//������auto�ͺܺ���
	while (it != s2.end())//����!=�ܷ񻻳�<�أ���string������ֿ��ԣ������Ƽ�����Ϊ����ͨ��д����string�ײ������飬��һ�������Ĵ���ռ䣬������list��������û�취��֤����ĵ�ַһ����ǰ��������Ƽ�д!=
	{
		cout << *it << " ";//��������һ����Ϊ��ָ��һ���Ķ�����ʱ�������ָ�룬��ʱ����ָ�룬����Ϊ������ָ���
		++it;
	}
	cout << endl;

	//string::const_iterator it5 = s5.begin();//������Ҳ�������汾����ͨ���const��
	auto it5 = s5.begin();//������auto�ͺܺ���
	while (it5 != s5.end())
	{
		//*it5 += 1;ָ������ݲ����޸�   const����������ָ�����ݵģ�ָ�����ݲ����޸�
		cout << *it5 << " ";
		++it5;
	}
	cout << endl;

	//���±�+[]��ô����Ϊɶ��Ҫ�������أ�
	//��Ϊ�±�+[]��������ķ��ʷ�ʽ������������ͨ�õķ��ʷ�ʽ
	//�±�+[]�޶��ײ������飬����������Ľṹ�в���ʹ�ã������������û�취ʹ�ã������������Ҫ�õ�����������ͨ�õķ��ʷ�ʽ
	list<int> lt = { 1,2,3,4,5 };
	list<int>::iterator it1 = lt.begin();
	while (it1 != lt.end())
	{
		*it1 += 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//���������������ָ�룬�����װ�ģ���Ϊ�����ָ�룬�ڲ���++��û�취�����ˣ���ô��++�����ߣ����Կ϶��Ƿ�װ�ģ���++���ص�
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;//������++��������
	}
	cout << endl;

	//��Χfor��������
	for (auto ch : s2)//��Χfor�ײ���ʵ�����أ����ǵ�����
	{
		cout << ch << " ";
	}
	cout << endl;
}

void test_string2()
{
	string s1;
	cout << s1.max_size() << endl;

	string s2("hello world");
	cout << s2.size() << endl;//size  ������\0   ʵ�ʴ��˶��ٸ���Ч�ַ� 
	cout << s2.capacity() << endl;//capacity ������\0   �ܴ���ٸ���Ч�ַ�

	s2.clear();//clearֻ�������ݣ�һ�㲻�ͷſռ�
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	s2[15];//�����Ƕ���
	//s2.at(15);//���������쳣

}

void test_string3()
{
	string s1;
	s1.push_back('x');
	s1.push_back('x');
	s1.push_back('x');
	s1.append("yyyyy");
	cout << s1 << endl;

	string s2("hello world");
	s1.append(s2.begin(), s2.end());//����������
	cout << s1 << endl;

	s1.append(s2.begin() + 6, s2.end());//���������ַ����жβ��룬���������+
	cout << s1 << endl;

	s1 += ' ';
	s1 += "zzz";
	s1 += s2;
	cout << s1 << endl;//+=������C�ֵ�strcat ��strcat�Ǹ�����Ľӿڣ�����
	//һ����Ϊstrcat�Ǳ����ҵ�\0��׷�ӣ���������������ݣ�����Ч�ʺ�ʵ���Զ��ܲ�
	//����+=����string�����size�ĵ�ַȥ����ģ����˱���Ч�ʸߣ����һ��Լ�����ռ䣬�����ֶ�����

}

void test_string4()
{
	string s1("1111111");
	string s2("22222222222222222222222222222222222222222222222");
	s2.reserve(100);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	s2.reserve(40);//vs�����ѡ�񣬵�reserve���α�capacityС,���߱�sizeС��ʱ���ǲ�������,����Linux g++����
	cout << s2.size() << endl;//��Ҳ������size�Ĵ�С��,��Ϊreserve�ĺ��ľ��ǲ��ı�ԭ����,�������ֻ������ԭsize�Ĵ�С
	cout << s2.capacity() << endl;
	//�ճ���reserve��Ҫ�����ݶ�������,����ȥ��shrink_to_fit,��Ϊreserve�Ƿ����ݲ�ȷ��,ȡ��������


	string s;
	s.reserve(1000);//reserve����Ҫ�����ǣ���֪����Ҫ����������ݣ�����ǰ�ѿռ俪�ã��������ݡ�

	size_t sz = s.capacity();
	cout << "capacity changed:" << sz << '\n';

	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{	
		//s.push back('c');
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}//�����ʼ��2�����ݣ�����Ľ����������һ��1.5��������
//Ϊ�˴���һЩ�ڴ���Ƭ������
//string �ڲ������δ洢���ơ����ַ������ַ���С�� 16 ʱ�����ݻ�ֱ�Ӵ洢�ڶ����ڲ��������У�����Ҫ��̬�����ڴ档�������൱�����ݴ洢�ڶ������ buffer �С�
//�����ַ������ڵ��� 16 ʱ���Ͳ���ʹ���������ô洢���ƣ�����ͨ����̬�����ڴ�ķ�ʽ���洢���ݣ�1.5��ʵ���Ƕ��ϵ����ݻ���;


void test_string5()
{
	//resize

	string s2("22222222");
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;
	
	s2.resize(3);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;
	
	s2.resize(13);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.resize(23);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;
	//size = 8,capacity = 15
	//resize(3);//��sizeС��ɾ������
	//resize(13)��size�󣬲������ݣ����˲ξͲ�����ַ���û���Ͳ�Ĭ�ϳ�ʼ���ַ�\0��
	//resize(20)��capacity��Ҫ��,���ݼӲ������ݡ�

}

void test_string6()
{
	string s1("22222222");
	cout << s1 << endl;
	//string����ͷ����в�,��Ϊ����������ռ�ҪŲ����,��һ��On���ӶȵĽӿ�
	s1.insert(0, "hello");
	cout << s1 << endl;

	s1.insert(0, 1 , 'x');//��0λ�ò�1��x,����ʵ����ͷ��
	cout << s1 << endl;

	s1.erase(5, 2);
	cout << s1 << endl;

	s1.erase(5);
	cout << s1 << endl;

}

void test_string7()
{
	string s1("22222222");
	string s2("33333333");

	//s1 = s2;
	s1.assign(s2);

	cout << s1 << endl;
	cout << s2 << endl;
}




int main()
{
	//while (1) 
	//{
	//	try
	//	{
	//		int i = 0;
	//		cin >> i;//���������͵������ӿڣ����������ݲ�ִ����һ����

	//		//test_string1();
	//		test_string2();
	//	}
	//	catch (const exception& e)
	//	{
	//		cout << e.what() << endl;
	//	}
	//}

	//test_string3();

	//test_string4();

	//test_string5();

	//test_string6();

	test_string7();


	
	return 0;
}