/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (40.60%)
 * Total Accepted:    207.6K
 * Total Submissions: 511.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates?where the candidate
 * numbers sums to target.
 *
 * Each number in candidates?may only be used once in the combination.
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
 * Input: candidates =?[10,1,2,7,6,1,5], target =?8,
 * A solution set is:
 * [
 * ? [1, 7],
 * ? [1, 2, 5],
 * ? [2, 6],
 * ? [1, 1, 6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates =?[2,5,2,1,2], target =?5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, out, ans);
        return ans;
    }

  private:
    void dfs(vector<int> &A, int s, int target, vector<int> &out, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(out);
            return;
        }
        int i = s;
        while (i < A.size()) {
            if (target >= 0) {
                for (int j = s; j < i; ++j) if (A[i] == A[j]) goto NEXT;
                out.push_back(A[i]);
                dfs(A, i + 1, target - A[i], out, ans);
                out.pop_back();
            } else
                break;
        NEXT:
            ++i;
        }
    }
};
