// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
	TreeNode* insertIntoBST(TreeNode* root, int val)
	{
		return iter_double_ptr(root, val);
	}

private:
	TreeNode* iter_double_ptr(TreeNode* root, int val)
	{
		TreeNode** ptr = &root;
		while (*ptr)
			ptr = &(val < (*ptr)->val ? (*ptr)->left : (*ptr)->right);
		*ptr = new TreeNode(val);

		return root;
	}

	// time: O(n * log(n))
	// space: O(1)
	TreeNode* iter(TreeNode* root, int val)
	{
		if (!root)
			return new TreeNode(val);

		TreeNode* pred = nullptr;
		for (auto* node = root; node; std::exchange(node, (val < node->val ? node->left : node->right)))
			pred = node;

		TreeNode* new_node = new TreeNode(val);
		if (val < pred->val)
			pred->left = new_node;
		else
			pred->right = new_node;

		return root;
	}

	// time: O(n * log(n))
	// space: O(H)
	TreeNode* rec(TreeNode* root, int val)
	{
		if (!root)
			return new TreeNode(val);

		if (root->val < val)
			root->right = rec(root->right, val);
		else if (root->val > val)
			root->left = rec(root->left, val);
		return root;
	}
};

int main(int argc, char** argv)
{
}
