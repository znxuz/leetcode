// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
	int kthSmallest(TreeNode* root, int k)
	{
		return iter(root, k);
	}

private:
	int iter(const TreeNode* root, int k)
	{
		std::stack<const TreeNode*> stk;

		stk.push(root);
		while (!stk.empty()) {
			auto* node = stk.top();
			stk.pop();
			if (!node)
				continue;
			if (stk.empty() || stk.top() != node->right) {
				stk.push(node->right);
				stk.push(node);
				stk.push(node->left);
			} else if (--k == 0) {
				return node->val;
			}
		}

		return -1;
	}

	int rec(const TreeNode* root, int* k)
	{
		if (!root)
			return -1;

		int left = rec(root->left, k);
		if (left != -1)
			return left;
		if (--*k == 0)
			return root->val;
		return rec(root->right, k);
	}
};

int main(int argc, char** argv)
{
}
