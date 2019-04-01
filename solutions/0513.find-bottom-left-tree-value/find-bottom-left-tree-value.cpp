/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (58.06%)
 * Total Accepted:    67.7K
 * Total Submissions: 116.5K
 * Testcase Example:  '[2,1,3]'
 *
 * 
 * Given a binary tree, find the leftmost value in the last row of the tree. 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * ?   2
 * ?  / \
 * ? 1   3
 * 
 * Output:
 * 1
 * 
 * 
 * 
 * ? Example 2: 
 * 
 * Input:
 * 
 * ?       1
 * ?      / \
 * ?     2   3
 * ?    /   / \
 * ?   4   5   6
 * ?      /
 * ?     7
 * 
 * Output:
 * 7
 * 
 * 
 * 
 * Note:
 * You may assume the tree (i.e., the given root node) is not NULL.
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

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode *> queue;
        int res;
        queue.push(root);
        while (!queue.empty()) {
            int sz = queue.size();
            res = queue.front()->val;
            for (int i = 0; i < sz; ++i) {
                TreeNode *front = queue.front();
                if (front->left != nullptr) queue.push(front->left);
                if (front->right != nullptr) queue.push(front->right);
                queue.pop();
            }
        }
        return res;
    }
};

