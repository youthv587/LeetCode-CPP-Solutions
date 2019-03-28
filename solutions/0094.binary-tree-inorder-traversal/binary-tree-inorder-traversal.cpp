/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (55.58%)
 * Total Accepted:    427.1K
 * Total Submissions: 768.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ?  1
 * ?   \
 * ?    2
 * ?   /
 * ?  3
 * 
 * Output: [1,3,2]
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
#include <queue>
#include <stack>

using namespace std;

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        stack<TreeNode *> stack;
        TreeNode *cur = root;
        while (cur != nullptr || !stack.empty()) {
            while (cur != nullptr) {
                stack.push(cur);
                cur = cur->left;
            }
            ans.push_back(stack.top()->val);
            cur = stack.top()->right;
            stack.pop();
        }
        return ans;
    }
};


