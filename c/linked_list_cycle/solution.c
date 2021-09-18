#include "function.h"

// floyd's cycle finding problem
bool hasCycle(struct ListNode *head)
{
	struct ListNode *walker = head;
	struct ListNode *runner = head;

	while (walker && runner->next && runner->next->next) {
		walker = walker->next;
		runner = runner->next->next;
		if (walker == runner)
			return true;
	}

	return false;
}
