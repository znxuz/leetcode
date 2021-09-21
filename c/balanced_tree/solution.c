// https://leetcode.com/problems/balanced-binary-tree/

#include "solution.h"

static int max(int x, int y)
{
	return x > y ? x : y;
}

// so proud i figured this out with just a little hint, which is the height ptr
static bool is_balanced(struct TreeNode *root, int *height)
{
	*height = 0;
	if (!root)
		return true;
	bool balanced = is_balanced(root->left, height);
	int lh = *height;
	balanced = balanced && is_balanced(root->right, height);
	int rh = *height;
	if (abs(lh - rh) > 1)
		balanced = false;
	*height = max(lh, rh) + 1;

	return balanced;
}

bool isBalanced(struct TreeNode *root)
{
	return is_balanced(root, (int[]){0});
}
