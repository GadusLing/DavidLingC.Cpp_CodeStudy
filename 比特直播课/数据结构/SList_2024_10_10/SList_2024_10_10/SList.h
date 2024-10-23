#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;//定义结构体所储存data数据的类型

typedef struct SLTNode//定义一个结构体SLTNode
{
	SLTDataType data;//存储数据
	struct SLTNode* next;//链式储存next节点的地址
}SLTNode;


// 动态申请一个节点
SLTNode* SLTBuyNode(SLTDataType x);

// 单链表打印
void SLTprint(SLTNode* phead);

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//尾删
void SLTPopBack(SLTNode** pphead);

//头删
void SLTPopFront(SLTNode** pphead);

// 单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SLTNode* pos);

// 在pos的前面插入
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

// 删除pos位置
void SLTErase(SLTNode** pphead, SLTNode* pos);

//销毁
void SLTDestroy(SLTNode** pphead);
