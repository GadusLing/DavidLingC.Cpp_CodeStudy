#pragma once

#include <stdio.h>;
#include <utility>
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
template<class K, class V>
struct RBTreeNode 
{
    // 成员变量
    pair<K, V> _kv;                  // 键值对数据
    RBTreeNode<K, V>* _left;         // 左子节点指针
    RBTreeNode<K, V>* _right;        // 右子节点指针
    RBTreeNode<K, V>* _parent;       // 父节点指针（红黑树平衡调整需要）
    Colour _col;                     // 节点颜色标识

    /**
     * 构造函数
     * @param kv 初始化用的键值对
     * 默认初始化：
     * - 左右子节点置空
     * - 父节点置空
     * - 新节点默认红色（符合红黑树插入规则）
     */
    RBTreeNode(const pair<K, V>& kv)
        : _kv(kv),
        _left(nullptr),
        _right(nullptr),
        _parent(nullptr),
        _col(RED)  // 新节点初始为红色，插入后再调整
    {}
};

/**
 * 红黑树（Red-Black Tree）模板类
 * @tparam K 键（Key）类型，需支持比较操作
 * @tparam V 值（Value）类型
 */
template<class K, class V>
class RBTree 
{
    typedef RBTreeNode<K, V> Node;  // 节点类型简写
public:
    // 默认构造函数（隐式初始化 _root 为 nullptr）
    RBTree() = default;

    // 禁用拷贝构造和赋值（红黑树通常不直接复制）
    RBTree(const RBTree&) = delete;
    RBTree& operator=(const RBTree&) = delete;

    // 析构函数（需后续实现递归释放节点）
    ~RBTree() 
    {
        _Destroy(_root);
    }

    // 基本操作接口（示例声明）
    bool Insert(const pair<K, V>& kv);  // 插入键值对
    {
        // 向红黑树中插入键值对
        if (_root == nullptr) 
        {
            // 情况1：树为空，直接插入新节点作为根节点
            _root = new Node(kv);
            _root->_col = BLACK;  // 根节点必须为黑色
            return true;
        }

        // 查找插入位置
        Node* parent = nullptr;
        Node* cur = _root;
        while (cur) 
        {
            if (cur->_kv.first < kv.first) 
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_kv.first > kv.first) 
            {
                parent = cur;
                cur = cur->_left;
            }
            else 
            {
                return false;  // 键已存在，插入失败
            }
        }

        // 创建新节点（默认为红色）
        cur = new Node(kv);
        cur->_col = RED;

        // 将新节点连接到父节点
        if (parent->_kv.first < kv.first) 
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
        return true;
    }
    Node* Find(const K& key);           // 查找键对应的节点
    bool Remove(const K& key);          // 删除键值对

private:
    // 私有辅助方法
    void _Destroy(Node* root);          // 递归销毁树
    void _RotateLeft(Node* parent);     // 左旋操作
    void _RotateRight(Node* parent);    // 右旋操作

private:
    Node* _root = nullptr;  // 根节点指针（默认初始化为空）
};

