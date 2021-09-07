#include <stdio.h>
#include "function.h"

static struct TreeNode *get_simple_tree()
{
	struct TreeNode *root = get_node(1);
	struct TreeNode *ret = root;
	root->left = get_node(2);
	root->right = get_node(2);

	root = root->left;
	root->left = get_node(2);
	root->right = get_node(2);

	root = root->left;
	root->left = get_node(2);
	root->right = get_node(2);

	return ret;
}

int main(void)
{
	struct TreeNode *root = get_simple_tree();
	printf("%s\n", isBalanced(root) ? "true" : "false");
}
