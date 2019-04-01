/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (46.52%)
 * Total Accepted:    191.6K
 * Total Submissions: 411.1K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 * Example:
 *
 *
 * Input:?n = 4, k = 2
 * Output:
 * [
 * ? [2,4],
 * ? [3,4],
 * ? [2,3],
 * ? [1,2],
 * ? [1,3],
 * ? [1,4],
 * ]
 *
 *
 */
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> out;
        dfs(n, k, 1, out, ans);
        return ans;
    }

  private:
    void dfs(int n, int k, int s, vector<int> &out, vector<vector<int>> &ans) {
        if (k == 0) {
            ans.push_back(out);
            return;
        }
        for (int i = s; i <= n; ++i) {
            out.push_back(i);
            dfs(n, k - 1, i + 1, out, ans);
            out.pop_back();
        }
    }
};
