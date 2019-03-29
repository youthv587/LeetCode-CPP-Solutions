/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (47.28%)
 * Total Accepted:    317.6K
 * Total Submissions: 671.5K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates?where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates?unlimited number of
 * times.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ? [7],
 * ? [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> out;
        dfs(candidates, 0, target, out, ans);
        return ans;
    }

  private:
    void dfs(vector<int> &A, int s, int target, vector<int> &out, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(out);
            return;
        }
        for (int i = s; i < A.size(); ++i) {
            if (target >= 0) {
                out.push_back(A[i]);
                dfs(A, i, target - A[i], out, ans);
                out.pop_back();
            } else
                break;
        }
    }
};
