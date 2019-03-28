/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (45.40%)
 * Total Accepted:    160.7K
 * Total Submissions: 353.9K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty?array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (const auto &n : nums) {
            ones = (ones ^ n) & ~twos;
            twos = (twos ^ n) & ~ones;
        }
        return ones;
    }
};
