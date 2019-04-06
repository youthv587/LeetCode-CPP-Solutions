/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (41.92%)
 * Total Accepted:    309K
 * Total Submissions: 726.6K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums?such that the sum is closest to?target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 */
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0, res = accumulate(nums.begin(), nums.begin() + 3, 0);
        for (int first = 0; first < nums.size() - 2; ++first) {
            int second = first + 1, third = nums.size() - 1;
            while (second < third) {
                sum = nums[first] + nums[second] + nums[third];
                res = abs(res - target) > abs(sum - target) ? sum : res;
                if (sum == target) return sum;
                else if (sum > target) --third;
                else ++second;
            }
        }
        return res;
    }
};
