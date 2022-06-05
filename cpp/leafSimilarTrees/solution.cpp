// https://leetcode.com/problems/leaf-similar-trees/

#include <queue>
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
	return iter(root1, root2);
    }

private:
    // time: O(n + m) with short circuit condition
    // space: O(max(n, m))
    bool iter(const TreeNode* r1, const TreeNode* r2)
    {
	std::queue<int> que;
	std::stack<const TreeNode*> stk;
	stk.push(r1);
	while (!stk.empty()) {
	    auto* node = stk.top();
	    stk.pop();
	    if (!node)
		continue;
	    if (!node->left && !node->right)
		que.push(node->val);
	    stk.push(node->right);
	    stk.push(node->left);
	}
	stk.push(r2);
	while (!stk.empty()) {
	    auto* node = stk.top();
	    stk.pop();
	    if (!node)
		continue;
	    if (!node->left && !node->right) {
		if (que.front() != node->val)
		    return false;
		que.pop();
	    }
	    stk.push(node->right);
	    stk.push(node->left);
	}
	return que.empty();
    }

    // time: O(n + m)
    // space: O(n + m)
    std::vector<int> get_leaves(const TreeNode* root)
    {
	std::vector<int> leaves;
	std::stack<const TreeNode*> stk;
	stk.push(root);
	while (!stk.empty()) {
	    auto* node = stk.top();
	    stk.pop();
	    if (!node)
		continue;
	    if (!node->left && !node->right)
		leaves.push_back(node->val);
	    stk.push(node->right);
	    stk.push(node->left);
	}

	return leaves;
    }
};

int main(int argc, char** argv)
{
}
