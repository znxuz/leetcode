#include "function.h"
#include <stdio.h>
#include "../binary_tree_inorder/function.c"
#include "../utils/binary_tree.h"
#include "../utils/array.h"

int main(void)
{
	int arr[] = {1, 3, 5, 7, 9, 11};
	int arr_size = sizeof arr / sizeof *arr;
	struct TreeNode *root = sortedArrayToBST(arr, arr_size);

	printf("arr size: %d\n", arr_size);
	printf("tree size: %d\n", get_tree_size(root));
	int *inorder = inorderTraversal(root, &arr_size);
	print_arr(inorder, arr_size);
}
