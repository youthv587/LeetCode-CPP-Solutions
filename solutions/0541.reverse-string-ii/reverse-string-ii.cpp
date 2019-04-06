/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (45.15%)
 * Total Accepted:    56.7K
 * Total Submissions: 125.5K
 * Testcase Example:  '"abcdefg"\n2'
 *
 *
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 *
 *
 * Example:
 *
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 *
 *
 *
 * Restrictions:
 *
 * ?The string consists of lower English letters only.
 * ?Length of the given string and k will in the range [1, 10000]
 *
 */
#include <string>

using namespace std;

class Solution {
  public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2 * k)
            reverse_str(i, i + k > s.length() ? s.length() : i + k, s);
        return s;
    }

  private:
    void reverse_str(int b, int e, string &str) {
        while (b < e) swap(str[b++], str[e-- - 1]);
    }
};
