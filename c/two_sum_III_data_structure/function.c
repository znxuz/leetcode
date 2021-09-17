// https://leetcode.com/problems/two-sum-iii-data-structure-design/

/**
 * Your TwoSum struct will be instantiated and called as such:
 * TwoSum *obj = twoSumCreate();
 * twoSumAdd(obj, number);
 * bool param_2 = twoSumFind(obj, value);
 * twoSumFree(obj);
*/

#include "function.h"

t_list *get_t_list_node(int val)
{
	t_list *node = malloc(sizeof *node);
	node->val = val;
	node ->next = node->prev = NULL;

	return node;
}

TwoSum *twoSumCreate()
{
	TwoSum *obj = malloc(sizeof *obj);
	obj->head = obj->end = NULL;

	return obj;
}

void twoSumAdd(TwoSum *obj, int val)
{
	t_list *node = get_t_list_node(val);
	if (!obj->head) {
		obj->head = obj->end = node;
	} else {
		t_list *ptr = obj->head;
		if (ptr->val >= node->val) {
			obj->head = node;
			obj->head->next = ptr;
			ptr->prev = obj->head;
		} else {
			while (ptr->next && ptr->next->val < node->val)
				ptr = ptr->next;
			node->next = ptr->next;
			node->prev = ptr;
			ptr->next = node;
			if (!node->next)
				obj->end = node;
			else
				node->next->prev = node;
		}
	}
}

bool twoSumFind(TwoSum *obj, int val)
{
	t_list *begin = obj->head;
	t_list *end = obj->end;
	if (begin == end)
		return false;

	while (begin != end) {
		int sum = begin->val + end->val;
		if (sum < val)
			begin = begin->next;
		else if (sum > val)
			end = end->prev;
		else
			return true;
	}

	return false;
}

void twoSumFree(TwoSum *obj)
{
	t_list *ptr;
	while (obj->head) {
		ptr = obj->head->next;
		free(obj->head);
		obj->head = ptr;
	}
	free(obj);
}

void twoSumPrint(TwoSum *obj)
{
	t_list *ptr = obj->head;
	while (ptr) {
		printf("%d%s", ptr->val, ptr->next ? ", " : "\n");
		ptr = ptr->next;
	}
}
