//
// Created by MirageCloud on 2024/9/13.
//
#include <stdio.h>
#include <stdlib.h>

/**顺序表*/
//给int类型设置别名E
typedef int E;

//创建构造体
struct List {
    E *array;
    int size;
    int capacity;
};

//对构造体设置别名 ArrayList
typedef struct List *ArrayList;

// 初始化顺序表
int initList(const ArrayList list) {
    list->capacity = 10;
    //动态规划内存使用量
    list->array = malloc(sizeof(E) * list->capacity);
    // 判断是否动态申请内存成功
    if (list->array == NULL) {
        return 0;
    }
    list->size = 0;
    return 1;
}

// 创建顺序表插入方法
int insertList(const ArrayList list, const E element, const int index) {
    // 判断index的值是否合法
    if (index < 1 || index > list->size + 1) return 0;
    // 对顺序表进行扩容
    if (list->size == list->capacity) {
        //添加新内存的大小为 原内存大小+原内存大小除以2
        const int newCapacity = list->capacity + (list->capacity >> 1);
        //动态规划新数组的动态内存大小
        E *newArray = realloc(list->array, newCapacity * sizeof(E));
        //判断申请新内存是否成功
        if (newArray == NULL) return 0;
        //调整原构造体内容
        list->array = newArray;
        list->capacity = newCapacity;
    }

    //使用for遍历，从末尾开始，将数组每一项数据的值替换为前一项数组的值
    for (int i = list->size; i > index; i--) {
        list->array[i] = list->array[i - 1];
    }
    //对第index项的数据进行替换
    list->array[index - 1] = element;
    //由于数据增加了，size应该也增加
    list->size++;
    return 1;
}

//创建打印顺序表方法
void printList(ArrayList list) {
    for (int i = 0; i < list->size; ++i)
        printf("%d ", list->array[i]);
    printf("\n");
}

//创建数组删除方法
int deleteList(const ArrayList list, const int index) {
    //判断index是否合法
    if (index < 1 || index > list->size) return 0;
    //使用for遍历，从index开始，将数组前一项的值替换为后一项的值
    for (int i = index - 1; i < list->size - 1; ++i)
        list->array[i] = list->array[i + 1];
    //由于数据减少了,size应该减少
    list->size--;
    return 1;
}

//获取顺序表长度
int sizeList(const ArrayList list) {
    //由于我们有构造体中维护有size,说以说直接把size返回回去,如果没有维护size可以使用sizeof()
    // int len = sizeof(list->array) / sizeof(list->array[0]);
    return list->size;
}

//获取指定位置上的元素
E * getList(const ArrayList list, const int index) {
    //判断index是否合法
    if (index < 1 || index > list->size) return NULL;
    //因为返回的是指针,所以要对构造体中取出来的数据进行取地址操作
    return &list->array[index - 1];
}

//查询元素在顺序表中的位置
int findList(const ArrayList list, const E element) {
    for (int i = 0; i < list->size; ++i) {
        // 遍历，若找到了就返回位置
        if (list->array[i] == element) return i+1;
    }
    return -1;
}




int main(void) {
    struct List list;
    //判断是否成功初始化顺序表
    if (initList(&list)) {
        //成功初始化后的操作
        for (int i = 0; i <= 30; ++i) {
            insertList(&list, i * 10, i);
        }
        deleteList(&list, 1);
        printList(&list);
        printf("%d",*getList(&list, 1));
        printf("%d",sizeList(&list));
        printf("%d",findList(&list, 50));
    } else { printf("Error"); }
}

