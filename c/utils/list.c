#include "../include/list.h"

struct ListNode *get_list_node(int val)
{
	struct ListNode *node = malloc(sizeof *node);
	node->val = val;
	node->next = 0;
	return node;
}

void append_end(struct ListNode **head, struct ListNode *node)
{
	if (!*head)
		*head = node;
	else if (!(*head)->next)
		(*head)->next = node;
	else
		append_end(&(*head)->next, node);
}

void append_first(struct ListNode **head, struct ListNode *node)
{
	if (*head)
		node->next = *head;
	*head = node;
}

void print_list(struct ListNode *head)
{
	if (!head)
		return;
	printf("%d\n", head->val);
	if (head->next)
		print_list(head->next);
}

void free_list(struct ListNode *head)
{
	if (!head)
		return;
	free_list(head->next);
	free(head);
}
