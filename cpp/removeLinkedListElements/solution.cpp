// https://leetcode.com/problems/remove-linked-list-elements/

#include <iostream>
#include <vector>

#include "helper.h"
#include "ListNode.h"

using namespace std;
using util::ListNode;

class Solution
{
	public:
		ListNode* removeElements(ListNode* head, int val)
		{
			return iter(head, val);
		}

	private:
		ListNode* iter(ListNode* head, int val)
		{
			ListNode* new_head{nullptr};
			ListNode* prev{nullptr};
			while (head) {
				auto* n = head->next;
				if (head->val == val) {
					delete head;
					if (prev)
						prev->next = n;
				} else if (!new_head) {
					new_head = head;
					prev = head;
				} else {
					prev->next = head;
					prev = head;
				}
				head = n;
			}

			return new_head;
		}

		ListNode* iter_sentinel(ListNode* head, int val)
		{
			ListNode* sentinel = new ListNode{};
			ListNode* prev = sentinel;
			prev->next = head;
			while (head) {
				auto* n = head->next;
				if (head->val == val) {
					delete head;
					prev->next = n;
				} else {
					prev = head;
				}
				head = n;
			}

			ListNode* res = sentinel->next;
			delete sentinel;
			return res;
		}

		ListNode* rec(ListNode* head, int val)
		{
			if (!head)
				return head;

			auto* next = rec(head->next, val);
			if (head->val == val) {
				delete head;
				return next;
			}
			head->next = next;
			return head;
		}
};

int main(int argc, char** argv)
{
}
