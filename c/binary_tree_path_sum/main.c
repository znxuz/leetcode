#include <stdio.h>
#include "solution.h"
#include "../include/array.h"
#include "../binary_tree_inorder/solution.c"

static struct TreeNode *get_simple_tree()
{
	struct TreeNode *root = get_node(1);
	struct TreeNode *ret = root;
	root->left = get_node(-2);
	root->left->left = get_node(1);
	root->left->right = get_node(3);
	root->left->left->left = get_node(-1);
	root->right = get_node(-3);
	root->right->left = get_node(-2);
	return ret;
}

int main(void)
{
	struct TreeNode *root = get_simple_tree();
	int arr_size, *arr = inorderTraversal(root, &arr_size);
	print_arr(arr, arr_size);

	printf("%s\n", hasPathSum(root, -1) ? "true" : "false");
}
