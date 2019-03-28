/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (41.74%)
 * Total Accepted:    193.2K
 * Total Submissions: 462.8K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, v, ans);
        return ans;
    }

  private:
    void dfs(vector<int> &nums, int pos, vector<int> &v, vector<vector<int>> &ans) {
        ans.push_back(v);
        for (int i = pos; i < nums.size(); ++i) {
            v.push_back(nums[i]);
            dfs(nums, i + 1, v, ans);
            v.pop_back();
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
        }
    }
};

