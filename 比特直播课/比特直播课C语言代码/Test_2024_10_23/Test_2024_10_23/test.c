#define _CRT_SECURE_NO_WARNINGS


////��ʼ��
//void HeapInit(HP* php)
//{
//	assert(php);
//	php->a = NULL;
//	php->capacity = php->size = 0;
//}





//void AdjustDown(HPDataType* arr, int size, int parent) 
//{
//    //���
//    int child = 2 * parent + 1;//�ҵ����ӽڵ�
//
//    while (child < size) 
//    {
//        if (child + 1 < size && arr[child + 1] > arr[child])//������ӽڵ�����Ҵ������ӽڵ㣬��ѡ�����ӽڵ�
//        {
//            child++;
//        }
//
//        if (arr[parent] >= arr[child])//������ڵ���ڻ�����ӽڵ㣬ֹͣ����
//        {
//            break;
//        }
//
//        Swap(&arr[parent], &arr[child]);//���򽻻����ڵ���ӽڵ��ֵ
//
//        //���¸��ڵ���ӽڵ���������������µ���
//        parent = child;
//        child = 2 * parent + 1;
//    }
//}

#include <stdio.h>

// ��������Ԫ�ص�ֵ
void Swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// �³�����������ά����С�ѵ�����
void AdjustDown(int* arr, int size, int parent) {
    int child = 2 * parent + 1;  // �ҵ����ӽڵ�

    while (child < size) {
        // ������ӽڵ���ڲ������ӽڵ�С�����ӽڵ㣬��ѡ�����ӽڵ�
        if (child + 1 < size && arr[child + 1] < arr[child]) {
            child++;
        }

        // ������ڵ�С�ڵ����ӽڵ㣬ֹͣ����
        if (arr[parent] <= arr[child]) {
            break;
        }

        // ���򽻻����ڵ����С���ӽڵ�
        Swap(&arr[parent], &arr[child]);

        // �������µ���
        parent = child;
        child = 2 * parent + 1;
    }
}

// �������㷨��������������С���ѣ�
void HeapSort(int* arr, int size) {
    // ��һ����������С��
    // �����һ����Ҷ�ӽڵ㿪ʼ����ǰ������
    for (int i = (size - 1) / 2; i >= 0; i--) {
        AdjustDown(arr, size, i);
    }

    // �ڶ������𲽽���СԪ���Ƶ�����ĩβ��Ȼ�����ʣ��Ķ�
    for (int i = size - 1; i > 0; i--) {
        // �����Ѷ�Ԫ���뵱ǰ�ѵ����һ��Ԫ��
        Swap(&arr[0], &arr[i]);

        // ����ʣ��Ķѣ�ʹ�����������С�ѵ�����
        AdjustDown(arr, i, 0);
    }
}

// ��ӡ��������
void PrintArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // ��������������
    int arr[] = { 50, 30, 40, 10, 5, 20, 60 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // ��ӡ����ǰ������
    printf("����ǰ������: ");
    PrintArray(arr, size);

    // ��������ж�����С���ѣ�
    HeapSort(arr, size);

    // ��ӡ����������
    printf("����������: ");
    PrintArray(arr, size);

    return 0;
}


