/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (42.75%)
 * Total Accepted:    1.6M
 * Total Submissions: 3.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 *
 *
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int>::const_iterator begin = nums.cbegin(), end = nums.cend();
        vector<int>::const_iterator left, right;
        for (left = begin; left != end; ++left)
            for (right = left + 1; right != end; ++right)
                if (*left + *right != target)
                    continue;
                else
                    goto RETURN;
    RETURN:
        return vector<int>{static_cast<int>(left - begin),
                           static_cast<int>(right - begin)};
    }
};
