/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (47.63%)
 * Total Accepted:    92.2K
 * Total Submissions: 193.4K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 *
 *
 * Example:
 *
 * Input:
 * "abccccdd"
 *
 * Output:
 * 7
 *
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 *
 */
#include <map>
#include <string>

using namespace std;

class Solution {
  public:
    int longestPalindrome(string s) {
        map<char, int> map;
        int odd = 0, res = 0;
        for (const auto &ch : s) ++map[ch];
        for (const auto &p : map) {
            res += p.second;
            odd += p.second & 1;
        }
        return res - odd + static_cast<bool>(odd);
    }
};
