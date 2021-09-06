// https://leetcode.com/problems/symmetric-tree/

#include "function.h"

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

#include <stdio.h>

// Wrong, inorder traversal cannot detect asymmetrical trees like [1, 2, 2, 2, 2]
bool isSymmetric(struct TreeNode* root)
{
	int tree_size, *inorder = inorderTraversal(root, &tree_size);
	if (!inorder || tree_size % 2 == 0)
		return false;

	int mid = (tree_size - 1) / 2, left = mid - 1, right = mid + 1;
	while ((left >= 0 && right < tree_size) && (*(inorder + left) == *(inorder + right)))
		left--, right++;

	return left == -1 && right == tree_size;
}
