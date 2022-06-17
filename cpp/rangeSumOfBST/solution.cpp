// https://leetcode.com/problems/range-sum-of-bst/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
	return inorder(root, low, high);
    }

private:
    // time: O(n)
    // space: O(h)
    int inorder(const TreeNode* root, int lo, int hi)
    {
	if (!root)
	    return 0;

	// return inorder(root->left, lo, hi) + inorder(root->right, lo, hi)
	    // + (root->val >= lo && root->val <= hi ? root->val : 0);

	if (root->val > hi)
	    return inorder(root->left, lo, hi);
	if (root->val < lo)
	    return inorder(root->right, lo, hi);
	return inorder(root->left, lo, hi) + inorder(root->right, lo, hi)
	    + root->val;
    }
};

int main(int argc, char** argv)
{
}
