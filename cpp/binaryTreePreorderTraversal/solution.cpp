// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
		// time: O(n)
		// space: O(n)
		vector<int> preorderTraversal(TreeNode* root)
		{
			vector<int> res;
			iter(res, root);

			return res;
		}

		void rec(vector<int>& res, TreeNode* root)
		{
			if (!root)
				return;

			res.push_back(root->val);
			rec(res, root->left);
			rec(res, root->right);
		}

		void iter(vector<int>& res, TreeNode* root)
		{
			stack<TreeNode*> st;
			st.push(root);

			while (!st.empty()) {
				auto* node = st.top();
				st.pop();
				if (!node)
					continue;
				res.push_back(node->val);
				st.push(node->right);
				st.push(node->left);
			}
		}
};

int main(int argc, char** argv)
{
}
