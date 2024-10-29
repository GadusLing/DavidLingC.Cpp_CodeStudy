#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

// 栈结构
typedef struct stack {
    STDataType* arr;   // 栈的数据存储区
    int top;         // 栈顶索引
    int capacity;    // 栈的容量
} ST;

// 初始化栈
void STInit(ST* ps);

// 销毁栈
void STDestroy(ST* ps);

// 入栈
void STPush(ST* ps, STDataType x);

// 出栈
void STPop(ST* ps);

// 取栈顶元素
STDataType STTop(ST* ps);

// 获取栈中有效元素个数
int STSize(ST* ps);

// 判断栈是否为空
bool STEmpty(ST* ps);

