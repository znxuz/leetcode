// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		return iter(root, p, q);
	}

	TreeNode* iter(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		while (root) {
			if (root->val < p->val && root->val < q->val)
				std::exchange(root, root->right);
			else if (root->val > q->val && root->val > p->val)
				std::exchange(root, root->left);
			else
				return root;
		}

		return root;
	}

	TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (!root)
			return root;
		if (root->val < p->val && root->val < q->val)
			return lowestCommonAncestor(root->right, p, q);
		else if (root->val > p->val && root->val > q->val)
			return lowestCommonAncestor(root->left, p, q);

		return root;
	}
};

int main(int argc, char** argv)
{
}
