/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.10%)
 * Total Accepted:    849.9K
 * Total Submissions: 3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ?            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 */

#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        char ch;
        int slen = static_cast<int>(s.length());

        if (slen == 0) return 0;

        map<char, int> cimap;
        int mslen = 0, start = 0;
        for (int i = 0; i != slen; ++i) {
            ch = s[i];

            if (cimap.find(ch) != cimap.end())
                start = max(cimap[ch] + 1, start);
            mslen = max(mslen, i - start + 1);
            cimap[ch] = i;
        }

        return mslen;
    }
};
