// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
#include <vector>

#include "helper.h"
#include "ListNode.h"

using namespace std;
using namespace util;

class Solution
{
	public:
		ListNode* reverseList(ListNode* head)
		{
			return iter(head);
		}

		ListNode* iter(ListNode* head)
		{
			ListNode* prev = nullptr;
			while (head) {
				auto* n = head->next;
				head->next = prev;
				prev = head;
				head = n;
			}

			return prev;
		}

		ListNode* rec(ListNode* head)
		{
			if (!head || !head->next)
				return head;

			auto* new_head = rec(head->next);
			head->next->next = head;
			head->next = nullptr;

			return new_head;
		}
};

int main(int argc, char** argv)
{
}
