/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (75.34%)
 * Total Accepted:    75.1K
 * Total Submissions: 99.6K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 
 * Given an integer array with no duplicates. A maximum tree building on this
 * array is defined as follow:
 * 
 * The root is the maximum number in the array. 
 * The left subtree is the maximum tree constructed from left part subarray
 * divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray
 * divided by the maximum number. 
 * 
 * 
 * 
 * 
 * Construct the maximum tree by the given array and output the root node of
 * this tree.
 * 
 * 
 * Example 1:
 * 
 * Input: [3,2,1,6,0,5]
 * Output: return the tree root node representing the following tree:
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 
 * Note:
 * 
 * The size of the given array will be in the range [1,1000].
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
#include <vector>

using namespace std;

class Solution {
  public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1);
    }

  private:
    TreeNode *build(vector<int> &nums, int s, int e) {
        if (s > e) return nullptr;
        auto pair = getmax(nums, s, e);
        TreeNode *root = new TreeNode(pair.second);
        root->left = build(nums, s, pair.first - 1);
        root->right = build(nums, pair.first + 1, e);
        return root;
    }

    pair<int, int> getmax(vector<int> &nums, int s, int e) {
        int max, pos;
        for (pos = s, max = nums[s]; s <= e; ++s)
            if (nums[s] > max) {
                pos = s;
                max = nums[s];
            }
        return {pos, max};
    }
};
