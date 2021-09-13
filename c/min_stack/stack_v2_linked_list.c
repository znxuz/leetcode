#include "function.h"
#include "../include/list.h"

typedef struct {
	struct ListNode *last;
	int min;
} MinStack;

MinStack* minStackCreate()
{
	MinStack *stack = malloc(sizeof *stack);
	stack->last = NULL;
	stack->min = INT_MAX;

	return stack;
}

void minStackPush(MinStack* stack, int val)
{
	if (val < stack->min)
		stack->min = val;
	struct ListNode *new = malloc(sizeof *new);
	new->next = NULL;
	new->val = val;
	if (stack->last)
		new->next = stack->last;
	stack->last = new;
}

static void set_min(MinStack *stack)
{
	struct ListNode *ptr = stack->last;
	int min = INT_MAX;
	while (ptr) {
		min = ptr->val < min ? ptr->val : min;
		ptr = ptr->next;
	}

	stack->min = min;
}

void minStackPop(MinStack* stack)
{
	struct ListNode *to_free = stack->last;
	stack->last = stack->last->next;
	if (to_free->val == stack->min)
		set_min(stack);
	free(to_free);
}

int minStackTop(MinStack* stack)
{
	return stack->last->val;
}

int minStackGetMin(MinStack* stack)
{
	return stack->min;
}

void minStackFree(MinStack* stack)
{
	struct ListNode *ptr = stack->last;
	while (ptr) {
		stack->last = stack->last->next;
		free(ptr);
		ptr = stack->last;
	}
	free(stack);
}
