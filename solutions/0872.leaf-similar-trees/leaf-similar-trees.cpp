/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (62.52%)
 * Total Accepted:    37.8K
 * Total Submissions: 60.5K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree.? From?left to right order, the
 * values of those?leaves form a leaf value sequence.
 * 
 * 
 * 
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 * 
 * Two binary trees are considered leaf-similar?if their leaf value sequence is
 * the same.
 * 
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Both of the given trees will have between 1 and 100 nodes.
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
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        std::vector<int> leaves1, leaves2;
        preorder(root1, leaves1);
        preorder(root2, leaves2);
        return leaves1 == leaves2;
    }

    void preorder(TreeNode *root, std::vector<int> &values) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr)
            values.push_back(root->val);
        preorder(root->left, values);
        preorder(root->right, values);
    }
};
