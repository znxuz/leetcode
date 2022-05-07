// https://leetcode.com/problems/linked-list-cycle-ii/

#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>

#include "helper.h"
#include "ListNode.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	ListNode *detectCycle(ListNode *head)
	{
	    return optimal(head);
	}

    private:
	ListNode* optimal(ListNode* head)
	{
	    ListNode* intersection = floyd(head);
	    if (!intersection)
		return nullptr;
	    ListNode* p1 = head;
	    while (p1 != intersection) {
		p1 = p1->next;
		intersection = intersection->next;
	    }

	    return p1;
	}

	ListNode* floyd(ListNode* head)
	{
	    ListNode* fast = head;
	    ListNode* slow = head;
	    while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		    return fast;
	    }
	    return nullptr;
	}

	ListNode* extra_space(ListNode* head)
	{
	    std::unordered_set<ListNode*> st;
	    return use_set(head, st);
	}

	// time: O(n)
	// space: O(n)
	ListNode* use_set(ListNode* head, std::unordered_set<ListNode*>& st)
	{
	    if (!head || !st.insert(head).second)
		return head;
	    return use_set(head->next, st);
	}
};

int main(int argc, char** argv)
{
}
