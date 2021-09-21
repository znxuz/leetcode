#include <stdio.h>
#include "solution.h"
#include "../include/array.h"

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
	int size;
	int *preorder = preorderTraversal(root, &size);

	print_arr(preorder, size);
}
