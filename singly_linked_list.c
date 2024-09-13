//
// Created by MirageCloud on 2024/9/13.
//

#include <stdio.h>
#include <stdlib.h>

//设置int 的别名 E
typedef int E;

//E:携带的数据, struct ListNode *next:指向的下一个链表的指针
struct ListNode {
    E element;
    struct ListNode *next;
};

//设置结构体别名
typedef struct ListNode * Node;

//初始化单链表
void initList(const Node node) {
    node->next = NULL;
}

//创建单链表插入方法
_Bool insertList( Node head, const E element, int index) {
    //判断index是否合法
    if(index<1) return 0;
    //通过--index的方式不断向后寻找前节点
    while(--index) {
        head = head->next;
        if(head == NULL) return 0;
    }

    //动态创新新节点
    const Node newNode = malloc(sizeof(struct ListNode));
    //判断节点为空，返回0
    if(newNode == NULL) return 0;
    newNode->element = element;    //把数据赋值给新节点
    newNode->next = head->next;   //把当前数据的指针传递给新节点
    head->next = newNode;   //把新节点的指针赋值给当前节点

    return 1;
}

//创建单链表打印方法
void printList( Node head) {
    while(head->next) {
        head = head->next;
        printf("当前值为%d", head->element);
    }
}

//创建单链表删除方法
_Bool deleteList(Node head,int index) {
    //判断index是否合法
    if(index<1) return 0;
    //通过--index的方式不断向后寻找前节点
    while(--index) {
        head = head->next;
        if(head == NULL) return 0;
    }
    if(head->next == NULL) return 0;  //判断删除的节点是否存在
    const Node temp = head->next; //拿到待删除的节点
    head->next = head->next->next; //让前节点指向下一个的下一个节点
    free(temp); //使用free函数释放内存
    return 1;
}

//获取指定位置上的元素
E * getList(Node head,int index) {
    // 判断index是否合法
    if(index<1) return 0;
    //因为不计算头节点，所以使用do-while语句
    do {
        head = head->next;
        if(head == NULL) return 0;
    }while(--index);//到达index结束
    return &head->element;
}

// 查询元素在单链表中的位置
int findList(Node head, const E element) {
    // 定义计数器
    int i = 0;
    do {
        //进入第一个节点
        head = head->next;
        //找到了就返回i，没找到就i++
        if(head->element != element) return i;
        i++;
    }while(head->next);
    return -1;
}

//获取单链表长度
int sizeList(Node head) {
    int i = -1;
    while(head) {
        head = head->next;
        i++;
    }
    return i;
}


// int main(void) {
//     struct ListNode head;
//     initList(&head);
//
//     for(int i = 1; i <= 3; ++i) {
//         insertList(&head, i*100, i);
//     }
//     deleteList(&head, 2);
//     printList(&head);
//     printf("%d", findList(&head, 100));
//     printf("%d", sizeList(&head));
// }