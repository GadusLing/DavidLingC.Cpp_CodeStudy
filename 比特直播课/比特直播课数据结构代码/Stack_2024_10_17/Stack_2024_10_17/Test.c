#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"

int main() {
    ST stack; // 创建栈
    STInit(&stack); // 初始化栈

    // 测试入栈
    printf("入栈元素:\n");
    fflush(stdout); // 确保输出被立即刷新
    for (int i = 1; i <= 5; i++) {
        STPush(&stack, i); // 将元素 i 入栈
        printf("入栈: %d, 当前栈大小: %d\n", i, STSize(&stack)); // 输出当前栈大小
        fflush(stdout); // 确保输出被立即刷新
    }

    // 测试栈顶元素
    printf("\n当前栈顶元素: %d\n", STTop(&stack)); // 输出栈顶元素
    fflush(stdout); // 确保输出被立即刷新

    // 测试出栈
    printf("\n出栈元素:\n");
    fflush(stdout); // 确保输出被立即刷新
    while (!STEmpty(&stack)) { // 当栈不为空时
        printf("出栈前栈顶: %d\n", STTop(&stack)); // 输出当前栈顶元素
        fflush(stdout); // 确保输出被立即刷新
        STPop(&stack); // 出栈
        printf("已出栈, 当前栈大小: %d\n", STSize(&stack)); // 输出出栈后的栈大小
        fflush(stdout); // 确保输出被立即刷新
    }

    // 测试栈是否为空
    if (STEmpty(&stack)) {
        printf("\n栈现在为空。\n"); // 如果栈为空，输出相应信息
        fflush(stdout); // 确保输出被立即刷新
    }

    // 销毁栈
    STDestroy(&stack); // 释放栈的资源
    printf("栈已销毁。\n");
    fflush(stdout); // 确保输出被立即刷新

    return 0;
}


