// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

#include "solution.h"

//	while (current && !empty(stack)) {
//		if (current) {
//			stack.push(current);
//			current = current->left;
//		} else {
//			current = stack.pop();
//			printf(current->val);
//			current = current->right;
//		}
//	}
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
	*returnSize = get_tree_size(root);
	if (!*returnSize)
		return 0;

	int *arr = malloc(sizeof *arr * *returnSize);
	int index = 0;

	struct TreeNode *stack[*returnSize];
	int top = -1;
	struct TreeNode *current = root;

	while (current || top != -1) {
		if (current) {
			stack[++top] = current;
			current = current->left;
		} else {
			current = stack[top--];
			*(arr + index++) = current->val;
			current = current->right;
		}
	}

	return arr;
}

void inorderTraversal_rec(struct TreeNode *root, int *ret, int *index)
{
	if (root->left)
		inorderTraversal_rec(root->left, ret, index);
	*(ret + (*index)++) = root->val;
	if (root->right)
		inorderTraversal_rec(root->right, ret, index);
}
