// https://leetcode.com/problems/remove-linked-list-elements/

#include "function.h"

struct ListNode *removeElements_rec(struct ListNode *head, int val)
{
	// TODO recursive
	return 0;
}

struct ListNode *removeElements(struct ListNode *head, int val)
{
	struct ListNode *current = head;
	struct ListNode *prev = NULL;

	while (current) {
		struct ListNode *next = current->next;
		if (current->val == val) {
			if (prev)
				prev->next = current->next;
			else
				head = current->next;
			free(current);
		} else {
			prev = current;
		}
		current = next;
	}

	return head;
}
