// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int get_tree_size(struct TreeNode *root)
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

//	while (current && !empty(stack)) {
//		if (current) {
//			stack.push(current);
//			current = current->left;
//		} else {
//			current = stack.pop();
//			printf(current->val);
//			current = current->right;
//		}
//	}
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

void inorderTraversal_rec(struct TreeNode *root, int *ret, int *index)
{
	if (root->left)
		inorderTraversal_rec(root->left, ret, index);
	*(ret + (*index)++) = root->val;
	if (root->right)
		inorderTraversal_rec(root->right, ret, index);
}

#include <stdio.h>

struct TreeNode *create_node(int val)
{
	struct TreeNode *node = malloc(sizeof *node);
	node->val = val;
	node->left = node->right = NULL;
	return node;
}

static struct TreeNode *get_simple_tree()
{
	struct TreeNode *root = create_node(1);
	struct TreeNode *ret = root;

	root->left = create_node(2);
	root->right = create_node(3);
	root = root->left;
	root->left = create_node(4);
	root->right = create_node(5);
	root = ret->right;
	root->left = create_node(6);
	root->right = create_node(7);

	return ret;
}

static void print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", *(arr + i));
	puts("");
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
