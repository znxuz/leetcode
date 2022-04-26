// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

#include <stack>
#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int getMinimumDifference(TreeNode* root)
	{
		return iter(root);
	}

private:
	// time: O(n)
	// space: O(n)
	int iter(const TreeNode* root)
	{
		std::stack<const TreeNode*> stk;
		stk.push(root);
		int prev = 0;
		bool first = true;
		int min = std::numeric_limits<int>::max();
		while (!stk.empty()) {
			auto* node = stk.top();
			stk.pop();
			if (!node)
				continue;
			if (stk.empty() || stk.top() != node->right) {
				stk.push(node->right);
				stk.push(node);
				stk.push(node->left);
			} else {
				if (!first)
					min = std::min(min, node->val - prev);
				else
					first = false;
				prev = node->val;
			}
		}
		//  	543
		//    384	652
		//     445    699

		return min;
	}
};

int main(int argc, char** argv)
{
}
