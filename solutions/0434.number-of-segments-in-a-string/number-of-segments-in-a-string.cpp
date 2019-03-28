/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (36.74%)
 * Total Accepted:    52.7K
 * Total Submissions: 143.4K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

class Solution {
  public:
    int countSegments(string s) {
        int cnt = 0, i = 0;
        while (i < s.length()) {
            while (i < s.length() && isspace(s[i])) ++i;
            cnt += (i == s.length() ? 0 : 1);
            while (i < s.length() && !isspace(s[i])) ++i;
        }
        return cnt;
    }
};

