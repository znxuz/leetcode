#include <stdio.h>
#include "function.h"

int main(void)
{
	struct ListNode *head = get_list_node(1);
	append_end(head, get_list_node(2));
	append_end(head, get_list_node(3));
	append_end(head, get_list_node(4));
	append_end(head, get_list_node(5));
	append_end(head, get_list_node(6));
	append_end(head, get_list_node(7));
	append_end(head, get_list_node(8));
	append_end(head, get_list_node(9));
	append_end(head, get_list_node(10));
	append_end(head, get_list_node(11));
	print_list(head);
	free_list(head);
}
