/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (58.23%)
 * Total Accepted:    73.6K
 * Total Submissions: 126.3K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 * 
 * Example 1:
 * 
 * Input:
 * ?   3
 * ?  / \
 * ? 9  20
 * ?   /  \
 * ?  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 * 
 * 
 * 
 * Note:
 * 
 * The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int cnt = queue.size();
            double sum = 0;
            for (int i = 0; i < cnt; ++i) {
                sum += queue.front()->val;
                if (queue.front()->left) queue.push(queue.front()->left);
                if (queue.front()->right) queue.push(queue.front()->right);
                queue.pop();
            }
            ans.push_back(sum / cnt);
        }
        return ans;
    }
};
