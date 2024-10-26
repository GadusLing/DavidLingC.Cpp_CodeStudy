#define _CRT_SECURE_NO_WARNINGS


////初始化
//void HeapInit(HP* php)
//{
//	assert(php);
//	php->a = NULL;
//	php->capacity = php->size = 0;
//}





//void AdjustDown(HPDataType* arr, int size, int parent) 
//{
//    //大堆
//    int child = 2 * parent + 1;//找到左子节点
//
//    while (child < size) 
//    {
//        if (child + 1 < size && arr[child + 1] > arr[child])//如果右子节点存在且大于左子节点，则选择右子节点
//        {
//            child++;
//        }
//
//        if (arr[parent] >= arr[child])//如果父节点大于或等于子节点，停止调整
//        {
//            break;
//        }
//
//        Swap(&arr[parent], &arr[child]);//否则交换父节点和子节点的值
//
//        //更新父节点和子节点的索引，继续向下调整
//        parent = child;
//        child = 2 * parent + 1;
//    }
//}

#include <stdio.h>

// 交换两个元素的值
void Swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 下沉调整，用于维护最小堆的性质
void AdjustDown(int* arr, int size, int parent) {
    int child = 2 * parent + 1;  // 找到左子节点

    while (child < size) {
        // 如果右子节点存在并且右子节点小于左子节点，则选择右子节点
        if (child + 1 < size && arr[child + 1] < arr[child]) {
            child++;
        }

        // 如果父节点小于等于子节点，停止调整
        if (arr[parent] <= arr[child]) {
            break;
        }

        // 否则交换父节点与较小的子节点
        Swap(&arr[parent], &arr[child]);

        // 继续向下调整
        parent = child;
        child = 2 * parent + 1;
    }
}

// 堆排序算法的主函数（基于小顶堆）
void HeapSort(int* arr, int size) {
    // 第一步：构建最小堆
    // 从最后一个非叶子节点开始，向前调整堆
    for (int i = (size - 1) / 2; i >= 0; i--) {
        AdjustDown(arr, size, i);
    }

    // 第二步：逐步将最小元素移到数组末尾，然后调整剩余的堆
    for (int i = size - 1; i > 0; i--) {
        // 交换堆顶元素与当前堆的最后一个元素
        Swap(&arr[0], &arr[i]);

        // 调整剩余的堆，使其继续保持最小堆的性质
        AdjustDown(arr, i, 0);
    }
}

// 打印数组内容
void PrintArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // 定义待排序的数组
    int arr[] = { 50, 30, 40, 10, 5, 20, 60 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // 打印排序前的数组
    printf("排序前的数组: ");
    PrintArray(arr, size);

    // 对数组进行堆排序（小顶堆）
    HeapSort(arr, size);

    // 打印排序后的数组
    printf("排序后的数组: ");
    PrintArray(arr, size);

    return 0;
}


