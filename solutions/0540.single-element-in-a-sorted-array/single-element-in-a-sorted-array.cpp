/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (57.28%)
 * Total Accepted:    49.9K
 * Total Submissions: 87K
 * Testcase Example:  '[1,1,2]'
 *
 * 
 * Given a sorted array consisting of only integers where every element appears
 * twice except for one element which appears once. Find this single element
 * that appears only once. 
 * 
 * 
 * Example 1:
 * 
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 * 
 * 
 * 
 * Note:
 * Your solution should run in O(log n) time and O(1) space.
 * 
 * 
 */
#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 1) {
                if (nums[mid] == nums[mid - 1]) low = mid + 1;
                else high = mid;
            } else {
                if (nums[mid] == nums[mid + 1]) low = mid + 1;
                else high = mid;
            }           
        }
        return nums[low];
    }
};

