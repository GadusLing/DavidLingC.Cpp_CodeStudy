#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;//����ṹ��������data���ݵ�����

typedef struct SLTNode//����һ���ṹ��SLTNode
{
	SLTDataType data;//�洢����
	struct SLTNode* next;//��ʽ����next�ڵ�ĵ�ַ
}SLTNode;


// ��̬����һ���ڵ�
SLTNode* SLTBuyNode(SLTDataType x);

// �������ӡ
void SLTprint(SLTNode* phead);

//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);

//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);

//βɾ
void SLTPopBack(SLTNode** pphead);

//ͷɾ
void SLTPopFront(SLTNode** pphead);

// ���������
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SLTNode* pos);

// ��pos��ǰ�����
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

// ɾ��posλ��
void SLTErase(SLTNode** pphead, SLTNode* pos);

//����
void SLTDestroy(SLTNode** pphead);
