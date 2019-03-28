/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (63.36%)
 * Total Accepted:    116.3K
 * Total Submissions: 183.5K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    string reverseWords(string s) {
        stack<char> stack;
        string ans;
        for (auto &c : s) {
            if (c != ' ') stack.push(c);
            else {
                while (!stack.empty()) {
                    ans += stack.top();
                    stack.pop();
                }
                ans += ' ';
            }
        }
        while (!stack.empty()) {
            ans += stack.top();
            stack.pop();
        }
        return ans;
    }
};

