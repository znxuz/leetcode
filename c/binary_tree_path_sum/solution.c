#include "function.c"

// removed unnesessary argument current sum
static bool has_path_sum_rec_solution(struct TreeNode *root, int target_sum)
{
	if (!root)
		return false;
	if (!root->left && !root->right)
		return target_sum - root->val == 0;
	return has_path_sum_rec_solution(root->left, target_sum - root->val)
		|| has_path_sum_rec_solution(root->right, target_sum - root->val);
}
