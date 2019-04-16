/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 *
 * https://leetcode.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (69.51%)
 * Total Accepted:    72.5K
 * Total Submissions: 104.2K
 * Testcase Example:  '1\n22'
 *
 *
 * A self-dividing number is a number that is divisible by every digit it
 * contains.
 *
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 ==
 * 0, and 128 % 8 == 0.
 *
 * Also, a self-dividing number is not allowed to contain the digit zero.
 *
 * Given a lower and upper number bound, output a list of every possible self
 * dividing number, including the bounds if possible.
 *
 * Example 1:
 *
 * Input:
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 *
 *
 *
 * Note:
 * The boundaries of each input argument are 1 .
 *
 */
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        int cur = left;
        while (cur <= right) {
            int rem = cur;
            while (rem) {
                if (rem % 10 != 0 && cur % (rem % 10) == 0) rem /= 10;
                else goto NEXT;
            }
            res.push_back(cur);
        NEXT: ++cur;
        }
        return res;
    }
};
