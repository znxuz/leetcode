// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include <iostream>
#include <vector>

#include "helper.h"
#include "ListNode.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		ListNode* deleteDuplicates(ListNode* head)
		{
			return iter(head);
		}

	private:
		ListNode* iter(ListNode* head)
		{
			ListNode* iter = head;
			while (iter) {
				auto* next = iter->next;
				while (next && next->val == iter->val) {
					auto* tmp = next->next;
					delete next;
					next = tmp;
				}
				iter->next = next;
				iter = next;
			}

			return head;
		}

		ListNode* rec(ListNode* head)
		{
			if (!head || !head->next)
				return head;

			ListNode* next = rec(head->next);
			if (head->val == next->val) {
				delete head;
				head = next;
			} else {
				head->next = next;
			}

			return head;
		}
};

int main(int argc, char** argv)
{
}
