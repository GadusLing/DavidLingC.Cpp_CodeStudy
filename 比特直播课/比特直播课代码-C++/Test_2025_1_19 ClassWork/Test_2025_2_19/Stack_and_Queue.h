#pragma once

#include <iostream>
#include <deque>

namespace LDW
{
    template<class T, class Con = std::deque<T>>
    class stack
    {
    public:
        stack(){}//  _c 是 std::deque<T> 类型，它的默认构造函数会自动创建一个空的容器，stack 的构造函数不需要做任何事情
        void push(const T& x)
        {
			_c.push_back(x);
        }
        void pop()
        {
			_c.pop_back();
        }
        T& top()
        {
			return _c.back();
        }
        const T& top()const
        {
			return _c.back();
        }
        size_t size()const
        {
			return _c.size();
        }
        bool empty()const
        {
			return _c.empty();
        }

    private:
        Con _c;// 这里会自动调用 std::deque<T> 的默认构造函数，创建一个空的 deque
    };


    template<class T, class Con = std::deque<T>>
    class queue
    {
    public:
        queue(){}
        void push(const T& x)
        {
			_c.push_back(x);
        }
        void pop()
        {
			_c.pop_front();
        }
        T& back()
        {
			return _c.back();
        }
        const T& back()const
        {
			return _c.back();
        }
        T& front()
        {
			return _c.front();
        }
        const T& front()const
        {
			return _c.front();
        }
        size_t size()const
        {
			return _c.size();
        }
        bool empty()const
        {
			return _c.empty();
        }

    private:
        Con _c;
    };
};
