# 学习数据结构与算法

## 二分搜索算法

* 给定一个 `n` 个元素有序的（升序）整型数组 `nums` 和一个目标值 `target` ，写一个函数搜索 `nums` 中的 `target`，如果目标值存在返回下标，否则返回 `-1`。

  * ```c
    int start = 0, end = (int)(numsSize)/2;
    nums[end] < target? end = numsSize-1 : end;
    if(numsSize == 1) end = numsSize-1;
    // 二分方式
    while (start <= end) {
        if (nums[start] == target) return start;
        if (nums[end] == target) return end;
        start += 1;
        end -= 1;
    }
    return -1;
    ```

## 顺序表

* 顺序表的创建

  * ```c
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
    int initList(ArrayList list) {
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
    
    int main(void) {
        struct List list;
        //判断是否成功初始化顺序表
        if (initList(&list)) {
            //成功初始化后的操作
        } else { printf("Error"); }
    }
    ```

* 

