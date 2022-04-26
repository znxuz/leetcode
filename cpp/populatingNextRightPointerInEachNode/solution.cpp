// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

/*
// Definition for a Node.
*/

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
	Node* connect(Node* root)
	{
		return optimal(root);
	}

private:
	// time: O(n)
	// space: O(1)
	Node* optimal(Node* root)
	{
		Node* left_most = root;
		while (left_most) {
			Node* head = left_most;
			while (head && head->left) {
				head->left->next = head->right; // connect left/right children
				if (head->next)
					head->right->next = head->next->left; // connect right to left non-children
				head = head->next; // change root on the same level
			}
			left_most = left_most->left; // go down next level
		}

		return root;
	}

	// time: O(n)
	// space: O(2^(H - 1))
	Node* iter(Node* root)
	{
		std::queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			Node* prev = nullptr;
			for (size_t i = que.size(); i > 0; --i) {
				auto* node = que.front();
				que.pop();
				if (!node)
					return root;
				if (prev)
					prev->next = node;
				prev = node;
				que.push(node->left);
				que.push(node->right);
			}
			prev = nullptr;
		}

		return root;
	}
};

int main(int argc, char** argv)
{
}
