// https://leetcode.com/problems/minimum-depth-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include "solution.h"

static int min(int x, int y)
{
	return x < y ? x : y;
}

int minDepth(struct TreeNode *root)
{
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;
	if (!root->left)
		return 1 + minDepth(root->right);
	if (!root->right)
		return 1 + minDepth(root->left);
	return 1 + min(minDepth(root->left), minDepth(root->right));
}
