/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 *
 * https://leetcode.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (37.70%)
 * Total Accepted:    66.3K
 * Total Submissions: 175.9K
 * Testcase Example:  '5'
 *
 * You have a total of n coins that you want to form in a staircase shape,
 * where every k-th row must have exactly k coins.
 * ?
 * Given n, find the total number of full staircase rows that can be formed.
 *
 * n is a non-negative integer and fits within the range of a 32-bit signed
 * integer.
 *
 * Example 1:
 *
 * n = 5
 *
 * The coins can form the following rows:
 * ��
 * �� ��
 * �� ��
 *
 * Because the 3rd row is incomplete, we return 2.
 *
 *
 *
 * Example 2:
 *
 * n = 8
 *
 * The coins can form the following rows:
 * ��
 * �� ��
 * �� �� ��
 * �� ��
 *
 * Because the 4th row is incomplete, we return 3.
 *
 *
 */
class Solution {
  public:
    int arrangeCoins(int n) {
        long int row, dn, rn;
        for (row = 0, dn = 2 * static_cast<long>(n), rn = row * (row + 1); dn > rn; ++row, rn = row * (row + 1)) ;
        return row - (dn != rn);
    }
};
