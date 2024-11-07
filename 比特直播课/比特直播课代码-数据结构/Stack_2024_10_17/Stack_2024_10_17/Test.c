#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"

int main() {
    ST stack; // ����ջ
    STInit(&stack); // ��ʼ��ջ

    // ������ջ
    printf("��ջԪ��:\n");
    fflush(stdout); // ȷ�����������ˢ��
    for (int i = 1; i <= 5; i++) {
        STPush(&stack, i); // ��Ԫ�� i ��ջ
        printf("��ջ: %d, ��ǰջ��С: %d\n", i, STSize(&stack)); // �����ǰջ��С
        fflush(stdout); // ȷ�����������ˢ��
    }

    // ����ջ��Ԫ��
    printf("\n��ǰջ��Ԫ��: %d\n", STTop(&stack)); // ���ջ��Ԫ��
    fflush(stdout); // ȷ�����������ˢ��

    // ���Գ�ջ
    printf("\n��ջԪ��:\n");
    fflush(stdout); // ȷ�����������ˢ��
    while (!STEmpty(&stack)) { // ��ջ��Ϊ��ʱ
        printf("��ջǰջ��: %d\n", STTop(&stack)); // �����ǰջ��Ԫ��
        fflush(stdout); // ȷ�����������ˢ��
        STPop(&stack); // ��ջ
        printf("�ѳ�ջ, ��ǰջ��С: %d\n", STSize(&stack)); // �����ջ���ջ��С
        fflush(stdout); // ȷ�����������ˢ��
    }

    // ����ջ�Ƿ�Ϊ��
    if (STEmpty(&stack)) {
        printf("\nջ����Ϊ�ա�\n"); // ���ջΪ�գ������Ӧ��Ϣ
        fflush(stdout); // ȷ�����������ˢ��
    }

    // ����ջ
    STDestroy(&stack); // �ͷ�ջ����Դ
    printf("ջ�����١�\n");
    fflush(stdout); // ȷ�����������ˢ��

    return 0;
}


