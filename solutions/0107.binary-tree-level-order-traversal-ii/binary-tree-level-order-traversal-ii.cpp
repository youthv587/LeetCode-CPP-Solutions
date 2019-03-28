/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (45.98%)
 * Total Accepted:    214.5K
 * Total Submissions: 466.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 * 
 * [
 * ? [15,7],
 * ? [9,20],
 * ? [3]
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
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
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
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

