// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
	void flatten(TreeNode* root)
	{
		iter(root);
	}

private:
	void iter(TreeNode* root)
	{
		std::stack<TreeNode*> stk;
		stk.push(root);
		TreeNode* iter = nullptr;
		while (!stk.empty()) {
			auto* node = stk.top();
			stk.pop();
			if (!node)
				continue;
			stk.push(node->right);
			stk.push(node->left);
			if (iter) {
				iter->right = node;
				iter->left = nullptr;
			}
			iter = node;
		}
	}

	// time: O(n)
	// space: O(n)
	void iter_extra_space(TreeNode* root)
	{
		std::vector<TreeNode*> preorder;
		std::stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) {
			auto* node = stk.top();
			stk.pop();
			if (!node)
				continue;
			preorder.push_back(node);
			stk.push(node->right);
			stk.push(node->left);
		}

		auto* iter = root;
		for (auto* node : preorder) {
			if (iter == node)
				continue;
			iter->left = nullptr;
			iter = iter->right = node;
		}
	}
};

int main(int argc, char** argv)
{
}
