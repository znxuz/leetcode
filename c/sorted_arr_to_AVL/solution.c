// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include "function.h"

// struct TreeNode *get_node(int val)
// {
	// struct TreeNode *node = malloc(sizeof *node);
	// node->val = val;
	// node->left = node->right = NULL;
	// return node;
// }

static struct TreeNode *to_AVL_rec(int *nums, int l, int r)
{
	int mid = l + (r - l) / 2;
	struct TreeNode *root = get_node(*(nums + mid));

	if (l < mid)
		root->left = to_AVL_rec(nums, l, mid - 1);
	if (r > mid)
		root->right = to_AVL_rec(nums, mid + 1, r);

	return root;
}

struct TreeNode *sortedArrayToBST(int *nums, int nums_size)
{
	if (!nums || !nums_size)
		return 0;
	return to_AVL_rec(nums, 0, nums_size - 1);
}
