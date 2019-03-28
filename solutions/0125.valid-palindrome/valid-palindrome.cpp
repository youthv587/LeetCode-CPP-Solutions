/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (30.49%)
 * Total Accepted:    332.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note:?For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
#include <cstring>
#include <string>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        string str;
        for (auto iter = s.cbegin(); iter != s.cend(); ++iter)
            if (isalnum(*iter)) str += tolower(*iter);
        for (auto left = str.begin(), right = str.end() - 1; left < right; ++left, --right)
            if (*left != *right) return false;
        return true;
    }
};

