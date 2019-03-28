/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (47.51%)
 * Total Accepted:    350.1K
 * Total Submissions: 736.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ?   3
 * ?  / \
 * ? 9  20
 * ?   /  \
 * ?  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ? [3],
 * ? [9,20],
 * ? [15,7]
 * ]
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
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int cnt = queue.size();
            vector<int> tmp;
            for (int i = 0; i < cnt; ++i) {
                tmp.push_back(queue.front()->val);
                if (queue.front()->left != nullptr) queue.push(queue.front()->left);
                if (queue.front()->right != nullptr) queue.push(queue.front()->right);
                queue.pop();
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

