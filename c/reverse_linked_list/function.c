// https://leetcode.com/problems/reverse-linked-list/

#include "function.h"

struct ListNode *reverseList_rec(struct ListNode *prev, struct ListNode *head)
{
	if (!head)
		return NULL;

	struct ListNode *next = head->next;
	head->next = prev;

	if (!next)
		return head;
	return reverseList_rec(head, next);
}

struct ListNode *reverseList(struct ListNode *head)
{
	return reverseList_rec(NULL, head);
}
