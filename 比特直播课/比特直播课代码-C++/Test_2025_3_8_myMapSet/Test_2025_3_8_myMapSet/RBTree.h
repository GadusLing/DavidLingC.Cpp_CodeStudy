#pragma once

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

