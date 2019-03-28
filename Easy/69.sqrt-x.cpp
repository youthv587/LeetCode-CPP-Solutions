/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (30.91%)
 * Total Accepted:    342.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
class Solution {
  public:
    int mySqrt(int x) {
        if (x < 1) return 0;

        int left = 1, right = x, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid == x / mid)
                return mid;
            else if (mid > x / mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};

