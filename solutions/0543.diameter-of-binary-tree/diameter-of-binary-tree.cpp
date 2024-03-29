/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (46.46%)
 * Total Accepted:    123.1K
 * Total Submissions: 264.9K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 *
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 *
 *
 *
 * Example:
 * Given a binary tree
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \
 * ⁠     4   5
 *
 *
 *
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
 *
 */

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode *root, int &res)
    {
        if (!root) return 0;
        int left = dfs(root->left, res), right = dfs(root->right, res);
        res = (left + right > res) ? left + right : res;
        return 1 + (left > right ? left : right);
    }
};
