// https://leetcode.com/problems/increasing-order-search-tree/

#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	TreeNode* increasingBST(TreeNode* root)
	{
		return iter(root);
	}

private:
	TreeNode* iter(TreeNode* root)
	{
		std::stack<TreeNode*> stk;
		stk.push(root);
		TreeNode* new_root = nullptr;
		TreeNode* it = nullptr;
		while (!stk.empty()) {
			auto* node = stk.top();
			stk.pop();

			if (!node)
				continue;
			if (stk.empty() || stk.top() != node->right) {
				stk.push(node->right);
				stk.push(node);
				stk.push(node->left);
			} else if (!it) {
				it = new_root = node;
			} else {
				it->left = nullptr;
				it->right = node;
				it = node;
			}
		}
		it->left = nullptr;

		return new_root;
	}

	TreeNode* rec(TreeNode* root)
	{
		TreeNode* new_root = nullptr;
		TreeNode* it = nullptr;
		inorder(root, &new_root, &it);
		it->left = nullptr; // damn son

		return new_root;
	}

	void inorder(TreeNode* root, TreeNode** new_root, TreeNode** it)
	{
		if (!root)
			return;

		inorder(root->left, new_root, it);
		if (!*it) {
			*it = *new_root = root;
		} else {
			(*it)->left = nullptr;
			(*it)->right = root;
			*it = root;
		}
		inorder(root->right, new_root, it);
	}
};

int main(int argc, char** argv)
{
}
