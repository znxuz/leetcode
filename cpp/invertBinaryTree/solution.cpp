// https://leetcode.com/problems/invert-binary-tree/

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
		TreeNode* invertTree(TreeNode* root)
		{
			iter(root);

			return root;
		}

		void iter(TreeNode* root)
		{
			stack<TreeNode*> stk;
			stk.push(root);
			while (!stk.empty()) {
				auto* node = stk.top();
				stk.pop();
				if (!node)
					continue;
				std::swap(node->left, node->right);
				stk.push(node->left);
				stk.push(node->right);
			}
		}

		void rec(TreeNode* root)
		{
			if (!root)
				return;
			rec(root->left);
			rec(root->right);
			std::swap(root->left, root->right);
		}

};

int main(int argc, char** argv)
{
}
