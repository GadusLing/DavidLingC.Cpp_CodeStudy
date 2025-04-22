#include <iostream>
#include <string>
using namespace std;

template<class K, class V>
struct BSTreeNode 
{
    K _key;
    V _value;
    BSTreeNode* _left;
    BSTreeNode* _right;
    BSTreeNode(const K& key, const V& value)
        : _key(key)
        , _value(value)
        , _left(nullptr)
        , _right(nullptr) 
    {}
};

template<class K,class V>
class BSTree 
{
    typedef BSTreeNode<K, V> Node;
public:
    bool Insert(const K& key, const V& value) 
    {
        if (_root == nullptr) 
        {
            _root = new Node(key, value);
            return true;
        }

        Node* cur = _root;
        Node* parent = nullptr;
        while (cur) 
        {
            if (key < cur->_key) 
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (key > cur->_key) 
            {
                parent = cur;
                cur = cur->_right;
            }
            else return false; // �ؼ����Ѵ���
            
        }

        if (key < parent->_key) parent->_left = new Node(key, value);
        else parent->_right = new Node(key, value);

        return true;
    }

    Node* Find(const K& key) 
    {
        Node* cur = _root;
        while (cur) 
        {
            if (key < cur->_key) cur = cur->_left;
            else if (key > cur->_key) cur = cur->_right;
            else return cur;
        }
        return nullptr;
    }

    bool Erase(const K& key) 
    {
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur && cur->_key != key) 
        {
            parent = cur;
            if (key < cur->_key) cur = cur->_left;
            else cur = cur->_right;
        }
        if (cur == nullptr) return false;

        // ɾ���ڵ�����������
        if (cur->_left && cur->_right) 
        {
            Node* minRight = cur->_right;
            Node* minRightParent = cur;

            while (minRight->_left) 
            {
                minRightParent = minRight;
                minRight = minRight->_left;
            }

            cur->_key = minRight->_key;
            cur->_value = minRight->_value;

            // �滻���ɾ�� minRight �ڵ�
            cur = minRight;
            parent = minRightParent;
        }

        // ɾ���ڵ���һ�����ӻ�û�к���
        Node* child = (cur->_left != nullptr) ? cur->_left : cur->_right;

        if (parent == nullptr) _root = child;
        else 
        {
            if (parent->_left == cur) parent->_left = child;
            else parent->_right = child;
        }

        delete cur;
        return true;
    }

    void InOrder() 
    {
        _InOrder(_root);
    }

    void _InOrder(Node* root) 
    {
        if (root == nullptr) return;
        _InOrder(root->_left);
        cout << root->_key << " : " << root->_value << endl;
        _InOrder(root->_right);
    }

private:
    Node* _root = nullptr;
};

void TestBSTree() 
{
    BSTree<string, string> dict;
    dict.Insert("insert", "����");
    dict.Insert("erase", "ɾ��");
    dict.Insert("left", "���");
    dict.Insert("string", "�ַ���");

    string str;
    cout << "������Ӣ�ĵ��ʽ��в�ѯ (Ctrl+Z ��ֹ):" << endl;
    while (cin >> str) 
    {
        auto ret = dict.Find(str);
        if (ret) cout << str << " : " << ret->_value << endl;
        else cout << "����ƴд����" << endl;
    }

    // ˮ��ͳ�Ʋ���
    string strs[] = { "ƻ��", "����", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��" };
    BSTree<string, int> countTree;
    for (auto& s : strs) 
    {
        auto ret = countTree.Find(s);
        if (ret == nullptr) countTree.Insert(s, 1);
        else ret->_value++;
    }

    cout << "\nˮ��ͳ�ƽ����" << endl;
    countTree.InOrder();
}
