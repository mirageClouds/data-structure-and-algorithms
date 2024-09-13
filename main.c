#include <stdio.h>
#include <stdlib.h>

// int search(int *arr, int i, int target);
//
// int main(void) {
//     int sum = 0;
//     for (int i = 0; i <= 100; ++i) {
//         sum += i;
//     }
//
//     printf("sum = %d\n", sum);
//     printf("sum = %d\n", (1 + 100) * 100 / 2);
//
//     int arr[] = {1}, target = 3;
//     printf("target = %d\n", search(arr, 10, target));
//     return 0;
// }
//
// // 二分查询
// int binarySearch(int *arr, int target, int left, int right) {
//     if (left > right) return -1;
//     int mid = (left + right) / 2;
//     if (arr[mid] == target) return mid;
//     if (arr[mid] < target)
//         return binarySearch(arr, target, mid + 1, right);
//     else
//         return binarySearch(arr, target, left, mid - 1);
// }
//
// int search(int *nums, int numsSize, int target) {
//     // const int len = sizeof(nums)/sizeof(nums[0]);
//     // for (int i = 0; i < len; ++i) {
//     //     if (nums[i] == target) return i;
//     //     if (nums[i] > target) return -1;
//     // }
//
//     int start = 0, end = (int) (numsSize) / 2;
//     nums[end] < target ? end = numsSize - 1 : end;
//     if (numsSize == 1) end = numsSize - 1;
//     // 二分方式
//     while (start <= end) {
//         if (nums[start] == target) return start;
//         if (nums[end] == target) return end;
//         start += 1;
//         end -= 1;
//     }
//     return -1;
//     return binarySearch(nums, target, 0, numsSize - 1);
// }


//顺序表
typedef int E; //给int类型设置别名

//创建构造体
struct List {
    E *array;
    int size;
    int capacity;
};

typedef struct List *ArrayList; //对构造体设置别名

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

int main(void) {
    struct List list;
    //判断是否成功初始化顺序表
    if (initList(&list)) {
        //成功初始化后的操作
        for (int i = 0; i < 30; ++i) {
            insertList(&list, i * 10, i);
        }

        printList(&list);
    } else { printf("Error"); }
}

