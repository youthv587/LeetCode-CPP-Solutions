/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.15%)
 * Total Accepted:    278.3K
 * Total Submissions: 839.6K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> ans = {-1, -1};
        if (A.size() == 0) return ans;

        int low = 0, high = A.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] >= target) high = mid;
            else low = mid + 1;
        }
        if (A[low] != target) return ans;
        ans.front() = low;
        low = 0;
        high = A.size() - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (A[mid] <= target) low = mid;
            else high = mid - 1;
        }
        ans.back() = low;
        return ans;
    }
};
