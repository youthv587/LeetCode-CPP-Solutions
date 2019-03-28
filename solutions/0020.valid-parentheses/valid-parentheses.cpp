/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.11%)
 * Total Accepted:    543.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is?also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
#include <map>
#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        map<char, char> map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> sta;
        for (auto iter = s.cbegin(); iter != s.cend(); ++iter) {
            if (sta.size() == 0) {
                sta.push(*iter);
                continue;
            }
            if (*iter == map[sta.top()]) sta.pop();
            else sta.push(*iter);
        }
        return sta.size() == 0 ? true : false;
    }
};

