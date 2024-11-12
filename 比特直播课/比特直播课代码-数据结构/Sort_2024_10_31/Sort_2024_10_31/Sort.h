#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//ð������
void BubbleSort(int* arr, int n);

//ֱ�Ӳ�������
void InsertSort(int* arr, int n);

//ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right);

// ���������ڿӷ�
int PartSort2(int* a, int left, int right);

// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);