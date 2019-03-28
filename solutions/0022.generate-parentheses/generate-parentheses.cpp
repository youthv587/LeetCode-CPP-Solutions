/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (53.72%)
 * Total Accepted:    313.2K
 * Total Submissions: 583K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ? "((()))",
 * ? "(()())",
 * ? "(())()",
 * ? "()(())",
 * ? "()()()"
 * ]
 * 
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        dfs(n, n, s, ans);
        return ans;
    }

  private:
    void dfs(int releft, int reright, string str, vector<string> &ans) {
        if (releft > reright)
            return;
        else if (releft == 0 && reright == 0)
            ans.push_back(str);
        else {
            if (releft > 0) dfs(releft - 1, reright, str + "(", ans);
            if (reright > 0) dfs(releft, reright - 1, str + ")", ans);
        }
    }
};
