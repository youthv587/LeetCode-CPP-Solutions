/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (39.94%)
 * Total Accepted:    167.9K
 * Total Submissions: 420.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted linked list: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ?     0
 * ?    / \
 * ?  -3   9
 * ?  /   /
 * ?-10  5
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr) return nullptr;

        std::vector<int> values;
        for (ListNode *p = head; p != nullptr; p = p->next) values.push_back(p->val);
        return build(values, 0, values.size() - 1);
    }

  private:
    TreeNode *build(std::vector<int> &nums, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, start, mid - 1);
        root->right = build(nums, mid + 1, end);
        return root;
    }
};

