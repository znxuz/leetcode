// https://leetcode.com/problems/symmetric-tree/

#include <stdbool.h>
#include <stdlib.h>
#include "../utils/binary_tree.h"

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

#include <stdio.h>

static struct TreeNode *get_simple_tree()
{
	struct TreeNode *root = get_node(1);
	struct TreeNode *ret = root;

	root->left = get_node(2);
	root->right = get_node(2);
	root = root->left;
	root->left = get_node(3);
	root = ret->right;
	root->left = get_node(3);

	return ret;
}

static void print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", *(arr + i));
	puts("");
}


int main(void)
{
	struct TreeNode *root = get_simple_tree();
	int tree_size, *inorder = inorderTraversal(root, &tree_size);
	print_arr(inorder, tree_size);
	printf("%s\n", isSymmetric(root) ? "true" : "false");
}
