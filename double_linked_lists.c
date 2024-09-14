/*//
// Created by MirageCloud on 2024/9/14.
//

#include <stdio.h>
#include <stdlib.h>
typedef int E;

struct ListNode {
    E element;
    struct ListNode *next;
    struct ListNode *prev;
};

typedef struct ListNode * Node;

//双向链表初始化
void initList(const Node node) {
    node->next = node->prev = NULL;
}

//创建双链表插入方法
_Bool insertList( Node node, const E element, int index) {
    //判断index是否合法
    if(index<1) return 0;
    //遍历找到插入的位置
    while (--index) {
        node = node->next;
        if(node == NULL) return 0;
    }
    // 动态创建内存空间
    const Node new_node = malloc(sizeof(struct ListNode));
    if(node == NULL) return 0; // 判断内存空间是否成功创建
    new_node->element = element;

    if(node->next) {
        new_node->next = node->next;    //将新节点的后节点指针替换成当前节点的后指针
        node->next->prev = new_node;    //将当前节点的后节点的前节点的指针指向新节点
    }else {
        new_node ->next = NULL; // 如果当前节点的后节点为空时，新节点的后指针也应当为空
    }

    node->next = new_node;  //将当前节点的后指针指向新节点
    new_node->prev = node;  //将新节点的前指针指向当前节点

    return 1;
}

void printNextList( Node node) {
    do {
        node = node->next;
        printf("%d ->", node->element);
    }while(node->next != NULL);
}

//创建双向链表删除方法
_Bool deleteList( Node node,int index) {
    // 判断index是否合法
    if(index<1) return 0;
    // 遍历找到需要删除的节点
    while (--index) {
        node = node->next;
        if(node == NULL) return 0;
    }
    // 判断当前节点的后节点是否为空
    if(node->next == NULL) return 0;

    //拿到当前节点
    const Node temp = node->next;
    // 判断当前节点的下一个节点的下一个节点是否存在
    if( node->next->next) {
        node->next = node->next->next; //将当前节点的下一个节点替换为当前节点的下一个节点的下一个节点
        node->next->next->prev = node;  //将当前节点的下一个节点的下一个节点的上节点指针指向当前节点
    }else {
        node->next = NULL;  //相当于删除最后一个节点
    }
    free(temp);  //释放内存
    return 1;
}


int main(void) {
    struct ListNode node;
    initList(&node);

    for (int i = 0; i < 10; i++) {
        insertList(&node, i*100, i);
    }
    printNextList(&node); //100 ->200 ->300 ->400 ->500 ->600 ->700 ->800 ->900 ->
    deleteList(&node, 4);
    printNextList(&node); // 100 ->200 ->300 ->500 ->600 ->700 ->800 ->900 ->
}*/