/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
	int
		left_depth = maxDepth(root->left),
		right_depth = maxDepth(root->right);
	return (left_depth > right_depth)? left_depth + 1 : right_depth + 1;
}