//
//  33_Search_in_Rotated_Sorted_Array_h.hpp
//  LeetCode
//
//  Created by Johnkui Wen on 16/3/21.
//  Copyright © 2016年 Johnkui Wen. All rights reserved.
//

#ifndef _33_Search_in_Rotated_Sorted_Array_h_hpp
#define _33_Search_in_Rotated_Sorted_Array_h_hpp

#include <vector>
using namespace std;

/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.
 */

class Solution {
public:
    // 方案1：找到pivot 然后选择一端进行二分法搜索
     int binarySearch(vector<int>& nums, int start, int end, int target) {
         if((end - start) == 1 || end == start) {
             if(nums[start] == target) return start;
             else if(nums[end] == target) return end;
             else return -1;
         }
    
         int middle = (end + start) / 2;
         if(nums[middle] == target) return middle;
         else if(nums[middle] < target) start = middle;
         else end = middle;
    
         return binarySearch(nums,start,end,target);
     }
     //找到pivot
     int indexOfPivot(vector<int>& nums) {
         int index = -1;
    
         if(nums.size() < 2) return index;
    
         for(int i = 1; i < nums.size(); i++) {
             if(nums[i] < nums[i-1]) {
                 index = i;
                 break;
             }
         }
    
         return index;
     }
    
     int search(vector<int>& nums, int target) {
         if(nums.size() == 0) return -1;
         int pivot = indexOfPivot(nums);
         if(pivot == -1) return binarySearch(nums, 0, nums.size() - 1, target);
         else if(nums[pivot] <= target && target <= nums[nums.size()-1]) return binarySearch(nums,pivot,nums.size() - 1, target);
         else if(nums[pivot - 1] >= target) return binarySearch(nums,0,pivot - 1, target);
         else return -1;
     }
    
    //方案二：直接二分法
//    int search(const vector<int>& nums, int target) {
//        int first = 0, last = nums.size();
//        while (first != last) {
//            const int mid = first + (last - first) / 2;
//            if (nums[mid] == target)
//                return mid;
//            if (nums[first] <= nums[mid]) {
//                if (nums[first] <= target && target < nums[mid])
//                    last = mid;
//                else
//                    first = mid + 1;
//            } else {
//                if (nums[mid] < target && target <= nums[last-1])
//                    first = mid + 1;
//                else
//                    last = mid;
//            }
//        }
//        return -1;
//    }
};

#endif /* _33_Search_in_Rotated_Sorted_Array_h_hpp */
