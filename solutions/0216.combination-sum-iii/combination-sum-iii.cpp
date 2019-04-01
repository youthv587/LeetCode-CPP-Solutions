/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (50.78%)
 * Total Accepted:    116.1K
 * Total Submissions: 228.5K
 * Testcase Example:  '3\n7'
 *
 *
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 *
 * Note:
 *
 *
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 *
 *
 * Example 2:
 *
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 *
 *
 */
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> out;
        dfs(n, k, 1, out, ans);
        return ans;
    }

  private:
    void dfs(int n, int k, int s, vector<int> &out, vector<vector<int>> &ans) {
        if (n == 0 && k == 0) {
            ans.push_back(out);
            return;
        }
        for (int i = s; i <= 9; ++i) {
            out.push_back(i);
            dfs(n - i, k - 1, i + 1, out, ans);
            out.pop_back();
        }
    }
};
