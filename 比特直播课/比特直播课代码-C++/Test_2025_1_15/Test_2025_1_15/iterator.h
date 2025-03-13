#pragma once

// 反向迭代器的实现
template<class Iterator, class Ref, class Ptr>
struct ReverseIterator
{
	//typedef ReverseIterator<Iterator, Ref, Ptr> Self;
	using Self = ReverseIterator<Iterator, Ref, Ptr>;

	ReverseIterator(Iterator it)
		:_it(it)
	{}
	// 不需要写析构，因为迭代器不负责释放资源，内部没有管理资源的需求，资源释放是容器的事情
	// 不用写析构一般就不用写拷贝构造

	Ref operator*() // 重载解引用
	{
		return *_it; // 这里注意，STL库里有些细节和我们不同  比如STL解引用结的是前一个位置,而且是用了个tmp    *--tmp
		// 其实是因为STL库里rbegin()返回的是end()，rend()返回的是begin()   我们是在rebegin那边改的 本质都一样 STL主要为了对称
	}

	Ptr operator->()// 重载->  本来应该是两个箭头，编译器为了可读性省略了一个
	{
		return &(operator*());
	}

	Self& operator++()// 重载++ 前置
	{
		--_it;
		return *this;
	}

	Self operator++(int)// 重载++ 后置 int充当占位符 标明后置
	{
		Self temp = *this; // 保存当前状态
		--_it; // 递增迭代器
		return temp; // 返回之前的状态
	}

	Self& operator--()// 重载--
	{
		++_it;
		return *this;
	}

	Self operator--(int)// 重载--，后置 int充当占位符 标明后置
	{
		Self temp = *this; // 保存当前状态
		++_it; // 递减迭代器
		return temp; // 返回之前的状态
	}

	bool operator!=(const Self& s) const//重载 !=
	{
		return _it != s._it;
	}

	bool operator==(const Self& s) const// 重载==
	{
		return _it == s._it;
	}



	Iterator _it;


};
