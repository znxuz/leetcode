// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

// Definition for a Node.
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
    vector<int> postorder(Node* root)
    {
	return iter(root);
    }

private:
    std::vector<int> iter(const Node* root)
    {
	if (!root)
	    return {};

	std::vector<int> res;
	std::stack<const Node*> stk;
	stk.push(root);
	const Node* prev = nullptr;
	while (!stk.empty()) {
	    const Node* node = stk.top();
	    stk.pop();
	    if (node->children.empty() || prev == node->children.back()) {
		res.push_back(node->val);
		prev = node;
	    } else {
		stk.push(node);
		for (size_t i = node->children.size(); i-- > 0;)
		    stk.push(node->children[i]);
	    }
	}

	return res;
    }

    std::vector<int> iter_reverse(const Node* root)
    {
	if (!root)
	    return {};

	std::vector<int> res;
	std::stack<const Node*> stk;
	stk.push(root);
	while (!stk.empty()) {
	    const Node* node = stk.top();
	    stk.pop();
	    res.push_back(node->val);
	    for (const Node* child : node->children)
		stk.push(child);
	}

	std::reverse(begin(res), end(res));
	return res;
    }

    void rec(const Node* root, std::vector<int>& res)
    {
	if (!root)
	    return;
	for (const Node* child : root->children)
	    rec(child, res);
	res.push_back(root->val);
    }
};

int main(int argc, char** argv)
{
}
