#include "solution.h"
#include <stdio.h>

static struct TreeNode *get_simple_tree()
{
	struct TreeNode *root = get_node(1);
	struct TreeNode *ret = root;

	root->left = get_node(2);
	root->right = get_node(3);
	root = root->left;
	root->left = get_node(4);
	root->right = get_node(5);
	root = ret->right;
	root->left = get_node(6);
	root->right = get_node(7);

	return ret;
}

static void iter_test(struct TreeNode *root)
{
	int ret_size;
	int *ret = inorderTraversal(root, &ret_size);
	print_arr(ret, ret_size);
}

static void rec_test(struct TreeNode *root)
{
	int ret_size = get_tree_size(root);
	int *ret = malloc(sizeof *ret * ret_size);
	int index = 0;
	inorderTraversal_rec(root, ret, &index);
	print_arr(ret, ret_size);
}

int main(void)
{
	struct TreeNode *root = get_simple_tree();
	iter_test(root);
	rec_test(root);
}
