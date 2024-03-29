/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.55%)
 * Total Accepted:    340.4K
 * Total Submissions: 2.3M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which?converts a string to an integer.
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * 
 * 
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [?2^31,? 2^31?? 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (2^31?? 1) or
 * INT_MIN (?2^31) is returned.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "42"
 * Output: 42
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical 
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 * 
 * Example 5:
 * 
 * 
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (?2^31) is returned.
 * 
 */
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

class Solution {
  public:
    int myAtoi(string str) {
        if (str.length() == 0) return 0;

        long ans = 0;
        int isneg = 1;
        auto front = str.begin(), back = str.end() - 1;
        while (front < back && isspace(*front)) ++front;
        while (front < back && isspace(*back)) --back;
        string s(front, back + 1);
        if (*front == '-') {
            isneg = -1;
            s.erase(s.begin());
        } else if (*front == '+') {
            s.erase(s.begin());
        }

        for (auto &c : s) {
            if (isdigit(c)) ans = ans * 10 + (c - '0');
            else break;
            if (ans > INT_MAX) break;
        }
        ans *= isneg;

        if (ans > INT_MAX) return INT_MAX;
        else if (ans < INT_MIN) return INT_MIN;
        else return static_cast<int>(ans);
    }
};

