/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 *
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (50.01%)
 * Total Accepted:    29K
 * Total Submissions: 58.1K
 * Testcase Example:  '[4,2,6,1,3,null,null]'
 *
 * Given a Binary Search Tree (BST) with the root node root, return?the minimum
 * difference between the values of any two different nodes in the tree.
 *
 * Example :
 *
 *
 * Input: root = [4,2,6,1,3,null,null]
 * Output: 1
 * Explanation:
 * Note that root is a TreeNode object, not an array.
 *
 * The given tree [4,2,6,1,3,null,null] is represented by the following
 * diagram:
 *
 * ?         4
 * ?       /   \
 * ?     2      6
 * ?    / \
 * ?   1   3
 *
 * while the minimum difference in this tree is 1, it occurs between node 1 and
 * node 2, also between node 3 and node 2.
 *
 *
 * Note:
 *
 *
 * The size of the BST will be between 2 and?100.
 * The BST is always valid, each node's value is an integer, and each node's
 * value is different.
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

class Solution {
  public:
    int minDiffInBST(TreeNode *root) {
        std::vector<int> values;
        inorder(root, values);
        int res = INT_MAX;
        for (int i = 1; i < values.size(); ++i)
            res = std::abs(values[i] - values[i - 1]) > res
                      ? res
                      : std::abs(values[i] - values[i - 1]);
        return res;
    }

  private:
    void inorder(TreeNode *root, std::vector<int> &values) {
        if (root == nullptr) return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
};
