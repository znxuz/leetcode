// https://leetcode.com/problems/max-stack/

#include <functional>
#include <stack>
#include <map>
#include <utility>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class MaxStack
{
    public:
	void push(int x)
	{
	    auto* n = new node(x, tail, nullptr);
	    if (!head)
		head = tail = n;
	    else
		tail = tail->next = n;
	    max_list[x].push(n);
	}

	int pop()
	{
	    int val = tail->val;
	    max_list[val].pop();
	    if (max_list[val].empty())
		max_list.erase(val);
	    if (head == tail) {
		delete tail;
		head = tail = nullptr;
	    } else {
		auto* prev_tail = tail->prev;
		prev_tail->next = nullptr;
		delete tail;
		tail = prev_tail;
	    }

	    return val;
	}

	int top()
	{
	    return tail->val;
	}

	int peekMax()
	{
	    return max_list.begin()->first;
	}

	int popMax()
	{
	    auto& stk = max_list.begin()->second;
	    auto* n = stk.top();
	    stk.pop();
	    if (stk.empty())
		max_list.erase(max_list.begin());

	    int val = n->val;
	    if (head == n) {
		if (head == tail) {
		    delete head;
		    head = tail = nullptr;
		} else {
		    auto* next_head = head->next;
		    next_head->prev = nullptr;
		    delete head;
		    head = next_head;
		}
	    } else if (tail == n) {
		auto* prev_tail = tail->prev;
		prev_tail->next = nullptr;
		delete tail;
		tail = prev_tail;
	    } else {
		n->prev->next = n->next;
		n->next->prev = n->prev;
		delete n;
	    }
	    return val;
	}

    private:
	struct node
	{
	    int val;
	    node* prev;
	    node* next;
	    node(int val, node* prev, node* next) : val(val), prev(prev), next(next)
	    {}
	    node(int val) : node(val, nullptr, nullptr)
	    {}
	};

	node* head = nullptr;
	node* tail = nullptr;
	std::map<int, std::stack<node*>, std::greater<int>> max_list;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

int main(int argc, char** argv)
{
}
