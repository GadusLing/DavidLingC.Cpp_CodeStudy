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

    //Ã°ÅÝ:
    //printf("Array before sorting: ");
    //PrintArray(arr, n);
    //BubbleSort(arr, n);
    //printf("Array after sorting: ");
    //PrintArray(arr, n);


    ////Ï£¶û:
    //printf("Array before sorting: ");
    //PrintArray(arr, n);
    //ShellSort(arr, n);
    //printf("Array after sorting: ");
    //PrintArray(arr, n);

    ////¿ìËÙÅÅÐòµÝ¹éÈý·½·¨
    //QuickSort(arr, 0, n - 1);
    //printf("Array after sorting: ");
    //PrintArray(arr, n);

    ////¿ìËÙÅÅÐò·ÇµÝ¹é
    //QuickSortNonR(arr, n);
    //printf("Array after sorting: ");
    //PrintArray(arr, n);

    ////¹é²¢ÅÅÐò µÝ¹é
    //mergeSort(arr, n);
    //printf("Array after sorting: ");
    //PrintArray(arr, n);

    //¹é²¢ÅÅÐò ·ÇµÝ¹é
    mergeSortNonR(arr, n);
    printf("Array after sorting: ");
    PrintArray(arr, n);


    return 0;
}