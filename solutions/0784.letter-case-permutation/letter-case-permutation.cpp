/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (55.96%)
 * Total Accepted:    42.5K
 * Total Submissions: 75.9K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible
 * strings we could create.
 *
 *
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 *
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 *
 * Input: S = "12345"
 * Output: ["12345"]
 *
 *
 * Note:
 *
 *
 * S will be a string with length between 1 and 12.
 * S will consist only of letters or digits.
 *
 *
 */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string str)
    {
        vector<string> res;
        dfs(str, 0, res);
        return res;
    }

    void dfs(string &str, int b, vector<string> &res)
    {
        if (b == str.length()) {
            res.push_back(str);
            return;
        }
        if (isdigit(str[b])) {
            dfs(str, b + 1, res);
            return;
        }

        str[b] = toupper(str[b]);
        dfs(str, b + 1, res);

        str[b] = tolower(str[b]);
        dfs(str, b + 1, res);
    }
};
