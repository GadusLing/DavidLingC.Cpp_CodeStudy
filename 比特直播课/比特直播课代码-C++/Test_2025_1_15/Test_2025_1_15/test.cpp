
#include "list.h"

void test_list1()
{
	list<int> lt1;// ģ�����͹��죬��int����һ��list
	lt1.push_back(1);// ֧��β��
	lt1.push_back(2);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

	list<int>::iterator it = lt1.begin();// ֧�ֵ���������
	while (it != lt1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (const auto& e : lt1)// ֧�ַ�Χfor
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>lt2 = { 10,2,30,5 };// ֧��initializer list��ʼ�� 
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_list2()
{
	list<int> lt1;// ģ�����͹��죬��int����һ��list
	lt1.push_back(1);// ֧��β��
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

	lt1.assign(2, 1);// ��lt1���10��1�����ɾ�����ٵ����ݲ��룬�������ά�ֳ�10��1

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;


}

struct A
{
public:
	A(int a1 = 1, int a2 = 1)
		:_a1(a1)
		,_a2(a2)
	{}


	int _a1;
	int _a2;

};


void test_list3()
{
	list<int> lt1;
	lt1.push_back(1);// emplace_back ��push_back�ӹ����Ͽ�������һ��
	lt1.push_back(2);// ��list<int> lt1;ʵ����int֮��push_backֻ�ܲ���ʵ������T���ͣ���int,��������ʽ����ת��Ϊint������

	lt1.emplace_back(3);// emplace_back����Ҳ��������
	lt1.emplace_back(0.5);

	//��������Ը������ͣ��������ǹ���һ��struct A
	//�ڴ���A����ʱ��push_back�����¼��ַ�ʽ
	list<A> lt2;
	A aa1(2, 2);// 1.����һ��aa1����
	lt2.push_back(aa1);// Ȼ�󴫶���
	lt2.push_back(A(2, 2));// 2.��������
	lt2.push_back({ 2, 2 });// ��ʽ����ת��initializer listת��ΪA����

	//emplace_back �����¼����÷�
	lt2.emplace_back(aa1);// 1.������
	lt2.emplace_back(A(2, 2));// 2.��������

	//lt2.emplace_back({ 2, 2 });emplace_backû�취�����ã���Ϊpush_back�Ĳ�����ȷ���ģ���������A�������������Ƶ�
	//��emplace_back��ģ�壬���������ǲ�ȷ���ģ������Ƶ�������initializer list�Ĳ�������ȥû�취�ã���֪����ô��

	lt2.emplace_back(2, 2);// 3.����emplace_back���������ã���Ϊ��ģ�壬�ɱ����������ֱ�ӰѲ�������ȥ��
						   // ��push_backʵ������������ߵı���{ 2, 2 }����ȥ������һ��A��Ȼ���ٰѹ���õ�A�߿�������ȥ�����������push_back������
						   // ����ֱ�Ӱ�����(2, 2)������emplace_back�ɱ������û�й���A�ٿ�������ȥ���ݣ�����ͨ�����������ֱ��������ĩβԭ�ع�����
	                       // �������ַ�ʽ�����Ч, ֮����C++11�׶λ����ٽ���һ���֣����ڿ����ȼ�ס����

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_list4()
{
	list<int>lt1 = { 10,6,30,5,6,8,9,6 };
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
	
	lt1.remove(100);// �������removeɾ��һ��û�е�ֵ�᲻�ᱨ���أ� �����
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.remove(5);//
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.remove(6);// ����remove�����erase�и��ص㣬��ɾ�����е�6,erase��ɾ��ĳһλ�õ�һ����һ������������
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list5()
{
	list<int>lt1 = { 10,6,30,5,6,8,9,6 };
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	//sort(lt1.begin(), lt1.end());// ����sort���㷨�������и�sortΪɶlist���滹Ҫ�Լ�дһ��sort
								 // ��Ϊ�㷨�������list����ò��ˣ��㷨���sort���˵�������-x���ܣ���list������֧��++ --�����ǲ�֧��-x��
	                             // �ܼ򵥵�ԭ��������������ռ䣬���еĵ����������໥-�����ۺܵ;��ܻ�ȡ��Ч�Ŀռ�
								 // ����������������ռ䣬�໥-Ҳ�ò�����Ч�ĵ�ַ�ռ䣬ֻ���õ�������ͣ��next or prvȥ��ȡ���ݣ�Ч�ʼ���
								 // ��������� ++ 
								 // ˫������� ++/--
								 // ��������� ++/-- /+x /-x
								 // ����forward_list�еĵ��������ǵ�������� (forward_iterator)
								 // ��list map set �еĵ���������˫������� (bidirectional_iterator)
								 // vector string �еĵ���������������� (random_access_iterator)
	// �㷨���ڵ�������������Ҫ��ģ�������
	// һ������ֲ��������д���������InputIterator ����Ҫ�󴫵������Ϊʲô���ﲻ��forward_iterator���������C++��Ƶ�����ʱ��һ�����ӹ�ϵ��ϵ�йأ�֮�����о�
	// ����ֻ��Ҫ��ȷ�����㷨һ�㶼��д�����Ҫ����InputIterator / BidirectionalIterator ���� RandomAccessIterator
	// ���滹����һ�����ӹ�ϵ�����Ǳ�����ҪInput�ĳ�������Bid �� RanҲ�ǿ����õģ�Bid�ĳ��� �� RanҲ�У�����Ran�ĳ�����������Inp �� Bid�� Ran > Bid > forward > Inp = Outp(������)

	//�㷨��ײ��ǿ�����ʡ��������Ҫ��+ -������ʣ�Ҳ������Ϊ��֧�֣�����list�Լ�Ҫ���sort
	
	// < ����
	lt1.sort();// �����sort���õĹ鲢����
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	// > ��Ҫ�������У�������õ��º���
	lt1.sort(greater<int>());// ��һ��greater<int>()��������, ֮�����ϸ���º����������ż����ȿ�����ô��
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	// list��sortʵ�ʿ����г����������Ƚ�С����Ȼ�ܲ��þͲ��ã������ر����磬release�±ȿ��Ų���2-3����Ч��
	// 100��������������£����������list������copy��vector��vector.sort����assign��list��Ч�ʶ���list�Լ���sort��
}

void test_list6()
{
	list<int>lt1 = { 10,6,6,30,5,6,8,8,9,6 };
	
	lt1.sort();// ��Ϊunique��ȥ������Ԫ�أ����Ծ�����sortһ�����ʹ�ã�������ȥ��

	lt1.unique();//unique��Ѱ���һ�������ģ����ظ�Ԫ��ȥ��
	// �ײ���ǿ���ָ��ȥ�أ���1��ʼ������һ���İѿ��Ԫ�ز嵽�����Ǳߡ������ٺ���

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list7()
{
	list<int>lt1 = { 1,2,3,30,5,6,8,8,9,6 };

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	// ͨ��splice���Լ���1�ƶ���β��
	lt1.splice(lt1.end(), lt1, lt1.begin());
	for (auto e : lt1)
	{
		cout << e << " ";
	}

}

void test_LDWlist1()
{
	LDW::list<int>lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);
	lt1.push_back(6);

	LDW::list<int>::iterator it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}

void Print(const LDW::list<int>& lt)
{	//Print �����Ĳ����� const LDW::list<A>& lt����������lt.begin();������const�������İ汾
	LDW::list<int>::const_iterator it1 = lt.begin();
	while (it1 != lt.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

}

void RPrint(const LDW::list<int>& lt)
{
	LDW::list<int>::const_reverse_iterator it1 = lt.rbegin();
	while (it1 != lt.rend())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}

void test_LDWlist2()
{
	//LDW::list<A> lt1;
	//lt1.push_back({ 1,1 });
	//lt1.push_back({ 2,2 });
	//lt1.push_back({ 3,3 });
	//lt1.push_back({ 4,4 });


	//LDW::list<A>::iterator it1 = lt1.begin();
	//while (it1 != lt1.end())
	//{
	//	//cout << (*it1)._a1 << ":" << (*it1)._a2 << endl;
	//	cout << it1->_a1 << ":" << it1->_a2 << endl; // ֧��(*it1)._a1 �� . ��Ҫ֧��->������->Ҳ������һ��
	//	//����Ӧ����������ͷ��������Ϊ�˿ɶ���ʡ����һ��
	//	//it->->_a1
	//	//it.operator->()->_a1
	//	++it1;
	//}
	//cout << endl;

	LDW::list<int> lt2;
	lt2.push_back(1);
	lt2.push_back(2);
	lt2.push_back(3);
	lt2.push_back(4);
	lt2.push_back(5);
	lt2.push_back(6);

	Print(lt2);
	cout << typeid(vector<int>::iterator).name() << endl;
}

void test_LDWlist4()
{


	LDW::list<int> lt2;
	lt2.push_back(1);
	lt2.push_back(2);
	lt2.push_back(3);
	lt2.push_back(4);
	lt2.push_back(5);
	lt2.push_back(6);
	Print(lt2);

	LDW::list<int> lt3(lt2);

	lt2.clear();

	Print(lt2);

	Print(lt3);

	LDW::list<int> lt4 = { 10,20,30,40 };
	//lt4.push_back(10);
	//lt4.push_back(20);
	//lt4.push_back(30);
	//lt4.push_back(40);

	lt2 = lt4;
	Print(lt4);



}

void test_LDWlist_Ritertor1()
{
	LDW::list<int> lt2;
	lt2.push_back(1);
	lt2.push_back(2);
	lt2.push_back(3);
	lt2.push_back(4);
	lt2.push_back(5);
	lt2.push_back(6);
	RPrint(lt2);

	LDW::list<int> lt3(lt2);

	lt2.clear();

	RPrint(lt2);

	RPrint(lt3);

	LDW::list<int> lt4 = { 10,20,30,40 };

	lt2 = lt4;
	RPrint(lt4);
}

int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();
	//test_list5();
	//test_list6();
	//test_list7();
	//test_LDWlist1();
	//test_LDWlist2();
	//test_LDWlist4();
	test_LDWlist_Ritertor1();





	return 0;
}