/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (35.06%)
 * Total Accepted:    131.5K
 * Total Submissions: 375K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
#include <vector>

using namespace std;

class Solution {
  public:
    vector<TreeNode *> generateTrees(int n) {
        return n == 0 ? vector<TreeNode *>() : build(1, n);
    }

  private:
    vector<TreeNode *> build(int s, int e) {
        vector<TreeNode *> ans;
        if (s > e) return {nullptr};
        for (int i = s; i <= e; ++i) {
            auto left = build(s, i - 1), right = build(i + 1, e);
            for (auto &lnode : left) {
                for (auto &rnode : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

