#define _CRT_SECURE_NO_WARNINGS

// Stack.cpp
#include"Stack.h"

namespace bit
{
    void STInit(ST* ps, int n)
    {
        assert(ps);
        ps->a = (STDataType*)malloc(n * sizeof(STDataType));
        ps->top = 0;
        ps->capacity = n;
    }
    // ջ��

    void STPush(ST* ps, STDataType x)
    {
        assert(ps);
        // ���ˣ�����
        if (ps->top == ps->capacity)
        {
            printf("����\n");
            int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
            STDataType* tmp = (STDataType*)realloc(ps->a,newcapacity * sizeof(STDataType));

            if (tmp == NULL)
            {
                perror("realloc fail");
                return;
            }
        }
    }
}