// https://leetcode.com/problems/add-two-numbers/

#include <iostream>
#include <type_traits>
#include <vector>
#include "ListNode.h"

using namespace std;

class Solution
{
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
		{
			ListNode* head = nullptr;
			ListNode* it = nullptr;
			int carry = 0;
			while (l1 || l2) {
				int val1 = l1 ? l1->val : 0;
				int val2 = l2 ? l2->val : 0;
				int sum = val1 + val2 + carry;
				carry = sum / 10;
				sum %= 10;
				auto* node = new ListNode(sum);
				if (!head) {
					head = node;
					it = head;
				} else {
					it->next = node;
					it = node;
				}
				l1 = l1 ? l1->next : l1;
				l2 = l2 ? l2->next : l2;
			}
			if (carry)
				it->next = new ListNode(1);

			return head;
		}

		ListNode* addTwoNumbersRec(ListNode* l1, ListNode* l2)
		{
			return add_with_carry(l1, l2, 0);
		}

		ListNode* add_with_carry(ListNode* l1, ListNode* l2, int carry)
		{
			if (!l1 && !l2)
				return carry ? new ListNode(1) : nullptr;

			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			int sum = val1 + val2 + carry;
			carry = sum / 10;
			sum %= 10;
			auto* node = new ListNode(sum);
			node->next = add_with_carry(l1 ? l1->next : 0, l2 ? l2->next : 0, carry);

			return node;
		}
};

int main(int argc, char** argv)
{
}
