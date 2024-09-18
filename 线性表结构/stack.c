//
// Created by MirageCloud on 2024/9/14.
//

#include <stdio.h>
#include <stdlib.h>

/**顺序表方式*/
/*typedef int E;

struct stack {
    E * array;
    int capacity;
    int top; //top表示栈顶的位置，存的是下标
};

typedef struct stack * ArrayStack;

//初始化栈
_Bool initStack(const ArrayStack stack) {
    // 动态申请内存空间
    stack->array = malloc(sizeof(E) * 10);
    if (stack->array == NULL) return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}

// 新增栈的内容
_Bool pushStack(const ArrayStack stack, const E element) {
    // 栈顶 +1 如果等于容量的话，说明说栈已经满了
    if(stack->top + 1 == stack->capacity) {
        // 动态申请空间,大小为原空间大小加上原空间大小除二
        const int newCapacity = stack->capacity+(stack->capacity>>1);
        E * newArray = realloc(stack->array, newCapacity * sizeof(E));
        if (newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    // 由于数据变动，栈顶+1
    stack->top++;
    //将栈顶的数据赋值
    stack->array[stack->top] = element;
    return 1;
}

// 创建出栈函数
_Bool isStackEmpty(const ArrayStack stack) {
    // 判断栈是否为空了
    return stack->top == -1;
}

E  popStack(const ArrayStack stack) {
    // 出栈，由于有元素出栈了，所以栈顶要—1
    return stack->array[stack->top--];
}

// 打印出栈函数
void printStack(const ArrayStack stack) {
    printf("|");
    for (int i = 0; i < stack->top+1; ++i) printf("%d, ", stack->array[i]);
    printf("|\n");
}


int main(void) {
    struct stack stack;
    initStack(&stack);
    for (int i = 0; i < 10; i++) pushStack(&stack, i*100);
    pushStack(&stack,321);
    printStack(&stack); //|0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 321, |

    while (!isStackEmpty(&stack)) {
        printf("%d,", popStack(&stack)); //321,900,800,700,600,500,400,300,200,100,0
    }
}*/

/**链表方式*/
/*typedef int E;

//创建链表
struct ListNode {
    E element;
    struct ListNode *next;
};

typedef struct ListNode * List;

//初始化链表
void initStack(const List list) {
    list->next = NULL;
}

//插入链表
_Bool pushStack(const List list, const E element) {
    const List newList = malloc(sizeof(struct ListNode));
    if(newList == NULL) return 0;
    newList->element = element;
    newList->next = list->next;
    list->next = newList;
    return 1;
}

//打印链表
void printStack( List list) {
    list = list->next;
    while(list) {
        printf("%d ", list->element);
        list = list->next;
    }
    printf("|\n");
}

// 出栈
_Bool isStackEmpty(const List list) {
    //判断是否到链表底部
    return list->next == NULL;
}

E popStack(const List list) {
    // 取链表的值
    const List temp = list->next;
    const E element = temp->element;
    // 让当前链表的指向指向后面的链表
    list->next = list->next->next;
    //销毁内存
    free(temp);
    return element;
}


int main(void) {
    struct ListNode list;
    initStack(&list);

    for(int i = 0; i < 10; i++) {
        pushStack(&list, i);
    }
    printStack(&list); //9 8 7 6 5 4 3 2 1 0 |
    while(!isStackEmpty(&list)) {
        printf("%d ", popStack(&list)); //9 8 7 6 5 4 3 2 1 0

    }
}*/