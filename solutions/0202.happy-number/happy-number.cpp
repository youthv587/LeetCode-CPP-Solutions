/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (44.65%)
 * Total Accepted:    222.9K
 * Total Submissions: 498.6K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 *
 * Example:?
 *
 *
 * Input: 19
 * Output: true
 * Explanation:
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 */
#include <set>

class Solution {
  public:
    bool isHappy(int n) {
        std::set<int> set;
        int sum;
    NEXT:
        sum = 0;
        while (n) {
            sum += pow(n % 10);
            n /= 10;
        }

        if (sum == 1) return true;
        else if (set.find(sum) == set.end()) {
            set.insert(n = sum);
            goto NEXT;
        }
        else return false;
    }

  private:
    int pow(int n) { return n * n; }
};

