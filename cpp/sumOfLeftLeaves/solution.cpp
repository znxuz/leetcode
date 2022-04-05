// https://leetcode.com/problems/sum-of-left-leaves/

#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int sumOfLeftLeaves(TreeNode* root)
	{
		return rec(root);
	}

private:
	int rec(const TreeNode* root)
	{
		if (!root)
			return 0;
		if (root->left && !root->left->left && !root->left->right)
			return root->left->val + rec(root->right);
		return rec(root->left) + rec(root->right);
	}

	int rec_default_arg(const TreeNode* root, bool is_left = false)
	{
		if (!root)
			return 0;
		if (!root->left && !root->right)
			return (is_left ? root->val : 0);
		return rec_default_arg(root->left, true) + rec_default_arg(root->right);
	}
};

int main(int argc, char** argv)
{
}
