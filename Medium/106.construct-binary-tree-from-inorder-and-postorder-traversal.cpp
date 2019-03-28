/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (38.39%)
 * Total Accepted:    144.9K
 * Total Submissions: 377.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return build(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }

  private:
    TreeNode *build(vector<int> postorder, vector<int> inorder, int ps, int pe, int is, int ie) {
        if (ps > pe) return nullptr;
        TreeNode *root = new TreeNode(postorder[pe]);
        int pos = is;
        while (pos <= ie) {
            if (inorder[pos] == root->val) break;
            else ++pos;
        }
        root->left = build(postorder, inorder, ps, ps -is - 1 + pos, is, pos - 1);
        root->right = build(postorder, inorder, pe - ie + pos, pe - 1, pos + 1, ie);
        return root;
    }
};

