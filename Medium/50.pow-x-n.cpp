/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (27.71%)
 * Total Accepted:    300.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */
#include <climits>

class Solution {
  public:
    double myPow(double x, int n) {
        double p = 1.0;
        if (n < 0) {
            if (n == INT_MIN)
                return 1.0 / (myPow(x, INT_MAX) * x);
            else
                return 1.0 / myPow(x, -n);
        }
        if (n == 0) return 1.0;
        for (; n > 0; x *= x, n >>= 1) if (n & 1) p *= x;
        return p;
    }
};

