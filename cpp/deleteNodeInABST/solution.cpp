// https://leetcode.com/problems/delete-node-in-a-bst/

#include <iostream>
#include <vector>

#include "TreeNode.h"
#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	TreeNode* deleteNode(TreeNode* root, int val)
	{
		return rec(root, val);
	}

private:
	TreeNode* rec(TreeNode* root, int val)
	{
		if (!root)
			return root;

		if (val == root->val) {
			auto* left = root->left;
			auto* right = root->right;
			delete root;
			root = insert(left, right);
		} else if (val < root->val) {
			root->left = rec(root->left, val);
		} else {
			root->right = rec(root->right, val);
		}

		return root;
	}

	TreeNode* insert(TreeNode* root, TreeNode* node)
	{
		if (!root)
			return node;
		if (!node)
			return root;

		if (node->val < root->val)
			root->left = insert(root->left, node);
		else if (node->val > root->val)
			root->right = insert(root->right, node);

		return root;
	}
};

int main(int argc, char** argv)
{
}
