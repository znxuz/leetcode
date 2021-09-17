#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// double linked list
typedef struct list {
	int val;
	struct list *prev;
	struct list *next;
} t_list;

typedef struct {
	t_list *head;
	t_list *end;
} TwoSum;

t_list *get_t_list_node(int val);
TwoSum *twoSumCreate();
void twoSumAdd(TwoSum *obj, int val);
bool twoSumFind(TwoSum *obj, int val);
void twoSumFree(TwoSum *obj);
void twoSumPrint(TwoSum *obj);
