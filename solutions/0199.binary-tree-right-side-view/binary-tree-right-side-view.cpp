/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (47.00%)
 * Total Accepted:    157.4K
 * Total Submissions: 334.3K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 *
 * Example:
 *
 *
 * Input:?[1,2,3,null,5,null,4]
 * Output:?[1, 3, 4]
 * Explanation:
 *
 * ?  1            <---
 * ?/   \
 * 2     3         <---
 * ?\     \
 * ? 5     4       <---
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (!root) return ans;
        
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int sz = queue.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode *front = queue.front();
                if (front->left) queue.push(front->left);
                if (front->right) queue.push(front->right);
                if (i == sz - 1) ans.push_back(front->val);
                queue.pop();
            }
        }
        return ans;
    }
};
