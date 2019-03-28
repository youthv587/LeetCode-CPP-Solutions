/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.85%)
 * Total Accepted:    506.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string longestPalindrome(string s) {
        int len = s.length();
        int mslen = 1, start = 0;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                if ((i - j <= 2 || dp[j + 1][i - 1]) && s[i] == s[j])
                    dp[j][i] = true;
                if (dp[j][i] && ((i - j + 1) > mslen)) {
                    mslen = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, mslen);
    }
};

