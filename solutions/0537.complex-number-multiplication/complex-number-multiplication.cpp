/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 *
 * https://leetcode.com/problems/complex-number-multiplication/description/
 *
 * algorithms
 * Medium (65.24%)
 * Total Accepted:    34.9K
 * Total Submissions: 53.5K
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 *
 * Given two strings representing two complex numbers.
 *
 *
 * You need to return a string representing their multiplication. Note i^2 = -1
 * according to the definition.
 *
 *
 * Example 1:
 *
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i^2 + 2 * i = 2i, and you need convert
 * it to the form of 0+2i.
 *
 *
 *
 * Example 2:
 *
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i^2 - 2 * i = -2i, and you need convert
 * it to the form of 0+-2i.
 *
 *
 *
 * Note:
 *
 * The input strings will not have extra blank.
 * The input strings will be given in the form of a+bi, where the integer a and
 * b will both belong to the range of [-100, 100]. And the output should be
 * also in this form.
 *
 *
 */
#include <string>

using namespace std;

class Solution {
  public:
    string complexNumberMultiply(string a, string b) {
        auto pos = find(a.begin(), a.end(), '+');
        int real_a = atoi(string(a.begin(), pos).c_str()),
            imag_a = atoi(string(pos + 1, a.end()).c_str());
        pos = find(b.begin(), b.end(), '+');
        int real_b = atoi(string(b.begin(), pos).c_str()),
            imag_b = atoi(string(pos + 1, b.end()).c_str());
        return to_string(real_a * real_b - imag_a * imag_b) + "+" + to_string(real_a * imag_b + real_b * imag_a) + "i";
    }
};
