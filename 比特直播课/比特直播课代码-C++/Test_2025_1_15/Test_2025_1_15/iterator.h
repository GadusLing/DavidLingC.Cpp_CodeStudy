#pragma once

// �����������ʵ��
template<class Iterator, class Ref, class Ptr>
struct ReverseIterator
{
	//typedef ReverseIterator<Iterator, Ref, Ptr> Self;
	using Self = ReverseIterator<Iterator, Ref, Ptr>;

	ReverseIterator(Iterator it)
		:_it(it)
	{}
	// ����Ҫд��������Ϊ�������������ͷ���Դ���ڲ�û�й�����Դ��������Դ�ͷ�������������
	// ����д����һ��Ͳ���д��������

	Ref operator*() // ���ؽ�����
	{
		return *_it; // ����ע�⣬STL������Щϸ�ں����ǲ�ͬ  ����STL�����ý����ǰһ��λ��,���������˸�tmp    *--tmp
		// ��ʵ����ΪSTL����rbegin()���ص���end()��rend()���ص���begin()   ��������rebegin�Ǳ߸ĵ� ���ʶ�һ�� STL��ҪΪ�˶Գ�
	}

	Ptr operator->()// ����->  ����Ӧ����������ͷ��������Ϊ�˿ɶ���ʡ����һ��
	{
		return &(operator*());
	}

	Self& operator++()// ����++ ǰ��
	{
		--_it;
		return *this;
	}

	Self operator++(int)// ����++ ���� int�䵱ռλ�� ��������
	{
		Self temp = *this; // ���浱ǰ״̬
		--_it; // ����������
		return temp; // ����֮ǰ��״̬
	}

	Self& operator--()// ����--
	{
		++_it;
		return *this;
	}

	Self operator--(int)// ����--������ int�䵱ռλ�� ��������
	{
		Self temp = *this; // ���浱ǰ״̬
		++_it; // �ݼ�������
		return temp; // ����֮ǰ��״̬
	}

	bool operator!=(const Self& s) const//���� !=
	{
		return _it != s._it;
	}

	bool operator==(const Self& s) const// ����==
	{
		return _it == s._it;
	}



	Iterator _it;


};
