#include <stdio.h>

#include "solution.h"

static struct TreeNode *get_tree(void)
{
	struct TreeNode *root = get_node(10);
	insert_node(&root, get_node(20));
	insert_node(&root, get_node(5));

	insert_node(&root, get_node(2));
	insert_node(&root, get_node(7));

	insert_node(&root, get_node(15));
	insert_node(&root, get_node(25));

	return root;
}

static void print_tree_inorder(struct TreeNode *root)
{

	int inorder_size, *inorder_arr = inorderTraversal(root, &inorder_size);
	print_arr(inorder_arr, inorder_size);
}

int main(void)
{
	struct TreeNode *root = get_tree();
	print_tree_inorder(root);

	printf("max depth: %d\n", maxDepth(root));
}
