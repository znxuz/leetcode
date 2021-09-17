#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode {
     int val;
     struct ListNode *next;
 } s_list;

struct ListNode *get_list_node(int val);
void append_end(struct ListNode **head, struct ListNode *node);
void append_first(struct ListNode **head, struct ListNode *node);
void print_list(struct ListNode *head);
void free_list(struct ListNode *head);

#endif
