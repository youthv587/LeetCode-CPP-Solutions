/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (70.13%)
 * Total Accepted:    225.2K
 * Total Submissions: 321.2K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 ¡Ü x, y < 2^31.
 * 
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ?      ¡ü   ¡ü
 * 
 * The above arrows point to positions where the corresponding bits are
 * different.
 * 
 * 
 */
class Solution {
  public:
    int hammingDistance(int x, int y) {
        int ans = 0, z = x ^ y;
        while (z != 0) {
            ans += z & 1;
            z >>= 1;
        }
        return ans;
    }
};

