// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
	Node* connect(Node* root)
	{
		return optimal(root);
	}

private:
	Node* optimal(Node* root)
	{
		Node* begin = root;
		while (begin) {
			Node* next_begin = nullptr;

			Node* prev = nullptr;
			Node* iter = begin;
			while (iter) {
				Node* cur = (prev == iter->left ? iter->right : iter->left);
				if (!cur)
					cur = iter->right;

				if (cur) {
					if (prev)
						prev->next = cur;
					prev = cur;
					if (!next_begin)
						next_begin = cur;
				}

				if (cur == iter->right)
					iter = iter->next;
			}

			begin = next_begin;
		}

		return root;
	}

	Node* via_queue(Node* root)
	{
		std::queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			Node* prev = nullptr;
			for (size_t i = que.size(); i-- > 0;) {
				auto* node = que.front();
				que.pop();
				if (!node)
					continue;
				if (prev)
					prev->next = node;
				prev = node;
				que.push(node->left);
				que.push(node->right);
			}
		}

		return root;
	}
};

int main(int argc, char** argv)
{
}
