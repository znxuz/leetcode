// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <iostream>
#include <queue>
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
		int maxDepth(TreeNode* root)
		{
			return iter(root);
		}

		int rec(TreeNode* root)
		{
			if (!root)
				return 0;
			return std::max(rec(root->left), rec(root->right)) + 1;
		}

		int iter(TreeNode* root)
		{
			int cnt = 0;
			queue<TreeNode*> stk;
			stk.push(root);
			while (!stk.empty()) {
				int num = stk.size();
				bool valid = false;
				for (int i = 0; i < num; ++i) {
					auto* node = stk.front();
					stk.pop();
					if (!node)
						continue;
					valid = true;
					stk.push(node->left);
					stk.push(node->right);
				}
				cnt += (valid ? 1 : 0);
			}

			return cnt;
		}
};

int main(int argc, char** argv)
{
}
