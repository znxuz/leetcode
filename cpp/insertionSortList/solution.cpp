// https://leetcode.com/problems/insertion-sort-list/

#include <algorithm>
#include <iostream>
#include <vector>

#include "ListNode.h"
#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	// time: O(n^2)
	// space: O(1)
	ListNode* insertionSortList(ListNode* head)
	{
	    ListNode* cur = head;
	    ListNode* prev = nullptr;
	    while (cur) {
		ListNode* pos = head;
		ListNode* pos_prev = nullptr;
		while (pos != cur && pos->val < cur->val)
		    pos_prev = std::exchange(pos, pos->next);

		if (pos == cur) {
		    prev = std::exchange(cur, cur->next);
		    continue;
		}
		auto* next = cur->next;
		if (prev)
		    prev->next = next;
		if (!pos_prev)
		    head = cur;
		else
		    pos_prev->next = cur;
		cur->next = pos;
		cur = next;
	    }

	    return head;
	}
};

int main(int argc, char** argv)
{
}
