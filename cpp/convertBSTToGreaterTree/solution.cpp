// https://leetcode.com/problems/convert-bst-to-greater-tree/

#include <stack>
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
	TreeNode* convertBST(TreeNode* root)
	{
		return iter(root);
	}

private:
	TreeNode* rec(TreeNode* root, int& sum)
	{
		if (!root)
			return root;

		rec(root->right, sum);
		sum += (root->val = sum);
		rec(root->left, sum);
		return root;
	}

	TreeNode* iter(TreeNode* root)
	{
		std::stack<TreeNode*> stk;
		stk.push(root);
		int sum = 0;
		while (!stk.empty()) {
			auto* node = stk.top();
			stk.pop();
			if (!node)
				continue;
			if (stk.empty() || stk.top() != node->left) {
				stk.push(node->left);
				stk.push(node);
				stk.push(node->right);
			} else {
				sum += node->val;
				node->val = sum;
			}
		}

		return root;
	}
};

int main(int argc, char** argv)
{
}
