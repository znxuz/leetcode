// https://leetcode.com/problems/validate-binary-search-tree/

#include <algorithm>
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
	bool isValidBST(TreeNode* root)
	{
		return rec(root);
	}

private:
	const TreeNode* prev = nullptr;
	bool rec(const TreeNode* root)
	{
		if (!root)
			return true;
		if (!rec(root->left))
			return false;
		if (prev && root->val <= prev->val)
			return false;
		prev = root;
		return rec(root->right);
	}

	bool iter(const TreeNode* root)
	{
		std::stack<const TreeNode*> stk;
		stk.push(root);
		const TreeNode* prev = nullptr;
		while (!stk.empty()) {
			auto* node = stk.top();
			stk.pop();
			if (!node)
				continue;
			if (stk.empty() || stk.top() != node->right) {
				stk.push(node->right);
				stk.push(node);
				stk.push(node->left);
			} else if (prev && node->val <= prev->val) {
				return false;
			} else {
				prev = node;
			}
		}
		return true;
	}
};

int main(int argc, char** argv)
{
	TreeNode* root = new TreeNode(1, new TreeNode(1), nullptr);
	std::cout << Solution().isValidBST(root) << '\n';
}
