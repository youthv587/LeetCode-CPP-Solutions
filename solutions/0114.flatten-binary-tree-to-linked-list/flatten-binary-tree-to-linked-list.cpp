/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (41.49%)
 * Total Accepted:    225.5K
 * Total Submissions: 543.4K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ?   1
 * ?  / \
 * ? 2   5
 * ?/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ?\
 * ? 2
 * ?  \
 * ?   3
 * ?    \
 * ?     4
 * ?      \
 * ?       5
 * ?        \
 * ?         6
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
class Solution {
  public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left != nullptr) {
            TreeNode *p = root->left;
            while (p->right != nullptr) p = p->right;
            p->right = root->right;
            root->right = root->left;
        }
        root->left = nullptr;
    }
};
