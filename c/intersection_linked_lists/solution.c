#include "function.h"

static int get_list_size(struct ListNode *list)
{
	if (!list)
		return 0;
	if (!list->next)
		return 1;
	return 1 + get_list_size(list->next);
}

static void offset_head(struct ListNode **ptr_a, struct ListNode **ptr_b, int diff)
{
	struct ListNode **offset_ptr = diff > 0 ? ptr_a : ptr_b;
	diff = diff < 0 ? -diff : diff;
	while (diff--)
		*offset_ptr = (*offset_ptr)->next;
}

struct ListNode *getIntersectionNode(struct ListNode *head_a, struct ListNode *head_b)
{
	struct ListNode *ptr_a = head_a;
	struct ListNode *ptr_b = head_b;

	int len_a = get_list_size(ptr_a);
	int len_b = get_list_size(ptr_b);
	offset_head(&ptr_a, &ptr_b, len_a - len_b);
	while (ptr_a && ptr_b) {
		if (ptr_a == ptr_b)
			return ptr_a;
		ptr_a = ptr_a->next;
		ptr_b = ptr_b->next;
	}
	return 0;
}

// O(n^2) eww
struct ListNode *brute_force_it(struct ListNode *headA, struct ListNode *headB)
{
	for (struct ListNode *ptr_a = headA; ptr_a; ptr_a = ptr_a->next) {
		for (struct ListNode *ptr_b = headB; ptr_b; ptr_b = ptr_b->next) {
			if (ptr_a == ptr_b)
				return ptr_a;
		}
	}
	return 0;
}
