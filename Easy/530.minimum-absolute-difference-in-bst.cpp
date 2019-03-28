/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (49.98%)
 * Total Accepted:    55.4K
 * Total Submissions: 110.8K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note: There are at least two nodes in this BST.
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
#include <algorithm>
#include <vector>

class Solution {
  public:
    int getMinimumDifference(TreeNode *root) {
        std::vector<int> values;
        inorder(root, values);
        int ans = values.back();
        for (int i = 1; i < values.size(); ++i)
            ans = abs(values[i] - values[i - 1]) < ans ? abs(values[i] - values[i - 1]) : ans;
        return ans;
    }

    void inorder(TreeNode *root, std::vector<int> &values) {
        if (root == nullptr) return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
};

