// https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include <queue>
#include <deque>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;

class Solution
{
	public:
		int minDepth(TreeNode* root)
		{
			return iter(root);
		}

		// BFS
		// time: O(n)
		// space: O(n)
		int iter(const TreeNode* root)
		{
			if (!root)
				return 0;

			queue<const TreeNode*> q;
			q.push(root);
			int min_height = 0;
			while (!q.empty()) {
				int cnt = q.size();
				bool leaf = 0;
				for (int i = 0; i < cnt; ++i) {
					const auto* node = q.front();
					q.pop();
					if (!node)
						continue;
					if (!node->left && !node->right)
						leaf = 1;
					q.push(node->left);
					q.push(node->right);
				}
				++min_height;
				if (leaf)
					break;
			}

			return min_height;
		}

		// DFS
		int rec(const TreeNode* root)
		{
			if (!root)
				return 0;
			if (!root->left && !root->right)
				return 1;
			if (!root->left || !root->right)
				return (!root->left ? rec(root->right) : rec(root->left)) + 1;
			return std::min(rec(root->left), rec(root->right)) + 1;
		}
};

int main(int argc, char** argv)
{
}
