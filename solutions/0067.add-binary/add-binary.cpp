/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.32%)
 * Total Accepted:    285K
 * Total Submissions: 743.7K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or?0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
#include <algorithm>
#include <string>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int alen = a.length(), blen = b.length();
        for (int i = 0; i < alen || i < blen; ++i) {
            int p = i < alen ? a[alen - i - 1] - '0' : 0;
            int q = i < blen ? b[blen - i - 1] - '0' : 0;
            int tmp = p + q + carry;
            carry = tmp / 2;
            ans.insert(ans.begin(), tmp % 2 + '0');
        }
        if (carry == 1) ans.insert(ans.begin(), carry + '0');
        return ans;
    }
};

