#pragma once

#include <stdio.h>;
#include <utility>
using namespace std;


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
    {
        // �������в����ֵ��
        if (_root == nullptr) 
        {
            // ���1����Ϊ�գ�ֱ�Ӳ����½ڵ���Ϊ���ڵ�
            _root = new Node(kv);
            _root->_col = BLACK;  // ���ڵ����Ϊ��ɫ
            return true;
        }

        // ���Ҳ���λ��
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
                return false;  // ���Ѵ��ڣ�����ʧ��
            }
        }

        // �����½ڵ㣨Ĭ��Ϊ��ɫ��
        cur = new Node(kv);
        cur->_col = RED;

        // ���½ڵ����ӵ����ڵ�
        if (parent->_kv.first < kv.first) 
        {
            parent->_right = cur;
        }
        else 
        {
            parent->_left = cur;
        }
        cur->_parent = parent;

        // �����ƽ����������ڵ�Ϊ��ɫʱ����Ҫ������
        while (parent && parent->_col == RED) 
        {
            Node* grandfather = parent->_parent;  // �游�ڵ�

            // ���A�����ڵ����游�ڵ������
            if (parent == grandfather->_left) 
            {
                Node* uncle = grandfather->_right;  // ����ڵ�

                // ���A1�����������Ϊ��ɫ
                if (uncle && uncle->_col == RED) 
                {
                    // ��ɫ����
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;

                    // �������ϼ��
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else 
                {  // ���A2�����岻���ڻ�Ϊ��ɫ
                    if (cur == parent->_left) 
                    {
                        // ���A2a����ǰ�ڵ��Ǹ��ڵ�����ӣ����������
                        // �����游�ڵ�
                        RotateR(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else 
                    {
                        // ���A2b����ǰ�ڵ��Ǹ��ڵ���Һ��ӣ����������
                        // ���������ڵ㣬�������游�ڵ�
                        RotateL(parent);
                        RotateR(grandfather);
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    break;  // ��ת������ƽ�⣬�˳�ѭ��
                }
            }
            // ���B�����ڵ����游�ڵ���Һ���
            else 
            {
                Node* uncle = grandfather->_left;  // ����ڵ�

                // ���B1�����������Ϊ��ɫ
                if (uncle && uncle->_col == RED) 
                {
                    // ��ɫ����
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;

                    // �������ϼ��
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else 
                {  // ���B2�����岻���ڻ�Ϊ��ɫ
                    if (cur == parent->_right) {
                        // ���B2a����ǰ�ڵ��Ǹ��ڵ���Һ��ӣ����������
                        // �����游�ڵ�
                        RotateL(grandfather);
                        parent->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else 
                    {
                        // ���B2b����ǰ�ڵ��Ǹ��ڵ�����ӣ����������
                        // ���������ڵ㣬�������游�ڵ�
                        RotateR(parent);
                        RotateL(grandfather);
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    break;  // ��ת������ƽ�⣬�˳�ѭ��
                }
            }
        }

        // ȷ�����ڵ�Ϊ��ɫ
        _root->_col = BLACK;
        return true;
    }
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

