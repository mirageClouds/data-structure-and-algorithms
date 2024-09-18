#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 力扣[704. 二分查找](https://leetcode.cn/problems/binary-search/)*/
 /*//递归解法
 int binarySearch(int *arr, int target, int left, int right) {
     if (left > right) return -1;
     int mid = (left + right) / 2;
     if (arr[mid] == target) return mid;
     if (arr[mid] < target)
         return binarySearch(arr, target, mid + 1, right);
     else
         return binarySearch(arr, target, left, mid - 1);
 }

 int search(int *nums, int numsSize, int target) {
     //直接解法
     const int len = sizeof(nums)/sizeof(nums[0]);
     for (int i = 0; i < len; ++i) {
         if (nums[i] == target) return i;
         if (nums[i] > target) return -1;
     }

     //二分查询解法
     int start = 0, end = (int) (numsSize) / 2;
     nums[end] < target ? end = numsSize - 1 : end;
     if (numsSize == 1) end = numsSize - 1;
     while (start <= end) {
         if (nums[start] == target) return start;
         if (nums[end] == target) return end;
         start += 1;
         end -= 1;
     }
     return -1;

     //递归解法
     return binarySearch(nums, target, 0, numsSize - 1);
 }

int main(void) {
     int arr[] = {1}, target = 3;
     printf("target = %d\n", search(arr, 10, target));
     return 0;
 }*/

/**删除链表中重复的元素 https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/*/
/*struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    // 如果链表为空直接返回原链表
    if(head == NULL || head->next == NULL) return head;
    struct ListNode * node = head;
    while(node != NULL && node->next != NULL){
        // 遍历有重复的元素，直接跳过
        if(node->val == node->next->val){
            node->next = node->next->next;
        }else{
            node = node->next;
        }
    }
    return head;
}*/

/**力扣[LCR 024. 反转链表](https://leetcode.cn/problems/UHnkqh/)*/

/*struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head) {
    // 创建一个新链表和有一个临时链表
    struct ListNode * newHead = NULL, *tmp;
    while(head){
        tmp = head->next; //让临时链表等于当前链表下一个
        head->next = newHead; // 让下一个链表变成新链表
        newHead = head; //把当前链表的值赋值给新链表
        head = tmp; // 把临时列表赋值给新链表
    }
    return newHead;
}*/

/**力扣[61. 旋转链表](https://leetcode.cn/problems/rotate-list/)*/
/*
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || k ==0) return head;
    // 计算链表长度
    int len = 1;
    struct ListNode * node = head;
    while(node->next) {
        node = node->next;
        len++;
    }

    //如果链表长度等于要旋转的长度，说明链表没有变化，直接返回原链表
    if(len == k) return head;

    node->next = head;
    //计算最终节点的位置
    int i = len - k % len;

    while (--i) head = head->next;

    struct ListNode * tmp = head->next; // 找到新的头节点
    head->next = NULL; // 切断尾部和头部
    return tmp;

}
*/

/**力扣[20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)*/
/*typedef char E;
// 创建栈
struct LNode {
    E element;
    struct LNode * next;
};

typedef struct LNode * List;

void initList(List l) {
    l->next = NULL;
};

bool pushList(List l , E e) {
    List node = malloc(sizeof(struct LNode));
    if(node == NULL) return false;
    node->next = l->next;
    node->element = e;
    l->next = node;
    return true;
}

bool isEmptyList(List l) {
    return l->next == NULL;
}

E popList(List l) {
    List top = l->next;
    l->next = l->next->next;
    E e = top->element;
    free(top);
    return e;
}

bool isValid(char* s) {
    // 获取字符串长度
    unsigned long len = strlen(s);
    //当字符串长度为奇数时代表这个括号是无效的
    if(len %2 == 1) return false;

    //初始化链表
    struct LNode head;
    initList(&head);

    //进行循环
    for(int i = 0; i < len; ++i) {
        // 每次区字符串的一个字符出来进行比较
        char c = s[i];
        // 如果是左括号就放进栈里
        if(c == '(' || c == '{' || c == '[') {
            pushList(&head, c);
        }else {
            //不是左括号进行判断，当栈里的内容为空时直接返回false
            if(isEmptyList(&head)) return false;
            //对字符进行依次判断，若是真的则进行出栈判断是否为另一半括号
            if(c==')') {
                if(popList(&head) != '(') return false;
            }else if(c == '}') {
                if(popList(&head) != '{') return false;
            }else {
                if(popList(&head) != '[') return false;
            }
        }
    }
    // 若字符串遍历完了栈里面还有内容，代表括号也不是完整的
    return isEmptyList(&head);
}*/

/**力扣[1539. 第 k 个缺失的正整数](https://leetcode.cn/problems/kth-missing-positive-number/)*/
/*int findKthPositive(int* arr, int arrSize, int k) {
    //暴力解法时间为O(n)
    /*int i = 0, j = 1;
    while (i < arrSize) {
        if(arr[i] ==j) {
            i++;
        }else {
            if(!--k) return j;
        }
        j++;
    }
    return j+k-1;#1#
    // 二分搜索
    if(arr[0]>k) return k;
    int left = 0,right = arrSize;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] - mid -1 >= k) {
            right = mid;
        }else {
            left = mid + 1;
        }
    }
    return k-(arr[left -1] - (left -1) -1) + arr[left -1];
}*/