// https://leetcode.com/problems/same-tree/

#include <stdbool.h>
#include <stdlib.h>
#include "../utils/binary_tree.h"

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (!p && !q)
		return true;
	if ((!p && q) || (p && !q))
		return false;
	if (p->val != q ->val)
		return false;
	if (p->left || p->right || q->left || q->right)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

	return true;
}
