/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.73%)
 * Total Accepted:    384.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        if (nums.size() == 0) return -1;
        auto low = nums.begin(), high = nums.end() - 1;
        while (low <= high) {
            auto mid = low + (high - low) / 2;
            if (*mid == target) return mid - nums.begin();
            if (*mid >= *low) {
                if (*low <= target && target < *mid) high = mid - 1;
                else low = mid + 1;
            } else {
                if (*low > target && target > *mid) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};

