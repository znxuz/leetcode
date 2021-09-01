/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * Definition for singly-linked list.
 */

#include <stdlib.h>

 struct ListNode {
	 int val;
	 struct ListNode *next;
 };

struct ListNode *deleteDuplicates_original(struct ListNode *head)
{
	struct ListNode *ret = head;

	while (head && head->next) {
		struct ListNode *ptr = head->next;
		while (ptr && ptr->val == head->val) {
			struct ListNode *tmp = ptr->next;
			free(ptr);
			ptr = tmp;
		}
		head->next = ptr;
		head = ptr;
	}

	return ret;
}

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	struct ListNode *ret = head;
	struct ListNode *ptr;
	while (head && head->next) {
		ptr = head->next;
		if (head->val == ptr->val) {
			head->next = ptr->next;
			free(ptr);
		} else
			head = head->next;
	}

	return ret;
}
