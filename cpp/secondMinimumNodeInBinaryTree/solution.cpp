// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	int findSecondMinimumValue(TreeNode* root)
	{
	    return rec(root);
	}

    private:
	int rec(const TreeNode* root)
	{
	    if (!root || (!root->left && !root->right))
		return -1;

	    if (root->val != root->left->val) {
		int branch = rec(root->right);
		return (branch != -1 ? std::min(branch, root->left->val) : root->left->val);
	    }
	    if (root->val != root->right->val) {
		int branch = rec(root->left);
		return (branch != -1 ? std::min(branch, root->right->val) : root->right->val);
	    }

	    int left = rec(root->left);
	    int right = rec(root->right);
	    if (left == -1 || right == -1)
		return (left == -1 ? right : left);
	    return std::min(left, right);
	}
};

int main(int argc, char** argv)
{
}
