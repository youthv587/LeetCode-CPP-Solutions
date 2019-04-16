/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (33.93%)
 * Total Accepted:    68.3K * Total Submissions: 201.1K
 * Testcase Example:  '"aba"'
 *
 *
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 *
 *
 * Example 1:
 *
 * Input: "aba"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 *
 *
 *
 * Note:
 *
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 *
 *
 */
#include <string>

using namespace std;

class Solution {
  public:
    bool validPalindrome(string str) {
        for (int i = 0, j = str.length() - 1; i < j; ++i, --j)
            if (str[i] != str[j]) return isPalindrome(str, i + 1, j) || isPalindrome(str, i, j - 1);
        return true;
    }

  private:
    bool isPalindrome(string &str, int begin, int end) {
        for (int i = begin, j = end; i < j; ++i, --j)
            if (str[i] != str[j]) return false;
        return true;
    }
};

