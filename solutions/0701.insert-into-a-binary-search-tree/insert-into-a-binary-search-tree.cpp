/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 *
 * https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (74.45%)
 * Total Accepted:    35.7K
 * Total Submissions: 47.9K
 * Testcase Example:  '[4,2,7,1,3]\n5'
 *
 * Given the root node of a binary search tree (BST) and a value to be inserted
 * into the tree,?insert the value into the BST. Return the root node of the
 * BST after the insertion. It is guaranteed that the new value does not exist
 * in the original BST.
 *
 * Note that there may exist?multiple valid ways for the?insertion, as long as
 * the tree remains a BST after insertion. You can return any of them.
 *
 * For example,?
 *
 *
 * Given the tree:
 * ?       4
 * ?      / \
 * ?     2   7
 * ?    / \
 * ?   1   3
 * And the value to insert: 5
 *
 *
 * You can return this binary search tree:
 *
 *
 * ?        4
 * ?      /   \
 * ?     2     7
 * ?    / \   /
 * ?   1   3 5
 *
 *
 * This tree is also valid:
 *
 *
 * ?        5
 * ?      /   \
 * ?     2     7
 * ?    / \
 * ?   1   3
 * ?        \
 * ?         4
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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr)
            root = new TreeNode(val);
        else if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};
