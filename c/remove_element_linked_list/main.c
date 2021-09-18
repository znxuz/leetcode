#include <stdio.h>
#include "../include/list.h"
#include "function.h"

int main(void)
{
	struct ListNode *begin = get_list_node(1);
	append_end(&begin, get_list_node(2));
	append_end(&begin, get_list_node(4));
	append_end(&begin, get_list_node(5));
	append_end(&begin, get_list_node(7));
	append_end(&begin, get_list_node(7));

	print_list(begin);
	// FIXME never ending bug
	removeElements(begin, 7);
	print_list(begin);
}
