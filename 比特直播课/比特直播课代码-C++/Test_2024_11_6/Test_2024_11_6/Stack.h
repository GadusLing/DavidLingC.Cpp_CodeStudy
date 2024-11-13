#pragma once

// 多⽂件中可以定义同名namespace，他们会默认合并到⼀起，就像同⼀个namespace⼀样

// Stack.h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
namespace bit
{
    typedef int STDataType;
    typedef struct Stack
    {
        STDataType* a;
        int top;
        int capacity;
    }ST;

    void STInit(ST* ps, int n);
    void STDestroy(ST* ps);

    void STPush(ST* ps, STDataType x);
    void STPop(ST* ps);
    STDataType STTop(ST* ps);
    int STSize(ST* ps);
    bool STEmpty(ST* ps);
}