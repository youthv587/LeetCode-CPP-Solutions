/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (31.61%)
 * Total Accepted:    153.9K
 * Total Submissions: 486.7K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * Note:
 * 
 * 
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't?be any?divide?by zero
 * operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation: 
 * ? ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 */
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 0) return 0;

        stack<string> stack;
        for (auto &str : tokens) {
            if (isOp(str)) {
                string s1 = stack.top();
                stack.pop();
                string s2 = stack.top();
                stack.pop();
                stack.push(to_string(doOp(s2, s1, str)));
            } else {
                stack.push(str);
            }
        }
        return atoi(stack.top().c_str());
    }

    bool isOp(string str) {
        if (str == "+" || str == "-" || str == "*" || str == "/") return true;
        return false;
    }

    int doOp(string &s1, string &s2, string &op) {
        int t1 = atoi(s1.c_str());
        int t2 = atoi(s2.c_str());

        switch (op.front()) {
        case '+': return t1 + t2;
        case '-': return t1 - t2;
        case '*': return t1 * t2;
        case '/': return t1 / t2;
        }
        return 0;
    }
};

