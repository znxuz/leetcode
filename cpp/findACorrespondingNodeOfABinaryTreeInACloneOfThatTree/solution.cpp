// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

#include <utility>
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
	return iter_bfs(original, cloned, target);
    }

private:
    TreeNode* iter_bfs(TreeNode* og, TreeNode* cl, TreeNode* t)
    {
	std::queue<std::pair<TreeNode*, TreeNode*>> que;
	que.push(std::pair(og, cl));
	while (!que.empty()) {
	    size_t size = que.size();
	    while (size-- > 0) {
		auto [og_node, cl_node] = que.front();
		que.pop();
		if (!og_node)
		    continue;
		if (og_node == t)
		    return cl_node;
		que.push(std::pair(og_node->left, cl_node->left));
		que.push(std::pair(og_node->right, cl_node->right));
	    }
	}

	return nullptr;
    }

    TreeNode* iter_dfs(TreeNode* og, TreeNode* cl, TreeNode* t)
    {
	std::stack<std::pair<TreeNode*, TreeNode*>> stk;
	stk.push(std::pair(og, cl));
	while (!stk.empty()) {
	    auto [og_node, cl_node] = stk.top();
	    stk.pop();
	    if (!og_node)
		continue;
	    if (og_node == t)
		return cl_node;
	    stk.push(std::pair(og_node->left, cl_node->left));
	    stk.push(std::pair(og_node->right, cl_node->right));
	}

	return nullptr;
    }

    TreeNode* rec(TreeNode* og, TreeNode* cl, TreeNode* t)
    {
	if (!og || og == t)
	    return cl;
	auto* left = rec(og->left, cl->left, t);
	if (left)
	    return left;
	return rec(og->right, cl->right, t);
    }
};

int main(int argc, char** argv)
{
}
