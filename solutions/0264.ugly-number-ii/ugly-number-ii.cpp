/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (35.91%)
 * Total Accepted:    100.5K
 * Total Submissions: 279.4K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5.?
 *
 * Example:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note: ?
 *
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 */
#include <algorithm>
#include <vector>

class Solution {
  public:
    int nthUglyNumber(int n) {
        std::vector<int> vi(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (vi.size() < n) {
            int d2 = vi[i2] * 2, d3 = vi[i3] * 3, d5 = vi[i5] * 5;
            int di = std::min(d2, std::min(d3, d5));
            if (di == d2) ++i2;
            if (di == d3) ++i3;
            if (di == d5) ++i5;
            vi.push_back(di);
        }
        return vi.back();
    }
};
