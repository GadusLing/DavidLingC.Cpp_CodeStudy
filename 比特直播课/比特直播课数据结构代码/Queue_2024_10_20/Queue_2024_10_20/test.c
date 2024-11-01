#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

int main()
{
    // ��ʼ������
    Queue q;
    QueueInit(&q);
    printf("�����ѳ�ʼ����\n");

    // �������Ƿ�Ϊ�գ�Ԥ���������
    printf("�����Ƿ�Ϊ�գ�%s\n", QueueEmpty(&q) ? "��" : "��"); // ��

    // ��Ӳ���������Ԫ��1, 2, 3
    QueuePush(&q, 1);
    printf("���1. ����ͷ: %d, ����β: %d, ���д�С: %d\n", QueueFront(&q), QueueBack(&q), QueueSize(&q)); // 1, 1, 1

    QueuePush(&q, 2);
    printf("���2. ����ͷ: %d, ����β: %d, ���д�С: %d\n", QueueFront(&q), QueueBack(&q), QueueSize(&q)); // 1, 2, 2

    QueuePush(&q, 3);
    printf("���3. ����ͷ: %d, ����β: %d, ���д�С: %d\n", QueueFront(&q), QueueBack(&q), QueueSize(&q)); // 1, 3, 3

    // ���Ӳ���
    QueuePop(&q);
    printf("����ͷ��Ԫ�ء� ����ͷ: %d, ����β: %d, ���д�С: %d\n", QueueFront(&q), QueueBack(&q), QueueSize(&q)); // 2, 3, 2

    QueuePop(&q);
    printf("����ͷ��Ԫ�ء� ����ͷ: %d, ����β: %d, ���д�С: %d\n", QueueFront(&q), QueueBack(&q), QueueSize(&q)); // 3, 3, 1

    // �ٴγ��ӣ�����ӦΪ��
    QueuePop(&q);
    printf("����ͷ��Ԫ�ء� �����Ƿ�Ϊ�գ�%s, ���д�С: %d\n", QueueEmpty(&q) ? "��" : "��", QueueSize(&q)); // ��, 0

    // �����ڿն�����ʹ��Front��Back����
    if (!QueueEmpty(&q))
    {
        printf("����ͷ: %d, ����β: %d\n", QueueFront(&q), QueueBack(&q));
    }
    else
    {
        printf("����Ϊ�գ�û�ж�ͷ���βԪ�ء�\n");
    }

    // ���ٶ���
    QueueDestroy(&q);
    printf("���������١� �����Ƿ�Ϊ�գ�%s, ���д�С: %d\n", QueueEmpty(&q) ? "��" : "��", QueueSize(&q)); // ��, 0

    return 0;
}
