// https://leetcode.com/problems/symmetric-tree/

#include <stack>
#include <iostream>
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
		bool isSymmetric(TreeNode* root)
		{
			return iter(root);
		}

		bool rec(TreeNode* node1, TreeNode* node2)
		{
			if (!node1 && !node2)
				return true;
			if (!node1 || !node2 || node1->val != node2->val)
				return false;

			return rec(node1->left, node2->right) && rec(node1->right, node2->left);
		}

		bool iter(TreeNode* root)
		{
			stack<TreeNode*> stk;
			stk.push(root);
			stk.push(root);
			while (!stk.empty()) {
				auto* right = stk.top();
				stk.pop();
				auto* left = stk.top();
				stk.pop();
				if (!left && !right)
					continue;
				if (!left || !right || left->val != right->val)
					return false;
				stk.push(left->left);
				stk.push(right->right);
				stk.push(left->right);
				stk.push(right->left);
			}

			return true;
		}
};

int main(int argc, char** argv)
{
}
