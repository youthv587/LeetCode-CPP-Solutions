/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (41.47%)
 * Total Accepted:    174.5K
 * Total Submissions: 420.7K
 * Testcase Example:  '27'
 *
 * Given an integer, write a function to determine if it is a power of three.
 * 
 * Example 1:
 * 
 * 
 * Input: 27
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: true
 * 
 * Example 4:
 * 
 * 
 * Input: 45
 * Output: false
 * 
 * Follow up:
 * Could you do it without using any loop / recursion?
 */
#include <climits>
#include <cmath>

class Solution {
  public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return static_cast<int>(pow(3, static_cast<int>(log(INT_MAX) / log(3)))) % n == 0;
    }
};

