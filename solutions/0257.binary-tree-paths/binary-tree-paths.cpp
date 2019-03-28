/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (45.31%)
 * Total Accepted:    215.3K
 * Total Submissions: 475.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note:?A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ?  1
 * ?/   \
 * 2     3
 * ?\
 * ? 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return {to_string(root->val)};
        vector<string> path_left = binaryTreePaths(root->left),
                       path_right = binaryTreePaths(root->right),
                       ans;
        for (auto &path : path_left) ans.push_back(to_string(root->val) + "->" + path);
        for (auto &path : path_right) ans.push_back(to_string(root->val) + "->" + path);
        return ans;
    }
};
