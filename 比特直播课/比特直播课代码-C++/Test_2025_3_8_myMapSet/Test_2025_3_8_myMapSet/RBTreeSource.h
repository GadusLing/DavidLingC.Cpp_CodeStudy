#pragma once

#include <stdio.h>
#include <utility>
#include <vector>
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


    // ���������ӿڣ�ʾ��������
    bool Insert(const pair<K, V>& kv) // �����ֵ��
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

    void  RotateR(Node* parent)//�ҵ���
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;

        parent->_left = subLR;// ����������ұ��Ƶ��������
        subL->_right = parent;// ���������������ұ�

        if (subLR)//subLR�п���Ϊ��Ŷ
            subLR->_parent = parent;//Ҫ�ǵø��±��ƶ��ڵ��parent��AVL��һ�ڣ�2:16:50__ԭ��ָ��5������Ҫָ��10
        Node* parentParent = parent->_parent;
        parent->_parent = subL;

        //if(parnetParent == nullptr)
        if (parent == _root)// ��ԭ����parent���Ǹ�ʱ
        {
            _root = subL;
            subL->_parent = nullptr;
        }
        else// �ֲ�����תʱ
        {
            if (parent == parentParent->_left)//������Ǹ�������ڵ�
            {
                parentParent->_left = subL;//����subLҪ������ԭ������λ��
            }
            else
            {
                parentParent->_right = subL;//ͬ������ԭ�����ұ�
            }
            subL->_parent = parentParent;//subL�ĸ��ױ���˸���
        }
    }

    void  RotateL(Node* parent)//����
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;

        parent->_right = subRL;// �ұ�����������Ƶ������ұ�
        subR->_left = parent;// ������ұ����������

        if (subRL)//subRL�п���Ϊ��Ŷ
            subRL->_parent = parent;//Ҫ�ǵø��±��ƶ��ڵ��parent
        Node* parentParent = parent->_parent;
        parent->_parent = subR;

        //if(parnetParent == nullptr)
        if (parent == _root)// ��ԭ����parent���Ǹ�ʱ
        {
            _root = subR;
            subR->_parent = nullptr;
        }
        else// �ֲ�����תʱ
        {
            if (parent == parentParent->_left)//������Ǹ�������ڵ�
            {
                parentParent->_left = subR;//����subRҪ������ԭ������λ��
            }
            else
            {
                parentParent->_right = subR;//ͬ������ԭ�����ұ�
            }
            subR->_parent = parentParent;//subR�ĸ��ױ���˸���
        }
    }

    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }

    /**
     * ��������Ƿ�����ƽ������
     * @param root ��ǰ���Ľڵ�ָ��
     * @param blackNum ��ǰ·���ϵĺ�ɫ�ڵ����
     * @param refNum ��Ϊ�ο��ĺ�ɫ�ڵ���������һ��·���ĺ�ɫ�ڵ�����
     * @return �������������������true�����򷵻�false
     */
    bool Check(Node* root, int blackNum, const int refNum) //ǰ��ݹ����
    {
        // �ݹ��������սڵ㣨Ҷ�ӽڵ���ӽڵ㣩
        if (root == nullptr) 
        {
            // ���ߵ��սڵ�ʱ��˵��һ��·���Ѿ�����
            // ��鵱ǰ·���ĺ�ɫ�ڵ����Ƿ���ο�ֵһ��
            if (refNum != blackNum) 
            {
                cout << "���ں�ɫ������������ȵ�·��" << endl;
                return false;
            }
            return true;
        }

        // ����Ƿ��������ĺ�ɫ�ڵ㣨�����������������ɫ�ڵ����ڣ�
        // ͨ����鵱ǰ�ڵ���丸�ڵ��Ƿ���ڲ��Ҷ��Ǻ�ɫ���ж�
        if (root->_col == RED && root->_parent && root->_parent->_col == RED)
        {
            cout << root->_kv.first << "���������ĺ�ɫ���" << endl;
            return false;
        }

        // �����ǰ�ڵ��Ǻ�ɫ�����Ӻ�ɫ�ڵ����
        if (root->_col == BLACK) 
        {
            blackNum++;
        }

        // �ݹ�����������
        return Check(root->_left, blackNum, refNum)
            && Check(root->_right, blackNum, refNum);
    }

    /**
     * ������ƽ����ӿ�
     * @return �������ƽ��ĺ��������true�����򷵻�false
     */
    bool IsBalanceTree()
    {
        // ������ƽ���
        if (_root == nullptr)
            return true;

        // ���ڵ�����Ǻ�ɫ�����������2��
        if (_root->_col == RED)
            return false;

        // ����ο�ֵ���Ӹ��ڵ㵽����Ҷ�ӽڵ�ĺ�ɫ�ڵ�����
        int refNum = 0;
        Node* cur = _root;
        while (cur) 
        {
            if (cur->_col == BLACK) 
            {
                ++refNum;
            }
            cur = cur->_left;  // һֱ������
        }

        // �Ӹ��ڵ㿪ʼ��飬��ʼ��ɫ�ڵ���Ϊ0
        return Check(_root, 0, refNum);
    }


    Node* Find(const K& key);           // ���Ҽ���Ӧ�Ľڵ�
    bool Remove(const K& key);          // ɾ����ֵ��

private:
    // ˽�и�������
    void _RotateLeft(Node* parent);     // ��������
    void _RotateRight(Node* parent);    // ��������

    void _InOrder(Node* root)
    {
        if (root == nullptr) return;

        _InOrder(root->_left);
        cout << root->_kv.first << " ";  // ����洢���Ǽ�ֵ��
        _InOrder(root->_right);
    }

    Node* _root = nullptr;  // ���ڵ�ָ�루Ĭ�ϳ�ʼ��Ϊ�գ�
};

