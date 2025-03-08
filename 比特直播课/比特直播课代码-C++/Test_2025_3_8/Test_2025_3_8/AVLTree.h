#pragma once

#include <iostream>
#include <utility>

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
        : _kv(kv), _left(nullptr), _right(nullptr), _parent(nullptr), _bf(0)
    {
    }
};