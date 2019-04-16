/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 *
 * https://leetcode.com/problems/maximum-swap/description/
 *
 * algorithms
 * Medium (39.37%)
 * Total Accepted:    34.2K
 * Total Submissions: 86.8K
 * Testcase Example:  '2736'
 *
 *
 * Given a non-negative integer, you could swap two digits at most once to get
 * the maximum valued number. Return the maximum valued number you could get.
 *
 *
 * Example 1:
 *
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 *
 *
 *
 * Example 2:
 *
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 *
 *
 *
 *
 * Note:
 *
 * The given number is in the range [0, 10^8]
 *
 *
 */
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maximumSwap(int num) {
        string n = to_string(num);
        trans(n, 0, n.size());
        return atoi(n.c_str());
    }

  private:
    void trans(string &s, int b, int e) {
        if (b >= e) return;
        auto pmax = max_element(s.rbegin(), s.rend() - b);
        if (*pmax != s[b]) swap(s[b], *pmax);
        else trans(s, b + 1, e);
    }
};
