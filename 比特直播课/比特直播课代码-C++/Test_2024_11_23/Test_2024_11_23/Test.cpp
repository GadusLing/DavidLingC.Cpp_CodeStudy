#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//// ��ģ��
//template<typename T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 4)
//	{
//		_array = new T[capacity];
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const T& data);
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//
//// ģ�治���������Ͷ�����뵽�����ļ�.h ��.cpp��������Ӵ��󣬾���ԭ�����ὲ
//template<class T>
//void Stack<T>::Push(const T& data)
//{
//	// ����
//	_array[_size] = data;
//	++_size;
//}
//
//
//
//int main()
//{
//	Stack<int> st1;    // int
//	Stack<double> st2; // double
//	return 0;
//}
/////////////////////////////////////////////////

//�ڴ����©��һ��֪ʶ
//��λnew

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//// ��λnew/replacement new
//int main()
//{
//	//���������new��Ҫ��̬������ô�죿Ҫô��operator new Ҫô malloc
//	A* p1 = (A*)operator new(sizeof(A));
//	//��ô�����и����⣬��ΪP1�ڲ���_a��˽�еģ���û����ʼ��
//	//�����ҵ�дһ��Init��������ʼ�����������͹���Ĺ����ظ�
//	//�������ʱ��Ҫ�õ���λnew
//	//��λnew���ʽ�����ѷ����ԭʼ�ڴ�ռ��е��ù��캯����ʼ��һ������
//
//	//new(p1)A;
//	new(p1)A(10);
//
//	//delete p1;
//	p1->~A();//������֧����ʾ���õģ����ǹ��첻֧�ֹ�
//	operator delete(p1);
//
//
//	//�����������еĶ�λnewʵ���϶���װ��new������
//	//A* p2 = new A(10);//һ��͸㶨��
//
//	//��ô��ʵ�ʵĿ���������ȷʵ��Щ�����ǲ�ʹ��new�ģ������ڴ��
//  //���óػ������������ڴ�غ󣬾ͻ��ö�λnewֱ�Ӵ��Ѵ��ڵ��ڴ���е����ڴ����������ʹ��new or malloc��������ϵͳҪ�ռ���
//
//	return 0;
//}
//////////////////////////////////////////////////////////

//STL����
//��Դ
//Alexander Stepanov��Meng Lee �ڻ���ʵ������ɵ�ԭʼ�汾�����ſ�Դ�����������������κ����������á��������޸ġ���������ҵʹ����Щ���룬���踶�ѡ�
//Ψһ����������Ҳ��Ҫ��ԭʼ�汾һ������Դʹ�á� HP �汾--����STLʵ�ְ汾��ʼ�档

//ԭ�����������񡪡�������Դ����ôΰ��
///////////////////////////////////////////////////////////////

//string����

//auto func1()
//{
//	return 1;
//}
//
//auto func2()
//{
//	return func1();
//}
//
//auto func3()
//{
//	return func2();
//}
//
//int main()
//{
//	int x = 10;
//
//	auto y = &x;
//	auto* z = &x;//����д���ұ߱���дָ��
//
//	auto& m = x;
//	auto n = x;
//
//	auto aa = 1, bb = 2;
//	// ���뱨��error C3538: ���������б��У���auto������ʼ���Ƶ�Ϊͬһ����
//	//auto cc = 3, dd = 4.0;//һ��������������Ƶ����ͱ�����һ����
//	// ���뱨��error C3318: ��auto []��: ���鲻�ܾ������а�����auto����Ԫ������
//
//
//	//auto array[] = { 4, 5, 6 };//auto�����Ƶ�����
//
//	//��ʵ�ʿ���auto������ɶ�������ͺܳ���ʱ����auto
//	//std::map<std::string, std::string> dict = { { "apple", "ƻ��" },{ "orange","����" }, {"pear","��"} };    //auto������֮��
//	//std::map<std::string, std::string>::iterator it = dict.begin();
//	
//	//auto it = dict.begin();   ��auto�ͺ�Ư��������auto�ĺ��ļ�ֵ�������������
//	
//	//auto��֮ǰĳЩʱ��֧��������������������ֵ���������µ���һ����������֧����������
//	
//	//auto������ֵ�и��׶ˣ�Ҫ������������ĺ�������
//	auto ret = func3();
//	//�������Ƕ�׵�ʱ��дauto������ˬ�ˣ��������˻�ǳ����ܣ�һ���ȥ��Ҫ
//
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////////

//��Χfor

//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	//// C++98�ı���
//	//for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//	//{
//	//	array[i] *= 2;
//	//}
//	//for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	//{
//	//	cout << array[i] << " ";
//	//}
//	//cout << endl;
//	////ͨ�����Ǵ�ͳдѭ������������ķ�ʽ����ѧ�˷�Χfor֮�����ǿ�������������д
//
//	// C++11�ı���
//	for (auto& e : array)//��������e�ǿ��������������Ҫ�ı�����ʱ��Ҫ������
//	{
//		e *= 2;
//	}
//	for (auto e : array)//auto ���������Ԫ�ص������Զ��Ƶ������� e ������    �Զ�ȡ���ݸ�ֵ����e���Զ�++���Զ�����
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (const auto& e : array)//����������Զ���������ôҪ���������죬����������뿽���ֲ����޸ģ����þ����const auto& e �������õ�д����д
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//
//}
//��Χfor�������Ա������飬�����Ա����������������Ҫѧ��string vector list֮���

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//string ����
//������string��Cplusplus�б�����Miscellaneous���Ҳ����˵���ϸ���˵������STL������������һЩ��ʷԭ��string�����ȿ����ģ�����string�ӹ�������һ�����׼׼��������֮��Ҳ��������Ϊ������û������

//string�ײ����� basic_string<char> ������typedef��ģ��
//basic_string<char>��һ����������char����ģ�����char˳����һ������

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
	
	for (size_t i = 0; i < s2.length(); i++)//size lengthЧ����һ���ģ���ʷ����ԭ�����𿪷���ʱ��д����length������������֮��Ͷ���size�ˣ��˽�һ�¼���
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

int main()
{
	test_string1();

	return 0;
}























