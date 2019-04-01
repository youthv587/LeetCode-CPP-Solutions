/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (50.39%)
 * Total Accepted:    209K
 * Total Submissions: 414.3K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.
 *
 * Example 1:
 *
 *
 * Input: root = [3,1,4,null,2], k = 1
 * ?  3
 * ? / \
 * ?1   4
 * ? \
 * 2
 * Output: 1
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * ?      5
 * ?     / \
 * ?    3   6
 * ?   / \
 * ?  2   4
 * ? /
 * ?1
 * Output: 3
 *
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
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
    int kthSmallest(TreeNode *root, int k) {
        std::vector<int> values;
        inorder(root, values, k);
        return values.back();
    }
    void inorder(TreeNode *root, std::vector<int> &values, int k) {
        if (root == nullptr) return;
        inorder(root->left, values, k);
        if (values.size() == k) return;
        values.push_back(root->val);
        inorder(root->right, values, k);
    }
};
