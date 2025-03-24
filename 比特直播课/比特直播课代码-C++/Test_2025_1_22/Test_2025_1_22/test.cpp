
#include <iostream>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//	}
//protected://如果基类成员不想在类外直接被访问，但需要在派⽣类
//	//中能访问，就定义为protected。可以说保护成员限定符就是因继承才出现的。
//	string _name = "张三"; // 姓名
//private:
//	int _age = 18; // 年龄
//};
//
//class Student : private Person// 如果把public继承改为private继承，那再用Student在类外就不能访问任何继承数据了
//{
//public:
//	void func()
//	{
//		//cout << _age << endl;// 基类的private在派生类中是没法访问的，但是确实是继承下来了，监视里可以看到
//		Print();// 但是类内还是可以访问
//	}
//
//protected:
//	int _stunum = 1; // 学号
//};
//
//int main()
//{
//	Student s;
//	//s.Print();
//	//s._name();// 遇到权限不同取二者中min的那个，比如_name在Person是protected，
//	// Student public继承了之后，取最小的，还是protected
//	s.func();// 但是也并非基类的private就不能使用，这样通过一层一层嵌套调用的方式
//	//func -> Print -> 私有成员   也能间接使用，所以其实不可见只是禁止直接使用，用一些间接的方法依旧能用
//
//	return 0;
//}
////使⽤关键字class时默认的继承⽅式是private，使⽤struct时默认的继承⽅式是public，
////不过最好显⽰的写出继承⽅式。


//class Person
//{
//public:
//protected:
//	string _name = "张三";
//	int _id = 1;
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		cout << _id << endl;
//		cout << Person::_id << endl;
//	}
//protected:
//	int _stunum = 1;
//	int _id = 2;
//};
//
//int main()
//{
//	Student s;
//	Person* ptr = &s;// 这里Student的指针能够直接给父类Person*而不需要强转，因为切片————赋值兼容转换
//	Person& ref = s;// 理论上这里也是不能引用的啊，因为隐式类型转换会产生临时对象，临时对象具有常性，无法引用
//	//但是其实这里引用的也不是临时对象，而是派生类中切片切出来的父类那一部分
//
//	int i = 0;
//	//double& rd = i;// 你看，这引用是不可以的，就是上面说的隐式类型转换产生临时对象，临时对象具有常性，无法引用
//	const double& rd = i;// 常性对象要用const接收，所以加const就能引用了
//
//	s.func();
//	// 派⽣类和基类中有同名成员，派⽣类成员将屏蔽基类对同名成员的直接访问，这种情况叫隐藏。
//	// 在派⽣类成员函数中，可以使⽤ 基类::基类成员 显⽰访问）
//
//	return 0;
//}
//
////基类对象不能赋值给派⽣类对象————很简单，子类里面可以切出父类的部分，但是父类里面切不出子类，谁知道子类里还有啥


//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//// 要把子类中的父类成员当成一个整体对象，作为子类的自定义成员看待
//class Student : public Person
//{
//public:
//	//Student(const char* name, int num)
//	//	: _name(name)// 这样写会报错的，要像下面这样
//	//	, _num(num)
//	//{}
//
//	Student(const char* name, int num)
//		: Person(name)// 这里很像定义一个匿名对象
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student & s)
//		: Person(s)// 这里传一个子类对象给父类的引用或者指针完全没问题，因为它会切片
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	Student& operator = (const Student & s)
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			// 构成隐藏，所以需要指定类域，显⽰调⽤
//			Person::operator =(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num = 1; //学号
//};
//
//int main()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//
//	return 0;
//}


////实现⼀个不能被继承的类 
////c++98的做法————基类的构造函数私有
//
//// C++11的⽅法
//class Base //final
//{
//public:
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//private:
//	// C++98的⽅法
//	/*Base()
//	{}*/
//};
//
//class Derive :public Base
//{
//	void func4() { cout << "Derive::func4" << endl; }
//protected:
//	int b = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}
//
////C++11新增了⼀个final关键字，final修改基类，派⽣类就不能继承了。


//// 友元关系不可继承
//class Student;// 互相引用，如果出缺少类型说明的错误，就加一个前置声明
//
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name = "张三"; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);// 派生类也添加了友元，才能使用
//protected:
//	int _stuNum = 1; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	// 编译报错：error C2248: “Student::_stuNum”: ⽆法访问 protected 成员
//	// 解决⽅案：Display也变成Student 的友元即可
//	Display(p, s);
//	return 0;
//}


//// 继承与静态成员
//// 静态成员会被继承，静态成员可以视作一个全局变量，受一些类域和访问限定符的限制而已
//// 基类定义了static静态成员，则整个继承体系⾥⾯只有⼀个这样的成员。⽆论派⽣出多少个派⽣类，都
//// 只有⼀个static成员实例。
//
//class Person
//{
//public:
//	string _name;
//	static int _count;
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum;
//};
//int main()
//{
//	Person p;
//	Student s;
//	Student s2;
//	// 这⾥的运⾏结果可以看到⾮静态成员_name的地址是不⼀样的
//	// 说明派⽣类继承下来了，⽗派⽣类对象各有⼀份
//	cout << &p._name << endl;
//	cout << &s._name << endl;
//	cout << &s2._name << endl;
//	// 这⾥的运⾏结果可以看到静态成员_count的地址是⼀样的
//	// 说明派⽣类和基类共⽤同⼀份静态成员
//	cout << &p._count << endl;
//	cout << &s._count << endl;
//	// 公有的情况下，⽗派⽣类指定类域都可以访问静态成员
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//	return 0;
//}


////多继承、虚继承问题，C++一个很大的坑
//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职⼯编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 编译报错：error C2385: 对“_name”的访问不明确
//	Assistant a;
//	//a._name = "peter";
//	// 需要显⽰指定访问哪个基类的成员可以解决⼆义性问题，但是数据冗余问题⽆法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//	return 0;
//}

class Person
{
public:
	string _name; // 姓名
	/*int _tel;
	int _age;
	string _gender;
	string _address;*/
	// ...
};

// 使⽤虚继承Person类
class Student : virtual public Person
{
protected:
	int _num; //学号
};
// 使⽤虚继承Person类
class Teacher : virtual public Person
{
protected:
	int _id; // 职⼯编号
};
// 教授助理
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};
int main()
{
	// 使⽤虚继承，可以解决数据冗余和⼆义性
	Assistant a;
	a._name = "peter";
	return 0;
}





