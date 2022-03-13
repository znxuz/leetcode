// https://leetcode.com/problems/balanced-binary-tree/

#include <unordered_map>
#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;

class Solution
{
	public:
		bool isBalanced(TreeNode* root)
		{
			// return rec_improved(root) != -1;
			return iter(root);
		}

		// time: O(n)
		// space: O(n)
		int iter(const TreeNode* root)
		{
			if (!root)
				return true;

			stack<const TreeNode*> stk;
			unordered_map<const TreeNode*, int> map;
			stk.push(root);
			auto* node = root;
			while (!stk.empty() || node) {
				if (node) {
					if (node->right)
						stk.push(node->right);
					stk.push(node);
					node = node->left;
					continue;
				} else {
					node = stk.top();
					stk.pop();
					if (!stk.empty() && stk.top() == node->right) {
						stk.pop();
						stk.push(node);
						node = node->right;
					} else {
						int l_sub = (node->left ? map[node->left] : 0);
						int r_sub = (node->right ? map[node->right] : 0);
						if (std::abs(l_sub - r_sub) > 1)
							return false;
						map[node] = std::max(l_sub, r_sub) + 1;
						node = nullptr;
					}
				}
			}

			return true;
		}

		// time: O(n)
		// space: O(h)
		int rec_improved(const TreeNode* root)
		{
			if (!root)
				return 0;
			int left = rec_improved(root->left);
			int right = rec_improved(root->right);
			if (left == -1 || right == -1 || std::abs(left - right) > 1)
				return -1;
			return std::max(left, right) + 1;
		}

		// time: O(n^2)
		// space: O(h)
		bool rec(const TreeNode* root)
		{
			if (!root)
				return true;
			return rec(root->left) && rec(root->right)
				&& std::abs(max_height(root->left) - max_height(root->right)) <= 1;
		}

		int max_height(const TreeNode* root)
		{
			if (!root)
				return 0;
			return std::max(max_height(root->left), max_height(root->right)) + 1;
		}
};

int main(int argc, char** argv)
{
}
