/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (51.59%)
 * Total Accepted:    342.1K
 * Total Submissions: 663K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ? [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> v;
        dfs(nums, 0, v, ans);
        return ans;
    }

  private:
    void dfs(vector<int>& nums, int pos, vector<int> &v, vector<vector<int>> &ans) {
        ans.push_back(v);
        for (int i = pos; i < nums.size(); ++i) {
            v.push_back(nums[i]);
            dfs(nums, i + 1, v, ans);
            v.pop_back();
        }
    }
};


