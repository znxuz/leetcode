// https://leetcode.com/problems/copy-list-with-random-pointer/

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
	Node* next;
	Node* random;

	Node(int _val)
	{
	    val = _val;
	    next = NULL;
	    random = NULL;
	}
};

class Solution
{
    public:
	Node* copyRandomList(Node* head)
	{
	    return modify_original(head);
	}

    private:
	// time: O(n)
	// space: O(1)
	Node* modify_original(Node* head)
	{
	    Node* iter = head;
	    while (iter) {
		auto* node = new Node(iter->val);
		auto* next = iter->next;
		iter->next = node;
		node->next = next;
		iter = next;
	    }

	    iter = head;
	    while (iter) {
		if (iter->random)
		    iter->next->random = iter->random->next;
		iter = iter->next->next;
	    }

	    Node* new_head = nullptr;
	    Node* new_iter = nullptr;
	    iter = head;
	    while (iter) {
		auto* next = iter->next->next;
		auto* new_node = iter->next;
		if (!new_head)
		    new_head = new_iter = new_node;
		else
		    new_iter = new_iter->next = new_node;
		iter->next = next;
		iter = next;
	    }

	    return new_head;
	}

	// time: O(n)
	// space: O(n)
	Node* iter(const Node* head)
	{
	    std::unordered_map<const Node*, Node*> copycats;
	    const Node* iter = head;
	    Node* new_head = nullptr;
	    Node* new_iter = nullptr;
	    while (iter) {
		auto* node = new Node(iter->val);
		copycats[iter] = node;
		if (!new_head)
		    new_iter = new_head = node;
		else
		    new_iter = new_iter->next = node;
		iter = iter->next;
	    }

	    iter = head;
	    new_iter = new_head;
	    while (iter) {
		new_iter->random = copycats[iter->random];
		new_iter = new_iter->next;
		iter = iter->next;
	    }

	    return new_head;
	}

	// time: O(n)
	// space: O(n)
	Node* rec(const Node* head, std::unordered_map<const Node*, Node*>& copycats)
	{
	    if (!head)
		return nullptr;

	    auto* copy = new Node(head->val);
	    copycats[head] = copy;
	    copy->next = rec(head->next, copycats);
	    copy->random = copycats[head->random];

	    return copy;
	}
};

int main(int argc, char** argv)
{
}
