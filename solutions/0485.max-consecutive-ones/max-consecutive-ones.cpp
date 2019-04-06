/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (54.67%)
 * Total Accepted:    129.5K
 * Total Submissions: 236.6K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 *
 * Example 1:
 *
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s.
 * ?   The maximum number of consecutive 1s is 3.
 *
 *
 *
 * Note:
 *
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 *
 *
 */
#include <vector>

using namespace std;

class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int res = 0, cur = 0;
        for (const auto &n : nums) {
            cur = n ? (cur + 1) : 0;
            res = cur > res ? cur : res;
        }
        return res;
    }
};
