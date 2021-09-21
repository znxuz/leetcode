#include <stdbool.h>
#include "../include/binary_tree.h"

static bool check_symmetric_rec(struct TreeNode *left, struct TreeNode *right)
{
	if (!left && !right)
		return true;
	if (!left || !right)
		return false;

	return (left->val == right->val)
		&& check_symmetric_rec(left->left, right->right)
		&& check_symmetric_rec(left->right, right->left);
}

bool isSymmetric_solution(struct TreeNode* root)
{
	if (!root)
		return false;
	return check_symmetric_rec(root->left, root->right);
}
