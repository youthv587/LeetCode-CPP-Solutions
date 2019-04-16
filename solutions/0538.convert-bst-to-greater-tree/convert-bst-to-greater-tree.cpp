/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (50.35%)
 * Total Accepted:    73.2K
 * Total Submissions: 145.4K
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 *
 *
 * Example:
 *
 * Input: The root of a Binary Search Tree like this:
 * ?             5
 * ?           /   \
 * ?          2     13
 *
 * Output: The root of a Greater Tree like this:
 * ?            18
 * ?           /   \
 * ?         20     13
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
    TreeNode *convertBST(TreeNode *root) {
        int accu = 0;
        order(root, accu);
        return root;
    }

  private:
    void order(TreeNode *root, int &accu) {
        if (!root) return;
        order(root->right, accu);
        root->val = (accu += root->val);
        order(root->left, accu);
    }
};
