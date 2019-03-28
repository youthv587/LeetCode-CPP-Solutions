/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.15%)
 * Total Accepted:    428.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";

        sort(strs.begin(), strs.end(), [](string &s1, string &s2) -> bool {
            return s1.size() < s2.size();
        });

        string prefix = strs[0];
        for (auto &str : strs)
            while (str.compare(0, prefix.length(), prefix) != 0)
                prefix.erase(prefix.end() - 1);
        return prefix;
    }
};

