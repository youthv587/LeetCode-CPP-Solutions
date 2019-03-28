/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (59.36%)
 * Total Accepted:    432.4K
 * Total Submissions: 728.4K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */
#include <vector>

using namespace std;

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int result;
        vector<int>::const_iterator begin = nums.cbegin(), end = nums.cend();
        for (result = *begin++; begin != end; ++begin) result ^= *begin;
        return result;
    }
};

