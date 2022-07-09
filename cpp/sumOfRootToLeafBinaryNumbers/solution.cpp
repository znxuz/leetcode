// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int sumRootToLeaf(TreeNode* root) 
    {
	return iter(root);
    }

private:
    constexpr static auto is_leaf = [](const TreeNode* node) {
	return !node->left && !node->right;
    };

    int iter(const TreeNode* root)
    {
	auto sum = 0;
	auto stk = std::stack<std::pair<const TreeNode*, int>>();
	stk.push({root, 0});
	while (!stk.empty()) {
	    const auto [node, prev_sum] = stk.top();
	    stk.pop();
	    if (!node || (!stk.empty() && stk.top().first == node->right))
		continue;

	    auto cur_sum = (prev_sum << 1) + node->val;
	    if (is_leaf(node)) {
		sum += cur_sum;
	    } else {
		stk.push({node->right, cur_sum});
		stk.push({node, cur_sum});
		stk.push({node->left, cur_sum});
	    }
	}

	return sum;
    }

    // time: O(n)
    // space: O(h)
    int rec(const TreeNode* root, int sum)
    {
	if (!root)
	    return 0;

	sum = (sum << 1) + root->val;
	return (is_leaf(root) ? sum : rec(root->left, sum) + rec(root->right, sum));
    }
};

int main(int argc, char** argv)
{
}
