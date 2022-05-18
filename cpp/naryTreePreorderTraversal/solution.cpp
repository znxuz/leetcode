// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

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
    vector<int> preorder(Node* root)
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
	while (!stk.empty()) {
	    const Node* node = stk.top();
	    stk.pop();
	    res.push_back(node->val);
	    for (size_t i = node->children.size(); i-- > 0;)
		stk.push(node->children[i]);
	}

	return res;
    }

    void rec(const Node* root, std::vector<int>& res)
    {
	if (!root)
	    return;
	res.push_back(root->val);
	for (const Node* child : root->children)
	    rec(child, res);
    }
};

int main(int argc, char** argv)
{
}
