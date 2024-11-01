#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

int main()
{
    // 初始化队列
    Queue q;
    QueueInit(&q);
    printf("队列已初始化。\n");

    // 检查队列是否为空，预期输出：是
    printf("队列是否为空？%s\n", QueueEmpty(&q) ? "是" : "否"); // 是

    // 入队操作，插入元素1, 2, 3
    QueuePush(&q, 1);
    printf("入队1. 队列头: %d, 队列尾: %d, 队列大小: %d\n", QueueFront(&q), QueueBack(&q), QueueSize(&q)); // 1, 1, 1

    QueuePush(&q, 2);
    printf("入队2. 队列头: %d, 队列尾: %d, 队列大小: %d\n", QueueFront(&q), QueueBack(&q), QueueSize(&q)); // 1, 2, 2

    QueuePush(&q, 3);
    printf("入队3. 队列头: %d, 队列尾: %d, 队列大小: %d\n", QueueFront(&q), QueueBack(&q), QueueSize(&q)); // 1, 3, 3

    // 出队操作
    QueuePop(&q);
    printf("出队头部元素。 队列头: %d, 队列尾: %d, 队列大小: %d\n", QueueFront(&q), QueueBack(&q), QueueSize(&q)); // 2, 3, 2

    QueuePop(&q);
    printf("出队头部元素。 队列头: %d, 队列尾: %d, 队列大小: %d\n", QueueFront(&q), QueueBack(&q), QueueSize(&q)); // 3, 3, 1

    // 再次出队，队列应为空
    QueuePop(&q);
    printf("出队头部元素。 队列是否为空？%s, 队列大小: %d\n", QueueEmpty(&q) ? "是" : "否", QueueSize(&q)); // 是, 0

    // 测试在空队列上使用Front和Back操作
    if (!QueueEmpty(&q))
    {
        printf("队列头: %d, 队列尾: %d\n", QueueFront(&q), QueueBack(&q));
    }
    else
    {
        printf("队列为空，没有队头或队尾元素。\n");
    }

    // 销毁队列
    QueueDestroy(&q);
    printf("队列已销毁。 队列是否为空？%s, 队列大小: %d\n", QueueEmpty(&q) ? "是" : "否", QueueSize(&q)); // 是, 0

    return 0;
}
