/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (57.39%)
 * Total Accepted:    60.4K
 * Total Submissions: 105.2K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 *
 * Example:
 *
 * Input:
 *
 * ?         1
 * ?        / \
 * ?       3   2
 * ?      / \   \
 * ?     5   3   9
 *
 * Output: [1, 3, 9]
 *
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
#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int sz = queue.size();
            res.push_back(INT_MIN);
            for (int i = 0; i < sz; ++i) {
                TreeNode *front = queue.front();
                res.back() = front->val > res.back() ? front->val : res.back();
                if (front->left) queue.push(front->left);
                if (front->right) queue.push(front->right);
                queue.pop();
            }
        }
        return res;
    }
};
