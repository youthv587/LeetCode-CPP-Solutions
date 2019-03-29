/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (53.98%)
 * Total Accepted:    352.8K
 * Total Submissions: 653.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ? [1,2,3],
 * ? [1,3,2],
 * ? [2,1,3],
 * ? [2,3,1],
 * ? [3,1,2],
 * ? [3,2,1]
 * ]
 *
 *
 */
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        dfs(nums, 0, ans);
        return ans;
    }

  private:
    void dfs(vector<int> &A, int e, vector<vector<int>> &ans) {
        if (e == A.size()) {
            ans.push_back(A);
            return;
        }
        for (int i = e; i < A.size(); ++i) {
            swap(A[e], A[i]);
            dfs(A, e + 1, ans);
            swap(A[e], A[i]);
        }
    }
};
