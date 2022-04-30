// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
	int sumNumbers(TreeNode* root)
	{
		return iter(root);
	}

private:
	int iter(const TreeNode* root)
	{
		std::stack<const TreeNode*> stk;
		stk.push(root);
		auto* iter = root;
		int sum = 0;
		int tmp = 0;
		while (!stk.empty() || iter) {
			if (iter) {
				if (iter->right)
					stk.push(iter->right);
				tmp = tmp * 10 + iter->val;
				stk.push(iter);
				iter = iter->left;
			} else {
				iter = stk.top();
				stk.pop();
				if (!stk.empty() && stk.top() == iter->right) {
					stk.pop();
					stk.push(iter);
					iter = iter->right;
				} else {
					if (!iter->left && !iter->right)
						sum += tmp;
					tmp /= 10;
					iter = nullptr;
				}
			}
		}

		return sum;
	}

	int rec(const TreeNode* root, int prev = 0)
	{
		if (!root)
			return 0;

		prev = prev * 10 + root->val;
		if (!root->left && !root->right)
			return prev;
		return rec(root->left, prev) + rec(root->right, prev);
	}

	void rec_extra_params(const TreeNode* root, int prev, int& sum)
	{
		if (!root)
			return;

		prev = prev * 10 + root->val;
		if (!root->left && !root->right)
			sum += prev;
		if (root->left)
			rec_extra_params(root->left, prev, sum);
		if (root->right)
			rec_extra_params(root->right, prev, sum);
	}
};

int main(int argc, char** argv)
{
}
