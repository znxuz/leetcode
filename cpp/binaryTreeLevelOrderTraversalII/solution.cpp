// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

#include <stack>
#include <queue>
#include <iostream>
#include <vector>

#include "TreeNode.h"
#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		std::stack<std::vector<int>> stk;
		std::queue<const TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			size_t size = que.size();
			std::vector<int> lvl;
			for (size_t i = 0; i < size; ++i) {
				const auto* node = que.front();
				que.pop();
				if (!node)
					continue;
				lvl.push_back(node->val);
				que.push(node->left);
				que.push(node->right);
			}
			if (!lvl.empty())
				stk.push(std::move(lvl));
		}

		std::vector<std::vector<int>> res;
		while (!stk.empty())
			res.push_back(stk.top()), stk.pop();
		return res;
	}
};

int main(int argc, char** argv)
{
}
