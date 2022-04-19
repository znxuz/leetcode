// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		return iter(root);
	}

private:
	std::vector<std::vector<int>> iter(const TreeNode* root)
	{
		std::vector<std::vector<int>> res;
		std::queue<const TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			auto size = que.size();
			std::vector<int> lvl;
			for (size_t i = 0; i < size; ++i) {
				auto* node = que.front();
				que.pop();
				if (!node)
					continue;
				lvl.push_back(node->val);
				que.push(node->left);
				que.push(node->right);
			}
			if (!lvl.empty())
				res.push_back(std::move(lvl));
		}

		return res;
	}
};

int main(int argc, char** argv)
{
}
