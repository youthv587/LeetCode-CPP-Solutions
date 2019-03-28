/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (52.09%)
 * Total Accepted:    79.7K
 * Total Submissions: 153K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ?   5
 * ?  / \
 * ? 3   6
 * ?/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ?   5
 * ?  / \
 * ? 3   6
 * ?/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * Output: False
 * 
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
#include <vector>

class Solution {
  public:
    bool findTarget(TreeNode *root, int k) {
        if (root == nullptr) return false;
        std::vector<int> values;
        inOrderTraversal(root, values);
        std::vector<int>::iterator left = values.begin(), right = values.end()-1;
        while (left < right) {
            if (*left + *right == k) return true;
            else if (*left + *right > k) --right;
            else ++left;
        }
        return false;
    }

    void inOrderTraversal(TreeNode *root, std::vector<int> &values) {
        if (root == nullptr) return;
        inOrderTraversal(root->left, values);
        values.push_back(root->val);
        inOrderTraversal(root->right, values);
    }
};

