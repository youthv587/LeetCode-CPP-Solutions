/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (25.40%)
 * Total Accepted:    373.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ?   2
 * ?  / \
 * ? 1   3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ?   5
 * ?  / \
 * ? 1   4
 * / \
 * 3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's
 * value
 * is 5 but its right child's value is 4.
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
    bool isValidBST(TreeNode *root) {
        vector<int> values;
        inorder(root, values);
        for (int i = 1; i < values.size(); ++i)
            if (values[i] <= values[i - 1]) return false;
        return true;
    }

    void inorder(TreeNode *root, vector<int> &values) {
        if (root == nullptr) return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
};

