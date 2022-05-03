// https://leetcode.com/problems/clone-graph/

#include <stack>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Node
{
    public:
	int val;
	vector<Node*> neighbors;
	Node()
	{
	    val = 0;
	    neighbors = vector<Node*>();
	}

	Node(int _val)
	{
	    val = _val;
	    neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors)
	{
	    val = _val;
	    neighbors = _neighbors;
	}
};

class Solution
{
    public:
	Node* cloneGraph(Node* node)
	{
	    return dfs_iter(node);
	}

    private:
	Node* dfs_rec(const Node* node, std::unordered_map<int, Node*>& vertices)
	{
	    if (!node)
		return nullptr;

	    if (vertices.count(node->val))
		return vertices[node->val];

	    auto* vertex = vertices[node->val] = new Node(node->val);
	    for (const auto* neighbor : node->neighbors)
		vertex->neighbors.push_back(dfs_rec(neighbor, vertices));

	    return vertex;
	}

	Node* dfs_iter(const Node* node)
	{
	    if (!node)
		return nullptr;

	    std::unordered_map<int, Node*> vertices;
	    std::stack<const Node*> stk;
	    stk.push(node);
	    Node* entry = vertices[node->val] = new Node(node->val);
	    while (!stk.empty()) {
		const auto* original = stk.top();
		stk.pop();

		Node* vertex = vertices[original->val];
		for (const auto* neighbor : original->neighbors) {
		    if (vertices.count(neighbor->val)) {
			vertex->neighbors.push_back(vertices[neighbor->val]);
		    } else {
			vertex->neighbors.push_back(new Node(neighbor->val));
			vertices[neighbor->val] = vertex->neighbors.back();
			stk.push(neighbor);
		    }
		}
	    }

	    return entry;
	}
};

int main(int argc, char** argv)
{
}
