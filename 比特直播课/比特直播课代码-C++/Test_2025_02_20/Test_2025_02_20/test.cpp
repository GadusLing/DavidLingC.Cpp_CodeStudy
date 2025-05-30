﻿
#include <iostream>
//#include "SearchBinaryTree.h"
#include "work.h"
using namespace std;

// 多态还补充了一些理论知识，在2025_02_20__115期__多态+搜索树 的前50分钟


// 二叉搜索树部分
//• 若它的左⼦树不为空，则左⼦树上所有结点的值都⼩于等于根结点的值
//• 若它的右⼦树不为空，则右⼦树上所有结点的值都⼤于等于根结点的值
//• 它的左右⼦树也分别为⼆叉搜索树
// 也就意味着，如果在二叉搜索树中找寻某一元素，最大的复杂度情况就是————查找树的高度次即可找到

// 搜索树也叫二叉排序树，因为这种结构还有一个彩蛋功能，就是当对一个搜索树走中序遍历（左根右）时，可以进行升序排列
// 通常使用的map or set结构是不允许冗余的，只有> <,如果想要有>= <=的功能，能有重复的元素，会使用multimap or multiset

// 理论上根据树的高度次，搜索二叉树的效率是logN，但实际上可能会有树左边巨长，右边只有一个这种类单支树情况，此时也符合搜索树性质
// 但这个时候要找最右的那个节点，效率就是N了
// 所以要控制平衡，让它尽量接近平衡状态，类完全二叉树or满二叉树，也就是AVL树和红黑树

// 先看基础二叉搜索树的增删查改
int main()
{
	//TestBSTree1();

	TestBSTree();// work

	return 0;
}

