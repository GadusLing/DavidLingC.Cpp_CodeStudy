#pragma once

#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;


// 颜色枚举类型（用于红黑树节点颜色标识）
enum Colour 
{
    RED,    // 红色
    BLACK   // 黑色
};

/**
 * 红黑树节点模板类
 * @tparam K 键类型
 * @tparam V 值类型
 * 采用key/value结构存储数据
 */
template<class T>
struct RBTreeNode 
{
    // 成员变量
    T _data;                  // 键值对数据
    RBTreeNode<T>* _left;         // 左子节点指针
    RBTreeNode<T>* _right;        // 右子节点指针
    RBTreeNode<T>* _parent;       // 父节点指针（红黑树平衡调整需要）
    Colour _col;                     // 节点颜色标识

    /**
     * 构造函数
     * @param data 初始化用的键值对
     * 默认初始化：
     * - 左右子节点置空
     * - 父节点置空
     * - 新节点默认红色（符合红黑树插入规则）
     */
    RBTreeNode(const T& data)
        : _data(data),
        _left(nullptr),
        _right(nullptr),
        _parent(nullptr),
        _col(RED)  // 新节点初始为红色，插入后再调整
    {}
};

template<class T, class Ref, class Ptr>
struct __TreeIterator
{
    typedef RBTreeNode<T> Node;
    typedef __TreeIterator<T, Ref, Ptr> Self;
    Node* _node;
    Node* _root;

    __TreeIterator(Node* node, Node* root)
        :_node(node)
        ,_root(root)
    {}

    Ref operator*()//解引用
    {
        return _node->_data;
    }

    Ptr operator->()//访问成员
    {
        return &_node->_data;
    }

    Self& operator++() 
    {
        if (_node->_right)  // 当前节点有右子树
        {
            // 情况1：后继是右子树的最左节点（即右子树的最小值）
            _node = _node->_right;  // 先进入右子树
            while (_node->_left)    // 然后一路向左到底
            {
                _node = _node->_left;
            }
            // 最终 _node 是右子树的最左节点
        }
        else  // 当前节点没有右子树
        {
            // 情况2：后继是最近的“左祖先”（即第一个使当前节点在其左子树中的祖先）
            Node* cur = _node;
            Node* parent = cur->_parent;
            // 向上回溯，直到当前节点是父节点的左孩子
            while (parent && cur == parent->_right) 
            {
                cur = parent;          // 当前节点上移
                parent = parent->_parent; // 父节点继续上移
            }
            // 退出循环时：
            // - parent 为 nullptr（说明当前节点是整棵树的最右节点，无后继）
            // - 或 cur 是 parent 的左孩子（此时 parent 就是后继）
            _node = parent;  // 更新为后继节点（可能是 nullptr）
        }
        return *this;  // 返回更新后的迭代器（支持链式操作，如 ++iter）
    }

    Self& operator--()
    {
        if (_node == nullptr)  // 当前是 end() 位置（即空节点）
        {
            // --end() 应当指向整棵树的最右节点（即最大值）
            Node* rightMost = _root;  // 假设 _root 是树的根节点
            while (rightMost && rightMost->_right)
            {
                rightMost = rightMost->_right;
            }
            _node = rightMost;  // 更新为最右节点
        }
        else if (_node->_left)  // 如果当前节点有左子树
        {
            // 找左子树的最右节点（即左子树的最大值）
            Node* rightMost = _node->_left;
            while (rightMost->_right)
            {
                rightMost = rightMost->_right;
            }
            _node = rightMost;  // 更新为左子树的最右节点
        }
        else  // 当前节点没有左子树
        {
            // 向上查找，直到当前节点是父节点的右孩子
            Node* cur = _node;
            Node* parent = cur->_parent;
            while (parent && cur == parent->_left)
            {
                cur = parent;
                parent = cur->_parent;
            }
            _node = parent;  // 返回第一个“父节点是右祖先”的节点
        }
        return *this;  // 返回更新后的迭代器（支持链式操作）
    }

    bool operator!=(const Self& s) const
    {
        return _node != s._node;
    }

    bool operator==(const Self& s) const
    {
        return _node == s._node;
    }

};



template<class K, class T, class KeyOFT>
class RBTree 
{
    typedef RBTreeNode<T> Node;  // 节点类型简写
public:
    typedef __TreeIterator<T, T&, T*> Iterator;
    typedef __TreeIterator<T, const T&, const T*> ConstIterator;

    Iterator Begin()
    {
        Node* minLeft = _root;
        while (minLeft && minLeft->_left)
        {
            minLeft = minLeft->_left;
        }
        return Iterator(minLeft, _root);
    }

    Iterator End()
    {
        return Iterator(nullptr, _root);
    }

    ConstIterator Begin() const
    {
        Node* minLeft = _root;
        while (minLeft && minLeft->_left)
        {
            minLeft = minLeft->_left;
        }
        return ConstIterator(minLeft, _root);
    }

    ConstIterator End() const
    {
        return ConstIterator(nullptr, _root);
    }

    // 默认构造函数（隐式初始化 _root 为 nullptr）
    RBTree() = default;

    // 禁用拷贝构造和赋值（红黑树通常不直接复制）
    RBTree(const RBTree&) = delete;
    RBTree& operator=(const RBTree&) = delete;


    // 基本操作接口（示例声明）
    pair<Iterator, bool> Insert(const T& data) // 插入键值对
    {
        // 向红黑树中插入键值对
        if (_root == nullptr) 
        {
            // 情况1：树为空，直接插入新节点作为根节点
            _root = new Node(data);
            _root->_col = BLACK;  // 根节点必须为黑色
            return { Iterator(_root, _root), true };
        }

        // 查找插入位置
        Node* parent = nullptr;
        Node* cur = _root;

        KeyOFT kot;

        while (cur) 
        {
            if (kot(cur->_data) < kot(data)) 
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (kot(cur->_data) > kot(data))
            {
                parent = cur;
                cur = cur->_left;
            }
            else 
            {
                return { Iterator(cur, _root), false };  // 键已存在，插入失败
            }
        }

        // 创建新节点（默认为红色）
        cur = new Node(data);
        Node* newnode = cur;
        cur->_col = RED;

        // 将新节点连接到父节点
        if (kot(parent->_data) < kot(data))
        {
            parent->_right = cur;
        }
        else 
        {
            parent->_left = cur;
        }
        cur->_parent = parent;

        // 红黑树平衡调整（父节点为红色时才需要调整）
        while (parent && parent->_col == RED) 
        {
            Node* grandfather = parent->_parent;  // 祖父节点

            // 情况A：父节点是祖父节点的左孩子
            if (parent == grandfather->_left) 
            {
                Node* uncle = grandfather->_right;  // 叔叔节点

                // 情况A1：叔叔存在且为红色
                if (uncle && uncle->_col == RED) 
                {
                    // 变色处理
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;

                    // 继续向上检查
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else 
                {  // 情况A2：叔叔不存在或为黑色
                    if (cur == parent->_left) 
                    {
                        // 情况A2a：当前节点是父节点的左孩子（左左情况）
                        // 右旋祖父节点
                        RotateR(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else 
                    {
                        // 情况A2b：当前节点是父节点的右孩子（左右情况）
                        // 先左旋父节点，再右旋祖父节点
                        RotateL(parent);
                        RotateR(grandfather);
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    break;  // 旋转后子树平衡，退出循环
                }
            }
            // 情况B：父节点是祖父节点的右孩子
            else 
            {
                Node* uncle = grandfather->_left;  // 叔叔节点

                // 情况B1：叔叔存在且为红色
                if (uncle && uncle->_col == RED) 
                {
                    // 变色处理
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;

                    // 继续向上检查
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else 
                {  // 情况B2：叔叔不存在或为黑色
                    if (cur == parent->_right) {
                        // 情况B2a：当前节点是父节点的右孩子（右右情况）
                        // 左旋祖父节点
                        RotateL(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else 
                    {
                        // 情况B2b：当前节点是父节点的左孩子（右左情况）
                        // 先右旋父节点，再左旋祖父节点
                        RotateR(parent);
                        RotateL(grandfather);
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    break;  // 旋转后子树平衡，退出循环
                }
            }
        }

        // 确保根节点为黑色
        _root->_col = BLACK;
        return { Iterator(newnode, _root), true };
    }

    void  RotateR(Node* parent)//右单旋
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;

        parent->_left = subLR;// 左边那条的右边移到父的左边
        subL->_right = parent;// 父变成左边那条的右边

        if (subLR)//subLR有可能为空哦
            subLR->_parent = parent;//要记得更新被移动节点的parent，AVL那一期，2:16:50__原本指向5，现在要指向10
        Node* parentParent = parent->_parent;
        parent->_parent = subL;

        //if(parnetParent == nullptr)
        if (parent == _root)// 当原本的parent就是根时
        {
            _root = subL;
            subL->_parent = nullptr;
        }
        else// 局部的旋转时
        {
            if (parent == parentParent->_left)//如果父是父父的左节点
            {
                parentParent->_left = subL;//现在subL要来接替原来父的位置
            }
            else
            {
                parentParent->_right = subL;//同理，接替原来的右边
            }
            subL->_parent = parentParent;//subL的父亲变成了父父
        }
    }

    void  RotateL(Node* parent)//左单旋
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;

        parent->_right = subRL;// 右边那条的左边移到父的右边
        subR->_left = parent;// 父变成右边那条的左边

        if (subRL)//subRL有可能为空哦
            subRL->_parent = parent;//要记得更新被移动节点的parent
        Node* parentParent = parent->_parent;
        parent->_parent = subR;

        //if(parnetParent == nullptr)
        if (parent == _root)// 当原本的parent就是根时
        {
            _root = subR;
            subR->_parent = nullptr;
        }
        else// 局部的旋转时
        {
            if (parent == parentParent->_left)//如果父是父父的左节点
            {
                parentParent->_left = subR;//现在subR要来接替原来父的位置
            }
            else
            {
                parentParent->_right = subR;//同理，接替原来的右边
            }
            subR->_parent = parentParent;//subR的父亲变成了父父
        }
    }

    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }

    /**
     * 检查红黑树是否满足平衡条件
     * @param root 当前检查的节点指针
     * @param blackNum 当前路径上的黑色节点计数
     * @param refNum 作为参考的黑色节点数量（第一条路径的黑色节点数）
     * @return 如果满足红黑树条件返回true，否则返回false
     */
    bool Check(Node* root, int blackNum, const int refNum) //前序递归遍历
    {
        // 递归基：到达空节点（叶子节点的子节点）
        if (root == nullptr) 
        {
            // 当走到空节点时，说明一条路径已经走完
            // 检查当前路径的黑色节点数是否与参考值一致
            if (refNum != blackNum) 
            {
                cout << "存在黑色结点的数量不相等的路径" << endl;
                return false;
            }
            return true;
        }

        // 检查是否有连续的红色节点（红黑树不允许两个红色节点相邻）
        // 通过检查当前节点和其父节点是否存在并且都是红色来判断
        if (root->_col == RED && root->_parent && root->_parent->_col == RED)
        {
            cout << root->_data.first << "存在连续的红色结点" << endl;
            return false;
        }

        // 如果当前节点是黑色，增加黑色节点计数
        if (root->_col == BLACK) 
        {
            blackNum++;
        }

        // 递归检查左右子树
        return Check(root->_left, blackNum, refNum)
            && Check(root->_right, blackNum, refNum);
    }

    /**
     * 公开的平衡检查接口
     * @return 如果树是平衡的红黑树返回true，否则返回false
     */
    bool IsBalanceTree()
    {
        // 空树是平衡的
        if (_root == nullptr)
            return true;

        // 根节点必须是黑色（红黑树性质2）
        if (_root->_col == RED)
            return false;

        // 计算参考值：从根节点到最左叶子节点的黑色节点数量
        int refNum = 0;
        Node* cur = _root;
        while (cur) 
        {
            if (cur->_col == BLACK) 
            {
                ++refNum;
            }
            cur = cur->_left;  // 一直向左走
        }

        // 从根节点开始检查，初始黑色节点数为0
        return Check(_root, 0, refNum);
    }


    Iterator Find(const K& key)          // 查找键对应的节点
    {
        KeyOFT kot;
        Node* cur = _root;
        while (cur != nullptr)
        {
            if (key > kot(cur->_data))       // 目标值大于当前节点，向右子树查找
            {
                cur = cur->_right;
            }
            else if (key < kot(cur->_data)) // 目标值小于当前节点，向左子树查找
            {
                cur = cur->_left;
            }
            else                           // 找到目标节点
            {
                return Iterator(cur, _root);
            }
        }
        return End(); // 未找到 
    }
    bool Remove(const K& key);          // 删除键值对

private:
    // 私有辅助方法
    void _RotateLeft(Node* parent);     // 左旋操作
    void _RotateRight(Node* parent);    // 右旋操作

    void _InOrder(Node* root)
    {
        if (root == nullptr) return;

        _InOrder(root->_left);
        cout << root->_data.first << " ";  // 假设存储的是键值对
        _InOrder(root->_right);
    }

    Node* _root = nullptr;  // 根节点指针（默认初始化为空）
};

