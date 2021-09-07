#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *get_node(int val);
int get_tree_size(struct TreeNode *root);
void insert_node(struct TreeNode **root, struct TreeNode *node);

#endif
