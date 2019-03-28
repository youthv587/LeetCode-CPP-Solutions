/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (40.87%)
 * Total Accepted:    203K
 * Total Submissions: 496.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ? [3],
 * ? [20,9],
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
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        bool isodd = true;
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
            if (!isodd) reverse(tmp.begin(), tmp.end());
            isodd = !isodd;
            ans.push_back(tmp);
        }
        return ans;
    }
};

