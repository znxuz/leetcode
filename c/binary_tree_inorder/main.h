#include <stdlib.h>
#include "../utils/binary_tree.h"

int *inorderTraversal(struct TreeNode *root, int *returnSize);
void inorderTraversal_rec(struct TreeNode *root, int *ret, int *index);
