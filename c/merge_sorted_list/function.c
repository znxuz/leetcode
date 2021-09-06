#include "function.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode head;
	struct ListNode *p_head = &head;

	if (!l1 && !l2)
		return NULL;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			p_head->next = l1;
			l1 = l1->next;
			p_head = p_head->next;
		} else {
			p_head->next = l2;
			l2 = l2->next;
			p_head = p_head->next;
		}
	}

	if (l1)
		p_head->next = l1;
	if (!l1)
		p_head->next = l2;

	return head.next;
}
