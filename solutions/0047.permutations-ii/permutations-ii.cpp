/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (39.58%)
 * Total Accepted:    228.5K
 * Total Submissions: 577.1K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 *
 *
 * Input: [1,1,2]
 * Output:
 * [
 * ? [1,1,2],
 * ? [1,2,1],
 * ? [2,1,1]
 * ]
 *
 *
 */
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
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
        int i = e;
        while (i < A.size()) {
            for (int j = e; j < i; ++j) if (A[i] == A[j]) goto NEXT;
            swap(A[e], A[i]);
            dfs(A, e + 1, ans);
            swap(A[e], A[i]);
        NEXT:
            ++i;
        }
    }
};
