#include <stdlib.h>
#include "../include/binary_tree.h"
#include "../include/array.h"

int *inorderTraversal(struct TreeNode *root, int *returnSize);
void inorderTraversal_rec(struct TreeNode *root, int *ret, int *index);
