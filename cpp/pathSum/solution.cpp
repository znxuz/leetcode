// https://leetcode.com/problems/path-sum/

#include <stack>
#include <iostream>
#include <iterator>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		bool hasPathSum(TreeNode* root, int target)
		{
			return iter(root, target);
		}

		bool rec(TreeNode* root, int prev_sum, int target)
		{
			if (!root)
				return false;

			prev_sum += root->val;
			if (!root->left && !root->right)
				return prev_sum == target;
			return rec(root->left, prev_sum, target) || rec(root->right, prev_sum, target);
		}

		bool iter(TreeNode* root, int target)
		{
			stack<int> vals;
			stack<TreeNode*> stk;
			stk.push(root);
			vals.push(0);
			while (!stk.empty()) {
				auto* node = stk.top();
				stk.pop();
				int val = vals.top();
				vals.pop();
				if (!node || (!stk.empty() && stk.top() == node->right))
					continue;
				val += node->val;
				if (!node->left && !node->right && val == target)
					return true;
				stk.push(node->right);
				vals.push(val);
				stk.push(node);
				vals.push(val);
				stk.push(node->left);
				vals.push(val);
			}

			return false;
		}
};

int main(int argc, char** argv)
{
}
