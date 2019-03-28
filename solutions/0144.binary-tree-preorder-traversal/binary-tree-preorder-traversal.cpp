/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (50.62%)
 * Total Accepted:    316.1K
 * Total Submissions: 624.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input:?[1,null,2,3]
 * ?  1
 * ?   \
 * ?    2
 * ?   /
 * ?  3
 * 
 * Output:?[1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        stack<TreeNode *> stack;
        TreeNode *tmp;
        stack.push(root);
        while (!stack.empty()) {
            tmp = stack.top();
            stack.pop();
            ans.push_back(tmp->val);
            if (tmp->right != nullptr) stack.push(tmp->right);
            if (tmp->left != nullptr) stack.push(tmp->left);
        }
        return ans;
    }
};

