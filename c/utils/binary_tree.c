#include "../include/binary_tree.h"

struct TreeNode *get_node(int val)
{
	struct TreeNode *node = malloc(sizeof *node);
	node->val = val;
	node->left = node->right = NULL;
	return node;
}

int get_tree_size(struct TreeNode *root)
{
	if (!root)
		return 0;

	int count = 1;
	if (root->left)
		count += get_tree_size(root->left);
	if (root->right)
		count += get_tree_size(root->right);
	return count;
}

void insert_node(struct TreeNode **root, struct TreeNode *node)
{
	if (!*root) {
		*root = node;
	} else if (node->val < (*root)->val) {
		if (!(*root)->left)
			(*root)->left = node;
		else
			insert_node(&(*root)->left, node);
	} else {
		if (!(*root)->right)
			(*root)->right = node;
		else
			insert_node(&(*root)->right, node);
	}
}
