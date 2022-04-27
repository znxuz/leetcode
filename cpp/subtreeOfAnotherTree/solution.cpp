// https://leetcode.com/problems/subtree-of-another-tree/

#include <iostream>
#include <vector>

#include "TreeNode.h"
#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool isSubtree(TreeNode* root, TreeNode* sub)
	{
		return rec(root, sub);
	}

private:
	// time: O(n^2)
	// space: O(n^2)
	bool rec(const TreeNode* root, const TreeNode* sub)
	{
		if (!root)
			return false;
		return check_tree(root, sub) || rec(root->left, sub) || rec(root->right, sub);
	}

	bool check_tree(const TreeNode* root, const TreeNode* sub)
	{
		if (!root && !sub)
			return true;
		if (!root || !sub)
			return false;
		return (root->val == sub->val &&
				check_tree(root->left, sub->left) && check_tree(root->right, sub->right));
	}
};

int main(int argc, char** argv)
{
}
