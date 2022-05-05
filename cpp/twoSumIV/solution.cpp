// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

#include <stack>
#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	bool findTarget(TreeNode* root, int k)
	{
	    return iter(root, k);
	}

    private:
	bool iter(const TreeNode* root, int k)
	{
	    std::vector<int> sorted;
	    std::stack<const TreeNode*> stk;
	    stk.push(root);
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
		    sorted.push_back(node->val);
		}
	    }

	    if (sorted.empty())
		return false;
	    for (size_t i = 0, j = sorted.size() - 1; i < j;) {
		int sum = sorted[i] + sorted[j];
		if (sum == k)
		    return true;
		if (sum < k)
		    ++i;
		else
		    --j;
	    }

	    return false;
	}

	bool rec(const TreeNode* root, int k, std::unordered_set<int>& complements)
	{
	    if (!root)
		return false;

	    if (rec(root->left, k, complements))
		return true;
	    if (complements.count(k - root->val))
		return true;
	    complements.insert(root->val);
	    return rec(root->right, k, complements);
	}
};

int main(int argc, char** argv)
{
}
