// https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/

#include "function.h"

static int *iter_one_stack(struct TreeNode *root, int *return_size)
{
	// TODO
}

// using two stacks
static int *postorderTraversal_iter(struct TreeNode *root, int *return_size)
{
	*return_size = get_tree_size(root);
	int *postorder = malloc(sizeof *postorder * *return_size);

	if (*return_size) {
		struct TreeNode *stack_1[*return_size];
		struct TreeNode *stack_2[*return_size];
		int top_1 = -1;
		int top_2 = -1;
		stack_1[++top_1] = root;
		while (top_1 != -1) {
			struct TreeNode *current = stack_1[top_1--];
			if (current->left)
				stack_1[++top_1] = current->left;
			if (current->right)
				stack_1[++top_1] = current->right;
			stack_2[++top_2] = current;
		}
		int index = 0;
		while (top_2 != -1)
			*(postorder + index++) = stack_2[top_2--]->val;
	}
	
	return postorder;
}

static void postorderTraversal_rec(struct TreeNode *root, int **postorder)
{
	if (!root)
		return;
	if (root->left)
		postorderTraversal_rec(root->left, postorder);
	if (root->right)
		postorderTraversal_rec(root->right, postorder);
	*(*postorder)++ = root->val;
}

int *postorderTraversal(struct TreeNode *root, int *return_size)
{
	*return_size = get_tree_size(root);
	int *postorder = malloc(sizeof *postorder * *return_size);
	int *ret = postorder;
	postorderTraversal_rec(root, &postorder);
	
	return ret;
}
