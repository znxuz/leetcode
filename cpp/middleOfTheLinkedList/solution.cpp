// https://leetcode.com/problems/middle-of-the-linked-list/

#include <iostream>
#include <vector>

#include "ListNode.h"
#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
	size_t sz = 0;
	return rec(head, sz);
    }

private:
    ListNode* rec(ListNode* head, size_t& sz)
    {
	if (!head)
	    return head;

	size_t cur = sz++;
	auto* md = rec(head->next, sz);
	return (sz / 2 == cur ? head : md);
    }

    ListNode* fast_slow(ListNode* head)
    {
	auto* fast = head;
	auto* slow = head;
	while (fast && fast->next) {
	    slow = slow->next;
	    fast = fast->next->next;
	}

	return slow;
    }
};

int main(int argc, char** argv)
{
}
