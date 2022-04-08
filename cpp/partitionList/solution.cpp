// https://leetcode.com/problems/partition-list/

#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"
#include "ListNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	ListNode* partition(ListNode* head, int x)
	{
		return two_pointer_iter(head, x);
	}

private:
	ListNode* two_pointer_iter(ListNode* head, int x)
	{
		ListNode n1, n2;
		ListNode* p1 = &n1;
		ListNode* p2 = &n2;
		while (head) {
			ListNode*& set = (head->val < x ? p1 : p2);
			set->next = std::exchange(head, head->next);
			set = set->next;
		}

		p1->next = n2.next;
		p2->next = nullptr;
		return n1.next;
	}
};

int main(int argc, char** argv)
{
}
