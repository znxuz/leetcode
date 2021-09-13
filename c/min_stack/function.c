// https://leetcode.com/problems/min-stack/

#include "function.h"

typedef struct {
	int *array;
	int capacity;
	int top;
	int min;
} MinStack;

MinStack* minStackCreate()
{
	MinStack *stack = malloc(sizeof *stack);
	stack->capacity = 10;
	stack->array = malloc(sizeof *stack->array * stack->capacity);
	stack->top = -1;
	stack->min = INT_MAX;

	return stack;
}

void minStackPush(MinStack* stack, int val)
{
	if (stack->top + 1 < stack->capacity) {
		stack->array[++stack->top] = val;
	} else {
		int *tmp = stack->array;
		stack->array = malloc(sizeof *stack * ++stack->capacity);
		for (int i = 0; i < stack->capacity - 1; i++)
			*(stack->array + i) = *(tmp + i);
		free(tmp);
		stack->array[++stack->top] = val;
	}
	stack->min = val < stack->min ? val : stack->min;
}

static void set_min(MinStack *stack)
{
	if (stack->top == -1) {
		stack->min = INT_MAX;
		return;
	}
	int min = *(stack->array);
	for (int i = 1; i <= stack->top; i++)
		min = *(stack->array + i) < min ? *(stack->array + i) : min;
	stack->min = min;
}

void minStackPop(MinStack* stack)
{
	int val = stack->array[stack->top--];
	if (stack->min == val)
		set_min(stack);
}

int minStackTop(MinStack* stack)
{
	return stack->array[stack->top];
}

int minStackGetMin(MinStack* stack)
{
	return stack->min;
}

void minStackFree(MinStack* stack)
{
	free(stack->array);
	free(stack);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* stack = minStackCreate();
 * minStackPush(stack, val);
 
 * minStackPop(stack);
 
 * int param_3 = minStackTop(stack);
 
 * int param_4 = minStackGetMin(stack);
 
 * minStackFree(stack);
*/
