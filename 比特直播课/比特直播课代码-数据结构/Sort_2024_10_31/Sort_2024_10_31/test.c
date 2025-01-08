#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"

void PrintArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = { 34, 8, 64, 51, 32, 21 };
    int n = sizeof(arr) / sizeof(arr[0]);

    //ð��:
    //printf("Array before sorting: ");
    //PrintArray(arr, n);
    //BubbleSort(arr, n);
    //printf("Array after sorting: ");
    //PrintArray(arr, n);


    ////ϣ��:
    //printf("Array before sorting: ");
    //PrintArray(arr, n);
    //ShellSort(arr, n);
    //printf("Array after sorting: ");
    //PrintArray(arr, n);

    ////��������ݹ�������
    //QuickSort(arr, 0, n - 1);
    //printf("Array after sorting: ");
    //PrintArray(arr, n);

    //��������ǵݹ�
    QuickSortNonR(arr, n);
    printf("Array after sorting: ");
    PrintArray(arr, n);



    return 0;
}