#define _CRT_SECURE_NO_WARNINGS


#include"vector.h"


//int main()
//{
//	vector<int> v1 = { 1,-2,30,4,5 };
//	list<int> lt1 = { 1,2,3,4,5 };
//
//	vector<string> v2;
//	vector<vector<int>> v3;
//
//	string name1 = "����";
//	v2.push_back(name1);//��������
//
//	v2.push_back(string("����"));//��������
//
//	v2.push_back("����");//��ʽ����ת��
//	
//	for (const auto& e : v2)// ��Χfor��������д����׳�����⴫ֵҪ�������̫��
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//int x;
//	//cin >> x;
//	////vector<int>::iterator it1 = find(v1.begin(), v1.end(), x);
//	//auto it1 = find(v1.begin(), v1.end(), x);
//	//if (it1 != v1.end())
//	//{
//	//	cout << x << "�ҵ���" << endl;
//	//}
//
//	//cin >> x;
//	////vector<int>::iterator it1 = find(v1.begin(), v1.end(), x);
//	//auto it2 = find(lt1.begin(), lt1.end(), x);
//	//if (it2 != lt1.end())
//	//{
//	//	cout << x << "�ҵ���" << endl;
//	//}
//
//	sort(v1.begin(), v1.end());//sortĬ������,�ײ��ǿ���,�ϸ���˵����ʡ����
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//������?�漰���º���,����֮��ὲ,������������
//	// Ĭ��less
//	//greater <int> gt;
//	//sort(v1.begin(), v1.end(), gt);
//	sort(v1.begin(), v1.end(), greater<int>());
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	//������Ҳ�����͵�,����˫�������,֧��++,֧��++--,֧��+N - N
//	//sort(lt1.begin(), lt1.end());
//	//��list�ĵ��������ǲ�֧��sort��
//
//
//	return 0;
//}



void func(const LDW::vector<int>& v)// �ܶ�ʱ�����������������ι�������const����֮��
{
	//for (size_t i = 0; i < v.size(); ++i)// ��Χfor��������᲻ͨ��
	//{
	//	//v[i]++; //�����޸�Ŷ����Ϊ�Ƿ��ص���const����
	//	cout << v[i] << " ";//��Ϊ�˴���[]���ղ�������ͨ����const�����޷�������ͨ����������Ҫ��������һ��const [] ��vector.h
	//}
	//cout << endl;

	//////int* const it = v.begin();
	////const LDW::vector<int>::iterator it = v.begin();// const����������ε�������������Ҫconst��������Ŀ�Ĳ������õ������������޸ģ�����Ҫ���ݲ����޸ģ�
	//// //����const����������������ͨ��������߼���const�������ˣ�����Ҫ����ʵ������һ�ݣ���������const_iterator������
	////while (it != v.end())
	////{
	////	cout << *it << " ";
	////	++it;
	////}


	//LDW::vector<int>::const_iterator it = v.begin();// ����������ˣ���������߼�const
	//while (it != v.end())
	//{
	//	//*int += 5;
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;


	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

}



//int main()
//{
//	LDW::vector<int> v1;
//	LDW::vector<double> v2;
//
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//
//	func(v1);
//
//
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < v1.size(); i++)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	//v1[i]
//	//v1.operator[](i);
//
//	//int a[10];
//	//a[i];  *(a+i)
//
//	//std::vector<int> v;
//	//cout << typeid(std::vector<int>::iterator).name() << endl;
//	//cout << typeid(std::vector<int>::const_iterator).name() << endl;
//	//cout << typeid(std::vector<int>::reverse_iterator).name() << endl;
//	//cout << typeid(std::vector<int>::const_reverse_iterator).name() << endl;
//
//
//	return 0;
//}//2025,�����ټ�




//int main()
//{
//	LDW::vector<int> v1;
//
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	//v1.push_back(5);// ��ʱ�������һЩ������ʧЧ�����⣬��������ע�͵�5������������ʧЧ����ô�������Զ϶��������й�ϵ
//
//	int i = 0;
//	cin >> i;
//	auto it = v1.begin() + i;
//	// insert ֮��Ĭ�ϵĵ�������ʧЧ�ˣ���Ҫʹ��
//	v1.insert(it, 10);// ����������£����itҲ��ʧЧ�ĵ�����
//
//
//
//	func(v1);
//	v1.insert(v1.begin(), 10);
//
//	func(v1);
//	v1.erase(v1.begin() + 3);
//	func(v1);
//
//
//
//
//
//
//	return 0;
//}

//int main()
//{
//	LDW::vector<int> v1;
//
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//
//	//���ӣ�����Ҫ��ɾ�����е�ż��
//	auto it = v1.begin();
//	while (it != v1.end())
//	{
//		if (*it % 2 == 0)
//		{
//			v1.erase(it); // Ҫʹ�� erase ���صĵ�����������it����Ȼֻ��v1.erase(it)��eease��it�ᱻ�ж�Ϊ������ʧЧ
//		}
//		else // ֻ���ڲ�ɾ��Ԫ��ʱ�ŵ���������
//		{
//			++it; 
//		}
//	}
//
//	func(v1);
//
//	return 0;
//}

//int main()
//{
//	LDW::vector<int> v1;
//
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);
//	func(v1);
//
//
//
//	v1.resize(7, 10);
//	func(v1);
//
//	v1.resize(17, 20);
//	func(v1);
//
//	v1.resize(5);
//	func(v1);
//
//	LDW::vector<int> v2;
//	v2.resize(100, 1);
//	func(v2);
//
//
//
//	return 0;
//}


//int main()
//{
//	LDW::vector<int> v1;
//
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);
//
//	//LDW::vector<int> v2(v1);
//	LDW::vector<int> v2 = v1;// ���Ҳ�ǿ����������ֻҪ��һ������ȥ��ʼ������һ�����󣬶�������������
//	func(v2);
//
//	LDW::vector<int> v3;
//	v3.resize(100, 1);
//	v1 = v3;
//	func(v1);
//
//
//	return 0;
//}

//int main()
//{
//	LDW::vector<string> v1;
//
//	v1.push_back("111111111111111111111");
//	v1.push_back("111111111111111111111");
//	v1.push_back("111111111111111111111");
//	v1.push_back("111111111111111111111");
//	v1.push_back("111111111111111111111");// Ϊɶ��5�о������أ�Ӧ�������ݵ�����
//
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


//int main()
//{
//	
//	LDW::vector<int> v1 = { 1,2,3,4,5,6 };// C++11 ֮��ĳ�ʼ����ʽ��������initializer_list
//	// ������ʵ�ǵ��������� ͨ��= ����ʽ����ת��
//	//LDW::vector<int> v2({ 1,2,3,4,5,6 });
//    // ������Ǵ�initializer_list�Ĳ�
//
//
//
//	//auto il = { 1,2,3,4,5,6 };
//	////ԭ���Ϻ�
//	//int a[] = { 1,2,3,4,5,6 };// ����
//	//cout << typeid(il).name() << endl;
//	//cout << il.begin() << endl;// ������Կ������initializer_listʵ������ջ�Ͽ��Ŀռ�
//	//cout << a << endl;// ����Щջ�Ͽ��������ַ�ӽ�
//	//const char* str = "hello world";// ������const����λ�ڳ���������ַ�����Զ
//	//cout << (void*)str << endl;
//
//
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//
//	LDW::vector<int> v1 = { 1,2,3,4,5,6 };
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	LDW::vector<int> v2(v1.begin() + 1, v1.end() - 1);
//	for (const auto& e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	string s1("hello world");
//	LDW::vector<int> v3(s1.begin(), s1.end());
//
//	for (const auto& e : v3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	int a[] = { 10,2,30,4,55,6 };
//	LDW::vector<int> v4(a, a + 6);// �����������ǿ��Դ�����������ԭ��ָ���Ŷ����Ϊ������ģ��ľ���ָ�����Ϊ������ԭ��ָ��͸����Ե��ɵ�������
//	for (const auto& e : v4)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	
//	sort(v4.begin(), v4.end()); // sort�ܶ������ĵ�������������
//	for (const auto& e : v4)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	sort(a, a + 6);
//	for (const auto& e : a) // sortҲ�ܶ�ָ����������
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}

int main()
{

	LDW::vector<double> v1(10, 0.1);
	for (const auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	LDW::vector<int> v2(10, 1);// C2100��������ƥ�䲻�ԣ�ƥ�䵽vector(InputIterator first, InputIterator last)���ˣ���Ϊ���Ǹ�����
	for (const auto& e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	LDW::vector<size_t> v3(10ULL, 1ULL);// ULL��ʾsize_t
	for (const auto& e : v3)
	{
		cout << e << " ";
	}
	cout << endl;



	return 0;
}


