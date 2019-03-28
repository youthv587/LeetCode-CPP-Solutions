/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (43.07%)
 * Total Accepted:    487.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray?(containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation:?[4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int sz = nums.size(), ans = nums[0];
        for (int i = 1; i < sz; ++i) {
            dp.push_back((dp[i - 1] + nums[i] < nums[i]) ? nums[i]
                                                         : dp[i - 1] + nums[i]);
            if (ans < dp[i]) ans = dp[i];
        }
        return ans;
    }
};

