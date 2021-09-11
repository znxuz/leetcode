// https://leetcode.com/problems/linked-list-cycle/

#include "function.h"

bool hasCycle(struct ListNode *head)
{
	if (!head)
		return false;

	struct ListNode *first = head;
	while (head->next) {
		if (head == head->next)
			return true;
		struct ListNode *ptr = first;
		while (ptr != head) {
			if (ptr == head->next)
				return true;
			ptr = ptr->next;
		}
		head = head->next;
	}
	return false;
}
