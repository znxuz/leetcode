// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

#include <utility>
#include <limits>
#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int minDiffInBST(TreeNode* root)
    {
	return iter(root);
    }

private:
    int iter(const TreeNode* root)
    {
	std::stack<const TreeNode*> stk;
	int min = 0;
	stk.push(root);
	int prev_val = 0;
	while (!stk.empty()) {
	    const auto* node = stk.top();
	    stk.pop();
	    if (!node)
		continue;
	    if (stk.empty() || stk.top() != node->right) {
		stk.push(node->right);
		stk.push(node);
		stk.push(node->left);
	    } else {
		if (!min)
		    prev_val = node->val, min = std::numeric_limits<int>::max();
		else
		    min = std::min(min, std::abs(node->val - std::exchange(prev_val, node->val)));
	    }
	}

	return min;
    }
};

int main(int argc, char** argv)
{
}
