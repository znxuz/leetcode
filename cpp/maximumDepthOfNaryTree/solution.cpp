// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

#include <utility>
#include <queue>
#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Node
{
public:
    int val;
    vector<Node*> children;

    Node()
    {}

    Node(int _val)
    {
	val = _val;
    }

    Node(int _val, vector<Node*> _children)
    {
	val = _val;
	children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node* root)
    {
	return iter_dfs(root);
    }

private:
    int iter_dfs(const Node* root)
    {
	if (!root)
	    return 0;

	std::stack<std::pair<const Node*, int>> stk;
	stk.push(pair(root, 1));
	int depth = 0;
	while (!stk.empty()) {
	    const auto n = stk.top();
	    stk.pop();
	    depth = std::max(depth, n.second);
	    for (const auto& c : n.first->children)
		stk.push(pair(c, n.second + 1));
	}

	return depth;
    }

    int iter_bfs(const Node* root)
    {
	if (!root)
	    return 0;

	std::queue<const Node*> que;
	que.push(root);
	int depth = 0;
	while (!que.empty()) {
	    size_t size = que.size();
	    while (size-- > 0) {
		const auto* node = que.front();
		que.pop();
		if (!node)
		    continue;
		for (const auto& child : node->children)
		    que.push(child);
	    }
	    ++depth;
	}

	return depth;
    }

    int rec_dfs(const Node* root)
    {
	if (!root)
	    return 0;

	int depth = 0;
	for (const auto& child : root->children)
	    depth = std::max(depth, rec_dfs(child));

	return ++depth;
    }
};

int main(int argc, char** argv)
{
}
