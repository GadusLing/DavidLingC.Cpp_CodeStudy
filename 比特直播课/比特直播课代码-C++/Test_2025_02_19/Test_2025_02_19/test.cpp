#include<iostream>

using namespace std;


//void push(const string& str)
//{
//
//
//}
//
//
//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	double d = 2.2;
//	const int& i = d;// 隐式转换会产生临时变量，前面的引用是引用临时变量，临时变量具有常性
//
//	const string& str = "111111";
//
//	string s1("1111");
//	push(s1);
//	push("1111");
//
//	// 那谈到转换问题，把派生类给给基类是否也被视作一种类型转换呢？因为两者类不同呀
//	// 这叫赋值兼容转换，是一种特殊处理，引用的是派生类切片出来的父类的那一部分
//
//
//	return 0;
//}



//// 菱形继承案例
//class Person
//{
//public:
//	Person(const char* name)
//		:_name(name)
//	{}
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		, _num(num)
//	{}
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//public:
//	Teacher(const char* name, int id)
//		:Person(name)
//		, _id(id)
//	{}
//protected:
//	int _id; // 职⼯编号
//};
//
//// 不要去玩菱形继承
//class Assistant : public Student, public Teacher
//{
//public:
//	Assistant(const char* name1, const char* name2, const char* name3)
//		:Person(name3)
//		, Student(name1, 1)
//		, Teacher(name2, 2)
//	{}
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 思考⼀下这⾥a对象中_name是"张三", "李四", "王五"中的哪⼀个？
//	Assistant a("张三", "李四", "王五");
//	return 0;
//}
//
//
//// 指针偏移问题，注意观察初始化的顺序，有些题会改初始顺序，但记住一点，谁先初始化谁地址就在前面
//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}



//// 多态内容
//// 实现多态还有两个必须重要条件：
//// 必须是基类的指针或者引⽤调⽤虚函数
//// 被调⽤的函数必须是虚函数，并且完成了虚函数重写/覆盖。虚函数重写/覆盖————函数名、参数类型、返回值三同才能构成重写/覆盖
//class Person 
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person 
//{
//public:
//	virtual void BuyTicket() { cout << "买票-打折" << endl; }
//};
//// 派⽣类的虚函数在不加virtual关键字时，虽然也可以构成重写(因为继承后基类的虚函数被继承下来了在派⽣类依旧保持虚函数属性)，
//// 简单的理解可以说派生类中所谓的“重写”，是重写函数后{}里面的功能内容，但前面的函数属性都继承了
//// 但是该种写法不是很规范，不建议这样使⽤，不过在考试选择题中，经常会故意买这个坑，让你判断是否构成多态。
//
//void Func(Person* ptr)
//{
//	// 这⾥可以看到虽然都是Person指针Ptr在调⽤BuyTicket
//	// 但是跟ptr没关系，⽽是由ptr指向的对象决定的。
//	ptr->BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(&ps);
//	Func(&st);
//	return 0;
//}


//class Animal
//{
//public:
//	virtual void talk() const
//	{
//	}
//};
//
//class Dog : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "汪汪" << std::endl;
//	}
//};
//
//class Cat : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		std::cout << "(>^ω^<)喵" << std::endl;
//	}
//};
//
//void letsHear(const Animal& animal)
//{
//	animal.talk();
//}
//
//int main()
//{
//	Cat cat;
//	Dog dog;
//	letsHear(cat);
//	letsHear(dog);
//	return 0;
//}



//// 经典题目，这个题目就是用了基类的声明+派生类的实现
//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }// 是A* 的 this 调的func()  继承不是在派生类中再生成一份，还是会回到对应的基类中去调
//	//所以这里的的this 是 A*而不是B*
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}
//// 仅做考察使用，项目里不要写这样的代码，影响工作效率，会被打


//// 协变
//// 了解即可，实用性不高
//// 派⽣类重写基类虚函数时，与基类虚函数返回值类型不同。
//// 即基类虚函数返回基类对象的指针或者引⽤，派⽣类虚函数返回派⽣类对象的指针或者引⽤时，称为协变。
//
//class A {};
//class B : public A {};
//
//class Person 
//{
//public:
//	virtual A* BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//		return nullptr;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* BuyTicket()
//	{
//		cout << "买票-打折" << endl;
//		return nullptr;
//	}
//};
//
//void Func(Person* ptr)
//{
//	ptr->BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Func(&ps);
//	Func(&st);
//	return 0;
//}


////析构函数重写
//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B : public A 
//{
//public:
//	virtual ~B()// 想构成多态，但是析构函数名不同怎么办？
//	{// 没关系，因为实际上派生类的析构函数和基类的析构函数构成隐藏，底层析构函数的名称被特殊处理成了destructor（)
//		cout << "~B()->delete:" << _p << endl;
//		delete _p;
//	}// 关于重载、重写/覆盖、隐藏的关系可以参考“多态”课件
//protected:
//	int* _p = new int[10];
//};
//// 只有派⽣类B的析构函数重写了A的析构函数，下⾯的delete对象调⽤析构函数，才能构成多态，
//// 才能保证p1和p2指向的对象正确的调⽤析构函数。
//
//// 之前还谈到了，基类加上virtual关键词，派生类不用加virtual也视作有虚函数属性
//// 所以如果基类的析构加上virtual，派生类哪怕忘记写virtual关键词了，也能保证各个类调用正确的析构
//// 所以推荐把基类的析构函数加上virtual做成虚函数
//
//int main()
//{
//	//A aa1;
//	//B bb1;
//
//	A* p1 = new A;
//	A* p2 = new B;// 这里如果AB两类的析构不构成多态，那么把B传给A的话，就会出现new B但调A析构，会有内存泄漏风险
//	delete p1;
//	delete p2;
//	return 0;
//}


////override 和 final关键字  C++11
//// error C3668: “Benz::Drive”: 包含重写说明符“override”的⽅法没有重写任何基类⽅法
//class Car {
//public:
//	virtual void Dirve()
//	{}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};
//int main()
//{
//	return 0;
//}

//// error C3248: “Car::Drive”: 声明为“final”的函数⽆法被“Benz::Drive”重写
//class Car
//{
//public:
//	virtual void Drive() final 
//	{}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};
//int main()
//{
//	return 0;
//}


//// 纯虚函数和抽象类
//// 在虚函数的后⾯写上 =0 ，则这个函数为纯虚函数，纯虚函数不需要定义实现(实现没啥意义因为要被派⽣类重写，但是语法上可以实现)，
//// 只要声明即可。包含纯虚函数的类叫做抽象类，抽象类不能实例化出对象，
//// 如果派⽣类继承后不重写纯虚函数，那么派⽣类也是抽象类。
//// 纯虚函数某种程度上强制了派⽣类重写虚函数，因为不重写实例化不出对象。
//
//class Car
//{
//public:
//	virtual void Drive() = 0;// 纯虚函数
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//
//int main()
//{
//	// 编译报错：error C2259: “Car”: ⽆法实例化抽象类
//	Car car;
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//	return 0;
//}


//// 经典题目 32位系统
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//protected:
//	int _b = 1;
//	char _ch = 'x';
//};
//int main()
//{
//	Base b;
//	cout << sizeof(b) << endl;
//	return 0;
//}
//// 按照之前学习的，32位下，一个int，一个char，内存对齐后应该是8，但是结果是12
//// 因为虚函数的影响，一个类里面有虚函数的话会增加一个指针，叫做虚表指针，32是4byte，64是8byte
// 虚函数表可以理解成一个 虚函数指针数组，里面存的是所有虚函数的地址



//多态原理
class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
private:
	string _name;
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-打折" << endl; }
private:
	string _id;
};

class Soldier : public Person {
public:
	virtual void BuyTicket() { cout << "买票-优先" << endl; }
private:
	string _codename;
};

void Func(Person* ptr)
{
	// 这⾥可以看到虽然都是Person指针Ptr在调⽤BuyTicket
	// 但是跟ptr没关系，⽽是由ptr指向的对象决定的。
	ptr->BuyTicket();
}
int main()
{
	// 其次多态不仅仅发⽣在派⽣类对象之间，多个派⽣类继承基类，重写虚函数后
	// 多态也会发⽣在多个派⽣类之间。
	Person ps;
	Student st;
	Soldier sr;
	Func(&ps);
	Func(&st);
	Func(&sr);
	return 0;
}
// 所以为什么叫 重写/覆盖 重写是语法层的表达，表示重新写了一遍功能，
// 覆盖也描述的很精准，表示没重写之前，派生类的虚表指针所指向的虚函数表里记录的那个地址就是继承自基类的虚函数地址
// 而如果重写了，就相当于在虚函数表中把派生类虚表指针指向的那个虚函数地址覆盖成自己写的虚函数了














