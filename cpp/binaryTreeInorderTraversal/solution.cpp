// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"
#include "ListNode.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(n)
		vector<int> inorderTraversal(TreeNode* root)
		{
			vector<int> res;
			iter(res, root);

			return res;
		}

		void rec(vector<int>& res, TreeNode* root)
		{
			if (!root)
				return;

			rec(res, root->left);
			res.push_back(root->val);
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
				if (st.empty() || st.top() != node->right) {
					st.push(node->right);
					st.push(node);
					st.push(node->left);
				} else {
					res.push_back(node->val);
				}
			}
		}
};

int main(int argc, char** argv)
{
}
