/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (31.06%)
 * Total Accepted:    297.8K
 * Total Submissions: 958.9K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string convert(string s, int numRows) {
        vector<string> vs(numRows);
        int cur = 0, len = s.length();
        while (cur < len) {
            for (int i = 0; i < numRows && cur < len; ++i) vs[i].push_back(s[cur++]);
            for (int i = numRows - 2; i > 0 && cur < len; --i) vs[i].push_back(s[cur++]);
        }
        for (auto iter = ++vs.cbegin(); iter != vs.cend(); ++iter) vs.front().append(*iter);
        return vs.front();
    }
};

