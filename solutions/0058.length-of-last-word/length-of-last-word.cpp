/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.19%)
 * Total Accepted:    253.4K
 * Total Submissions: 787.2K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
#include <string>

using namespace std;

class Solution {
  public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        auto r_iter = s.crbegin(), r_end = s.crend();
        while (r_iter != r_end)
            if (*r_iter++ != ' ') ++ans;
            else if (ans != 0) break;
        return ans;
    }
};

