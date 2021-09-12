/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator it = nums.begin();
        int i = 0;
        for(i = 0; i < nums.size(); i++) {
            it = find(nums.begin(), nums.end(), target-nums[i]);
            if(i == it - nums.begin()) 
                it = find(nums.begin() + i + 1, nums.end(), target-nums[i]);
            if(it != nums.end()) break;
        }
        return {i, (int)(it - nums.begin())};
    }
};


// @lc code=end

