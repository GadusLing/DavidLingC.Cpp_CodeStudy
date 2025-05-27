#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <assert.h>

using namespace std;

template<class K, class V>
struct AVLTreeNode
{
    // 需要parent指针，后续更新平衡因⼦可以看到
    std::pair<K, V> _kv;
    AVLTreeNode<K, V>* _left;
    AVLTreeNode<K, V>* _right;
    AVLTreeNode<K, V>* _parent;
    int _bf; // balance factor

    AVLTreeNode(const std::pair<K, V>& kv)
        : _kv(kv),
        _left(nullptr),
        _right(nullptr),
        _parent(nullptr),
        _bf(0)
    {}
};

template<class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;

public:
    bool Insert(const pair<K, V>& kv)
    {
        // 情况1：空树直接插入根节点
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }

        // 查找插入位置
        Node* parent = nullptr;
        Node* cur = _root;
        while (cur)
        {
            if (cur->_kv.first < kv.first)  // 新节点key比当前大，往右子树找
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_kv.first > kv.first)  // 新节点key比当前小，往左子树找
            {
                parent = cur;
                cur = cur->_left;
            }
            else  // key已存在，插入失败
            {
                return false;
            }
        }

        // 创建新节点并插入到正确位置
        cur = new Node(kv);
        if (parent->_kv.first < kv.first)
        {
            parent->_right = cur;  // 作为右孩子插入
        }
        else
        {
            parent->_left = cur;  // 作为左孩子插入
        }
        cur->_parent = parent;  // 设置父节点指针

        // 更新平衡因子（AVL核心部分）
        while (parent)
        {
            // 根据插入位置调整父节点平衡因子
            if (cur == parent->_left)
                parent->_bf--;  // 左子树高度增加
            else
                parent->_bf++;  // 右子树高度增加

            // 判断平衡状态
            if (parent->_bf == 0)
            {
                // 情况2：子树高度不变，更新终止
                break;
            }
            else if (parent->_bf == 1 || parent->_bf == -1)
            {
                // 情况3：子树高度变化，需要继续向上更新
                cur = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2)
            {
                // 情况4：出现不平衡，需要旋转处理
                if (parent->_bf == -2 && cur->_bf == -1)// 右单旋
                {
                    RotateR(parent);
                }
                else if (parent->_bf == 2 && cur->_bf == 1)// 左单旋
                {
                    RotateL(parent);
                }
                else if (parent->_bf == -2 && cur->_bf == 1)// 左右双旋
                {
                    RotateLR(parent);
                }
                else if (parent->_bf == 2 && cur->_bf == -1)// 左右双旋
                {
                    RotateRL(parent);
                }
                else assert(false);
                break;
            }
            else
            {
                // 非法平衡因子（理论上不会出现）
                assert(false);
            }
        }
        _size++;
        return true;
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
        parent->_bf = subL->_bf = 0;// 平衡了，要更新父和subL的平衡因子为0
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
        parent->_bf = subR->_bf = 0;// 平衡了，要更新父和subR的平衡因子为0
    }

    void  RotateLR(Node* parent)//左右双旋，复用前面写的左右单旋来实现，更省力
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf;

        RotateL(parent->_left);
        RotateR(parent);
        //双旋在旋转上很好理解，难点在于平衡因子的更新
        //在e or f不同的位置插入，虽然最终结构是一样的，但是会影响5 和 10的平衡因子的
        //还有一种情况是B拆不成e f，它就是个空节点
        //所以这里平衡因子的更新要分为3个情况来讨论，通过检查8本身平衡因子的变化，来确定究竟是在e还是f插入

        if (bf == -1)//意味着在e插入
        {
            subLR->_bf = 0;
            subL->_bf = 0;
            parent->_bf = 1;
        }
        else if (bf == 1)// 在f插入
        {
            subLR->_bf = 0;
            subL->_bf = -1;
            parent->_bf = 0;
        }
        else if (bf == 0)//意味着B是空的，这里还是手动置0，更健壮
        {
            subLR->_bf = 0;
            subL->_bf = 0;
            parent->_bf = 0;
        }
        else assert(false);//未知错误情况则跳出，健壮
    }

    void RotateRL(Node* parent) // 右左双旋（先右旋右子树，再左旋父节点）
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf;

        RotateR(parent->_right); // 对右子树右旋
        RotateL(parent);         // 对父节点左旋

        if (bf == 1)  // 在右子树的右子树插入
        {
            subRL->_bf = 0;
            subR->_bf = 0;
            parent->_bf = -1;
        }
        else if (bf == -1)  // 在右子树的左子树插入
        {
            subRL->_bf = 0;
            subR->_bf = 1;
            parent->_bf = 0;
        }
        else if (bf == 0)  // subRL是新节点
        {
            subRL->_bf = 0;
            subR->_bf = 0;
            parent->_bf = 0;
        }
        else assert(false);
    }

    void InOrder() 
    {
        _InOrder(_root);
        cout << endl;
    }

    bool IsBalanceTree() 
    {
        return _IsBalanceTree(_root);
    }

    Node* Find(const K& key)
    {
        Node* cur = _root;
        while (cur != nullptr)
        {
            if (key > cur->_kv.first)       // 目标值大于当前节点，向右子树查找
            {
                cur = cur->_right;
            }
            else if (key < cur->_kv.first) // 目标值小于当前节点，向左子树查找
            {
                cur = cur->_left;
            }
            else                           // 找到目标节点
            {
                return cur;
            }
        }
        return nullptr; // 未找到
    }

    int Height()
    {
        return _Height(_root);
    }

    size_t Size() const 
    {
        return _size;
    }

private:
    Node* _root = nullptr;
    size_t _size = 0;  // 新增成员变量记录节点数量

    void _InOrder(Node* root)
    {
        if (root == nullptr) return;

        _InOrder(root->_left);
        cout << root->_kv.first << " ";  // 假设存储的是键值对
        _InOrder(root->_right);
    }

    bool _IsBalanceTree(Node* root) 
    {
        if (root == nullptr) return true;
        
        // 检查当前节点的平衡因子是否正确
        int leftHeight = _Height(root->_left);
        int rightHeight = _Height(root->_right);
        int bf = rightHeight - leftHeight;

        if (abs(bf) > 1 || bf != root->_bf) 
        {
            cout << "Node:" << root->_kv.first
                << " bf:" << root->_bf
                << " real bf:" << bf << endl;
            return false;
        }

        // 递归检查左右子树
        return _IsBalanceTree(root->_left)
            && _IsBalanceTree(root->_right);
    }

    // 辅助方法：计算树的高度
    int _Height(Node* root) 
    {
        if (root == nullptr) return 0;
        return max(_Height(root->_left), _Height(root->_right)) + 1;
    }
};