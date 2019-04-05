/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (41.83%)
 * Total Accepted:    89.5K
 * Total Submissions: 213.9K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 *
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 *
 *
 *
 * Note:
 *
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 *
 *
 *
 */
#include <map>
#include <vector>

using namespace std;

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        map<int, int> map;
        int sum = 0, res = 0;
        map[0] = 1;
        for (const auto &n : nums) {
            res += map[(sum += n) - k];
            ++map[sum];
        }
        return res;
    }
};
