#include <stdio.h>
#include <stdlib.h>

/**给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1*/
//初始化search函数
 int search(int *arr, int i, int target);

 int main(void) {
     int arr[] = {1}, target = 3;
     printf("target = %d\n", search(arr, 10, target));
     return 0;
 }

 //递归解法
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



