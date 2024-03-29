/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (42.63%)
 * Total Accepted:    267.1K
 * Total Submissions: 626.5K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., ?[0,1,2,4,5,6,7]?might become ?[4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
#include <vector>

using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
        auto left = nums.begin(), right = nums.end() - 1;
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (*mid > *right) left = mid + 1;
            else right = mid;
        }
        return *left;
    }
};

