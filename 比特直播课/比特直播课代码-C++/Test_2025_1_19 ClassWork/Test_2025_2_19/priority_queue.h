#include <vector>
#include <functional>
#include <algorithm>

namespace LDW
{
    template <class T>
    class Less
    {
    public:
        bool operator()(const T& l, const T& r) const
        {
            return l < r;
        }
    };

    template<class T>
    class Greater
    {
    public:
        bool operator()(const T& l, const T& r) const
        {
            return l > r;
        }
    };

    template <class T, class Container = std::vector<T>, class Compare = Less<T>>
    class priority_queue
    {
    public:
        priority_queue()
            : _c()
            , _comp()
        {}

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
            : _c(first, last)// 用迭代器范围 [first, last) 来初始化容器 _c，将 [first, last) 范围内的元素复制到 _c 中
        {
            // 从最后一个非叶子节点开始向下调整_c为堆结构
            for (int i = (_c.size() - 1) / 2; i >= 0; --i)
            {
                adjust_down(i);
            }
        }

        bool empty() const
        {
            return _c.empty();
        }

        size_t size() const
        {
            return _c.size();
        }

        T& top() const
        {
            return _c.front();
        }

        void push(const T& x)
        {
            _c.push_back(x);
            adjust_up(_c.size() - 1);
        }

        void pop()
        {
            if (_c.empty())
                return;

            std::swap(_c[0], _c[_c.size() - 1]);
            _c.pop_back();
            adjust_down(0);
        }

    private:
        void adjust_up(size_t child)
        {
            Compare com;
            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                if (com(_c[parent], _c[child]))
                {
                    std::swap(_c[parent], _c[child]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }

        void adjust_down(size_t parent)
        {
            Compare com;
            size_t child = parent * 2 + 1;
            while (child < _c.size())
            {
                if (child + 1 < _c.size() && com(_c[child], _c[child + 1]))
                {
                    child += 1;
                }

                if (com(_c[parent], _c[child]))
                {
                    std::swap(_c[parent], _c[child]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }

    private:
        Container _c;
        Compare _comp;
    };
};