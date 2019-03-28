/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (41.75%)
 * Total Accepted:    176.4K
 * Total Submissions: 422.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * 
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * Note:?A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * ?   1
 * ?  / \
 * ? 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 * 
 * Example 2:
 * 
 * 
 * Input: [4,9,0,5,1]
 * ?   4
 * ?  / \
 * ? 9   0
 * / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
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

// using the result of 257--binary tree paths
// class Solution_1 {
//   public:
//     int sumNumbers(TreeNode *root) {
//         vector<string> nums = binaryTreePaths(root);
//         int ans = 0;
//         for (const auto &num : nums) ans += atoi(num.c_str());
//         return ans;
//     }

//   private:
//     vector<string> binaryTreePaths(TreeNode *root) {
//         if (root == nullptr) return {};
//         if (root->left == nullptr && root->right == nullptr) return {to_string(root->val)};
//         vector<string> path_left = binaryTreePaths(root->left),
//                        path_right = binaryTreePaths(root->right),
//                        ans;
//         for (auto &path : path_left) ans.push_back(to_string(root->val) + path);
//         for (auto &path : path_right) ans.push_back(to_string(root->val) + path);
//         return ans;
//     }
// };

class Solution {
  public:
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode *root, int sum) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return sum * 10 + root->val;
        return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);
    }
};

