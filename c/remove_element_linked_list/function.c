// https://leetcode.com/problems/remove-linked-list-elements/

#include "function.h"

struct ListNode *removeElements_rec(struct ListNode *head, int val)
{
	if (!head)
		return NULL;
	head->next = removeElements_rec(head->next, val);
	if (head->val == val) {
		struct ListNode *next = head->next;
		free(head);
		return next;
	}
	return head;
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
