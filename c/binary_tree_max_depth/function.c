// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include "function.h"

static int max(int x, int y)
{
	return x > y ? x : y;
}

int max_depth_rec(struct TreeNode *root)
{
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;
	return max(max_depth_rec(root->left) + 1, max_depth_rec(root->right) + 1);
}

int maxDepth(struct TreeNode *root)
{
	return max_depth_rec(root);
}
