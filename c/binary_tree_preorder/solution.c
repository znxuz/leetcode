// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include "solution.h"

// using a stack, save the current, and pop&store the value right away
// then add right and left
// rinse and repeat
static int *preorderTraversal_iter(struct TreeNode *root, int *return_size)
{
	*return_size = get_tree_size(root);
	int *preorder = malloc(sizeof *preorder * *return_size);
	if (*return_size) {
		struct TreeNode *stack[get_tree_size(root)];
		int index = 0;
		int top = -1;
		stack[++top] = root;
		while (top != -1) {
			struct TreeNode *current = stack[top--];
			*(preorder + index++) = current->val;
			if (current->right)
				stack[++top] = current->right;
			if (current->left)
				stack[++top] = current->left;
		}
	}

	return preorder;
}

static void preorderTraversal_rec(struct TreeNode *root, int **preorder)
{
	if (!root)
		return;
	*(*preorder)++ = root->val;
	preorderTraversal_rec(root->left, preorder);
	preorderTraversal_rec(root->right, preorder);
}

int *preorderTraversal(struct TreeNode *root, int *return_size)
{
	*return_size = get_tree_size(root);
	int *preorder = malloc(sizeof *preorder * *return_size);
	int *ret = preorder;
	preorderTraversal_rec(root, &preorder);

	return ret;
}
