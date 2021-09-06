#include <stdio.h>
#include "function.h"

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
