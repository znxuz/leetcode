// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include <deque>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		std::vector<std::vector<int>> res;
		std::deque<const TreeNode*> deque;
		deque.push_back(root);
		size_t cnt = 0;
		while (!deque.empty()) {
			if (!(cnt & 1))
				zig(res,deque);
			else
				zag(res, deque);
			++cnt;
		}

		return res;
	}

private:
	void zig(std::vector<std::vector<int>>& res, std::deque<const TreeNode*>& deque)
	{
		size_t size = deque.size();
		std::vector<int> row;
		for (size_t i = 0; i < size; ++i) {
			const auto* node = deque.back();
			deque.pop_back();
			if (!node)
				continue;
			row.push_back(node->val);
			deque.push_front(node->left);
			deque.push_front(node->right);
		}
		if (!row.empty())
			res.push_back(row);
	}

	void zag(std::vector<std::vector<int>>& res, std::deque<const TreeNode*>& deque)
	{
		size_t size = deque.size();
		std::vector<int> row;
		for (size_t i = 0; i < size; ++i) {
			const auto* node = deque.front();
			deque.pop_front();
			if (!node)
				continue;
			row.push_back(node->val);
			deque.push_back(node->right);
			deque.push_back(node->left);
		}
		if (!row.empty())
			res.push_back(row);
	}
};

int main(int argc, char** argv)
{
}
