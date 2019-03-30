/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (72.93%)
 * Total Accepted:    6.9K
 * Total Submissions: 9.5K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Return the root node of a binary search tree that matches the given preorder
 * traversal.
 *
 * (Recall that a binary search tree?is a binary tree where for every node, any
 * descendant of node.left has a value <?node.val, and any descendant of
 * node.right has a value >?node.val.? Also recall that a preorder traversal
 * displays the value of the?node first, then traverses node.left, then
 * traverses node.right.)
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 *
 *
 *
 *
 *
 * Note:?
 *
 *
 * 1 <= preorder.length <= 100
 * The values of preorder are distinct.
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
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        if (preorder.size() == 0) return nullptr;
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);

    }

  private:
    TreeNode *build(vector<int> preorder, vector<int> inorder, int ps, int pe, int is, int ie) {
        if (ps > pe) return nullptr;
        TreeNode *root = new TreeNode(preorder[ps]);
        int pos = is;
        while (pos <= ie)
            if (inorder[pos] == root->val) break;
            else ++pos;
        root->left =
            build(preorder, inorder, ps + 1, ps - is + pos, is, pos - 1);
        root->right =
            build(preorder, inorder, ps - is + pos + 1, pe, pos + 1, ie);
        return root;
    }
};
