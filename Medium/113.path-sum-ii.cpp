/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (39.81%)
 * Total Accepted:    218.9K
 * Total Submissions: 550K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ans;
        vector<int> tmp;
        if (root == nullptr) return ans;
        dfs(root, ans, tmp, sum);
        return ans;
    }

  private:
    void dfs(TreeNode *root, vector<vector<int>> &ans, vector<int> &tmp, int sum) {
        if (root == nullptr) return;
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            tmp.push_back(root->val);
            ans.push_back(vector<int>(tmp));
            tmp.pop_back();
            return;
        }
        tmp.push_back(root->val);
        dfs(root->left, ans, tmp, sum);
        dfs(root->right, ans, tmp, sum);
        tmp.pop_back();
    }
};

