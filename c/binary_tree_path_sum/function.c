// https://leetcode.com/problems/path-sum/

#include "function.h"

static bool has_path_sum_rec(struct TreeNode *root,
										int target_sum, int current_sum)
{
	if (!root)
		return false;
	if (!root->left && !root->right)
		return root->val + current_sum == target_sum;
	return has_path_sum_rec(root->left, target_sum, current_sum + root->val)
		|| has_path_sum_rec(root->right, target_sum, current_sum + root->val);
}

bool hasPathSum(struct TreeNode *root, int target_sum)
{
	return has_path_sum_rec(root, target_sum, 0);
}
