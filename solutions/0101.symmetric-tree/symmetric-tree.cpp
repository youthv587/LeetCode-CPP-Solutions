/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (42.97%)
 * Total Accepted:    373.5K
 * Total Submissions: 869.3K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ?   1
 * ?  / \
 * ? 2   2
 * ?/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ?   1
 * ?  / \
 * ? 2   2
 * ?  \   \
 * ?  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *tree1, TreeNode *tree2) {
        if (tree1 == nullptr || tree2 == nullptr) return tree1 == tree2;
        return tree1->val == tree2->val &&
               isMirror(tree1->left, tree2->right) &&
               isMirror(tree1->right, tree2->left);
    }
};

