//
// Created by MirageCloud on 2024/9/14.
//

#include <stdlib.h>
#include <stdio.h>
// 引入这个包，_Bool就可以写成bool 然后返回值可以写true和false了
#include <stdbool.h>

/**顺序表方式*/
/*typedef int E;

struct  Queue{
    E * array;
    int capacity;
    int front, rear; //创建队列的头和尾
};

typedef struct Queue * ArrayQueue;

//初始化队列
_Bool initQueue(const ArrayQueue queue) {
    // 动态申请内存大小
    queue->array = malloc(sizeof(E) * 10);
    if (queue->array == NULL) return 0;
    queue->capacity = 10;
    // 用于队列中没有内容，所以队首和队尾都为0
    queue->front = queue->rear =  0;
    return 1;
}

// 打印队列函数
void printQueue(const ArrayQueue queue) {
    printf("[");
    // 遍历需要从队首开始
    int i = queue->front;
    do {
        // 由于队首的携带内容为空，所以说开始的时候需要向后移动一次
        i = (i + 1)% queue->capacity;
        printf("%d, ", queue->array[i]);
    } while (i != queue->rear); // 当队首等于队尾时，表示这个队列已经打印成功了
    printf("]");
}


// 入队函数
_Bool emQueue(const ArrayQueue queue, const E element) {
    // 由于是循环数组，需要判断数组申请的内存空间是否被占满了，进行取余操作来获取队尾指针指向的正确位置
    const int pos = (queue->rear + 1) % queue->capacity;
    // 当队尾指针指向了队首指针，说明了这个数组已经满了，直接返回出去
    if(pos == queue->front)
        return 0;
    // 进行赋值
    queue->rear = pos;
    queue->array[queue->rear] = element;
    return 1;
}

// 出队函数
_Bool isEmpty(const ArrayQueue queue) {
    // 当队尾等于队首等于队尾的时候，说明说这个队列是为空的，不进行出队操作
    return queue->front == queue->rear;
}

E pollQueue(const ArrayQueue queue) {
    // 那到正确的队首指针位置
    queue -> front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}



int main(void) {
    struct Queue queue;
    initQueue(&queue);

    for (int i = 0; i < 10; i++) {
        emQueue(&queue, i);
    }

    printQueue(&queue); // [0, 1, 2, 3, 4, 5, 6, 7, 8, ]

    while (!isEmpty(&queue)) {
        printf("%d", pollQueue(&queue)); // 012345678
    }
}*/

/**链表方式*/
/*typedef int E;

// 创建链表
struct LNode {
    E element;
    struct LNode *next;
};

typedef struct LNode * Node;

//将队头和队尾封装成一个构造体
struct Queue {
    Node front, rear;
};

typedef struct Queue * LinkedQueue;

// 初始化队列
bool initQueue(const LinkedQueue queue) {
    // 动态申请内存空间,创建头节点
    const Node node = malloc(sizeof(struct Queue));
    if(node == NULL) return false;
    // 设置队头和队尾同指向节点
    queue -> rear = queue -> front = node;
    return true;
}

// 入队函数
bool offerQueue(LinkedQueue queue, const E element) {
    // 创建子节点
    const Node node = malloc(sizeof(struct Queue));
    if(node == NULL) return false;
    node -> element = element;
    // 让队列的队尾的下一个指针指向新创建的子节点
    queue ->rear->next = node;
    // 让队尾也指向子节点
    queue->rear = node;
    return true;
}

// 打印队列函数
void printQueue(const LinkedQueue queue) {
    printf("[");
    // 因为头节点不携带任何内容，所以需要从头结点的下一个节点去遍历
    Node node = queue ->front ->next;
    while(node) {
        printf(" %d", node -> element);
        // 让当前node的指针指向下一个节点
        node = node -> next;
    }
    printf(" ]");
}

// 出队函数
bool isEmpty(const LinkedQueue queue) {
    // 判断，当头指针和尾指针相等的时候，说明说这个队列为空的
    return queue -> rear == queue -> front;
}

E pollQueue(const LinkedQueue queue) {
    // 取出要出队的节点
    const Node tmp = queue -> front ->next;
    const E e = tmp -> element;
    // 将头节点指针指向要出队的节点的下一个节点
    queue->front->next =  queue->front->next->next;
    // 如果队尾节点就是要出队的加点的话，把队尾指针指向到队首指针
    if(queue->rear == tmp) queue->rear = queue->front;
    free(tmp);
    return e;
}


int main(void) {
    struct Queue queue;
    initQueue(&queue);

    for(int i = 1; i <= 10; i++) {
        offerQueue(&queue, i);
    }
    printQueue(&queue); //[ 1 2 3 4 5 6 7 8 9 10 ]

    while(!isEmpty(&queue)) {
        printf("%d", pollQueue(&queue)); //12345678910
    }
}*/