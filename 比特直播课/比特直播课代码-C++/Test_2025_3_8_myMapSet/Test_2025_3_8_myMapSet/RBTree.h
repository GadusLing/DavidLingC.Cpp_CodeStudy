#pragma once

// ��ɫö�����ͣ����ں�����ڵ���ɫ��ʶ��
enum Colour 
{
    RED,    // ��ɫ
    BLACK   // ��ɫ
};

/**
 * ������ڵ�ģ����
 * @tparam K ������
 * @tparam V ֵ����
 * ����key/value�ṹ�洢����
 */
template<class K, class V>
struct RBTreeNode 
{
    // ��Ա����
    pair<K, V> _kv;                  // ��ֵ������
    RBTreeNode<K, V>* _left;         // ���ӽڵ�ָ��
    RBTreeNode<K, V>* _right;        // ���ӽڵ�ָ��
    RBTreeNode<K, V>* _parent;       // ���ڵ�ָ�루�����ƽ�������Ҫ��
    Colour _col;                     // �ڵ���ɫ��ʶ

    /**
     * ���캯��
     * @param kv ��ʼ���õļ�ֵ��
     * Ĭ�ϳ�ʼ����
     * - �����ӽڵ��ÿ�
     * - ���ڵ��ÿ�
     * - �½ڵ�Ĭ�Ϻ�ɫ�����Ϻ�����������
     */
    RBTreeNode(const pair<K, V>& kv)
        : _kv(kv),
        _left(nullptr),
        _right(nullptr),
        _parent(nullptr),
        _col(RED)  // �½ڵ��ʼΪ��ɫ��������ٵ���
    {}
};

/**
 * �������Red-Black Tree��ģ����
 * @tparam K ����Key�����ͣ���֧�ֱȽϲ���
 * @tparam V ֵ��Value������
 */
template<class K, class V>
class RBTree 
{
    typedef RBTreeNode<K, V> Node;  // �ڵ����ͼ�д
public:
    // Ĭ�Ϲ��캯������ʽ��ʼ�� _root Ϊ nullptr��
    RBTree() = default;

    // ���ÿ�������͸�ֵ�������ͨ����ֱ�Ӹ��ƣ�
    RBTree(const RBTree&) = delete;
    RBTree& operator=(const RBTree&) = delete;

    // ���������������ʵ�ֵݹ��ͷŽڵ㣩
    ~RBTree() 
    {
        _Destroy(_root);
    }

    // ���������ӿڣ�ʾ��������
    bool Insert(const pair<K, V>& kv);  // �����ֵ��
    Node* Find(const K& key);           // ���Ҽ���Ӧ�Ľڵ�
    bool Remove(const K& key);          // ɾ����ֵ��

private:
    // ˽�и�������
    void _Destroy(Node* root);          // �ݹ�������
    void _RotateLeft(Node* parent);     // ��������
    void _RotateRight(Node* parent);    // ��������

private:
    Node* _root = nullptr;  // ���ڵ�ָ�루Ĭ�ϳ�ʼ��Ϊ�գ�
};

