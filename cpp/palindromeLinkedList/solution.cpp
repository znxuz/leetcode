// https://leetcode.com/problems/palindrome-linked-list/

#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"
#include "ListNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool isPalindrome(ListNode* head)
	{
		return optimal(head);
	}

	bool optimal(ListNode* head)
	{
		ListNode* half = get_half(head);
		ListNode* reversed = reverse_list(half->next);
		bool res = true;
		for (auto* it = reversed; it && res;) {
			if (std::exchange(it, it->next)->val != std::exchange(head, head->next)->val)
				res = false;
		}
		half->next = reverse_list(reversed);

		return res;
	}

	ListNode* reverse_list(ListNode* head)
	{
		if (!head || !head->next)
			return head;
		auto* new_head = reverse_list(head->next);
		head->next->next = head;
		head->next = nullptr;
		return new_head;
	}

	ListNode* get_half(ListNode* head)
	{
		if (!head)
			return head;

		auto* slow = head;
		auto* fast = head;
		while (fast->next && fast->next->next)
			std::exchange(slow, slow->next), std::exchange(fast, fast->next->next);

		return slow;
	}

	// time: O(n)
	// space: O(n)
	bool rec(ListNode* head, ListNode** cmp)
	{
		if (!head)
			return true;
		if (!rec(head->next, cmp))
			return false;
		if (head->val != (*cmp)->val)
			return false;
		*cmp = (*cmp)->next;

		return true;
	}
};

int main(int argc, char** argv)
{
}
