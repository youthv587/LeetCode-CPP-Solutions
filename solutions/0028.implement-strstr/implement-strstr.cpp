/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.49%)
 * Total Accepted:    397.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's?strstr() and Java's?indexOf().
 * 
 */
#include <string>

using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle) {
        const int hlen = haystack.length(), nlen = needle.length();

        if (nlen == 0) return 0;

        for (int i = 0; i < hlen - nlen + 1; ++i)
            if (haystack.substr(i, nlen) == needle) return i;
        return -1;
    }
};

