// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
		vector<int> postorderTraversal(TreeNode* root)
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
			rec(res, root->right);
			res.push_back(root->val);
		}

		void iter(vector<int>& res, TreeNode* root)
		{
			stack<TreeNode*> st;
			auto* node = root;
			while (!st.empty() || node) {
				if (node) {
					if (node->right)
						st.push(node->right);
					st.push(node);
					node = node->left;
				} else {
					node = st.top();
					st.pop();
					if (!st.empty() && st.top() == node->right) {
						st.pop();
						st.push(node);
						node = node->right;
					} else {
						res.push_back(node->val);
						node = nullptr;
					}
				}
			}
		}

		void iter_reverse(vector<int>& res, TreeNode* root)
		{
			stack<TreeNode*> st;
			st.push(root);
			while (!st.empty()) {
				auto* node = st.top();
				st.pop();
				if (!node)
					continue;
				res.push_back(node->val);
				st.push(node->left);
				st.push(node->right);	// preorder right comes before left
			}
			reverse(begin(res), end(res));
		}
};

int main(int argc, char** argv)
{
}
