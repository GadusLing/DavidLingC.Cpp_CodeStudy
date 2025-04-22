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
            else return false; // 关键字已存在
            
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

        // 删除节点有两个孩子
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

            // 替换完后删掉 minRight 节点
            cur = minRight;
            parent = minRightParent;
        }

        // 删除节点有一个孩子或没有孩子
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
    dict.Insert("insert", "插入");
    dict.Insert("erase", "删除");
    dict.Insert("left", "左边");
    dict.Insert("string", "字符串");

    string str;
    cout << "请输入英文单词进行查询 (Ctrl+Z 终止):" << endl;
    while (cin >> str) 
    {
        auto ret = dict.Find(str);
        if (ret) cout << str << " : " << ret->_value << endl;
        else cout << "单词拼写错误" << endl;
    }

    // 水果统计部分
    string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
    BSTree<string, int> countTree;
    for (auto& s : strs) 
    {
        auto ret = countTree.Find(s);
        if (ret == nullptr) countTree.Insert(s, 1);
        else ret->_value++;
    }

    cout << "\n水果统计结果：" << endl;
    countTree.InOrder();
}
