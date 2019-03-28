/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (34.43%)
 * Total Accepted:    167.1K
 * Total Submissions: 485.4K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ¡Ý s. If there isn't
 * one, return 0 instead.
 * 
 * Example:?
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n).?
 * 
 */
#include <climits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (accumulate(nums.begin(), nums.end(), 0) < s) return 0;

        int sz = nums.size(), min = sz + 1;
        int i, j, sum;
        for (i = j = sum = 0; i < sz; ++i, j = i, sum = 0) {
            while (j < sz && (sum += nums[j]) < s) ++j;
            if (j == sz) break;
            min = j - i + 1 < min ? j - i + 1 : min;
        }
        return min;
    }
};

