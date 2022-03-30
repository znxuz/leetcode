// https://leetcode.com/problems/binary-tree-paths/

#include <stack>
#include <iostream>
#include <string>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<string> binaryTreePaths(TreeNode* root)
	{
		return iter(root);
	}

private:
	vector<string> iter(const TreeNode* root)
	{
		std::stack<const TreeNode*> stk;
		std::stack<string> p;
		vector<string> res;
		stk.push(root);
		p.push(string{});
		while (!stk.empty()) {
			const auto* node = stk.top();
			stk.pop();
			std::string path = p.top() + std::to_string(node->val);
			p.pop();
			if (!node->left && !node->right) {
				res.push_back(path);
			} else {
				path += "->";
				if (node->right)
					stk.push(node->right), p.push(path);
				if (node->left)
					stk.push(node->left), p.push(path);
			}
		}

		return res;
	}

	void rec(const TreeNode* root, vector<string>& res, string p)
	{
		if (!root)
			return;

		p += std::to_string(root->val);
		if (!root->left && !root->right) {
			res.push_back(p);
			return;
		}
		p += "->";

		rec(root->left, res, p);
		rec(root->right, res, p);
	}
};

int main(int argc, char** argv)
{
}
