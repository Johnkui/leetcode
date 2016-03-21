//
//  main.m
//  LeetCode
//
//  Created by Johnkui Wen on 16/3/21.
//  Copyright © 2016年 Johnkui Wen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <time.h>
#import "33_Search_in_Rotated_Sorted_Array_h.hpp"

int main(int argc, const char * argv[]) {
    @autoreleasepool {

        vector<int> nums;
        nums.push_back(1);
        nums.push_back(3);
        nums.push_back(5);
        
        int target = 4;
        Solution s;
        
        clock_t start, end;
        start = clock();
        int index = s.search(nums, target);
        end = clock();
        
        NSLog(@"index = %d, time = %lf", index, (end - start) * 1000.0 / (CLOCKS_PER_SEC));
        
    }
    return 0;
}
