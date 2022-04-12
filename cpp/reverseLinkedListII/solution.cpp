// https://leetcode.com/problems/reverse-linked-list-ii/

#include <iostream>
#include <vector>

#include "helper.h"
#include "ListNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	// time: O(n)
	// space: O(1)
	ListNode* reverseBetween(ListNode* head, size_t left, size_t right)
	{
		ListNode sentinel(0, head);
		ListNode* prev = &sentinel;
		for (size_t i = 0; i < left - 1; ++i)
			prev = prev->next;

		ListNode* cur = prev->next;
		for (size_t i = 0; i < right - left; ++i) {
			auto* tmp = prev->next;
			prev->next = cur->next;
			cur->next = cur->next->next;
			prev->next->next = tmp;
		}

		return sentinel.next;
	}

	// time: O(n)
	// space: O(n)
	ListNode* with_helper(ListNode* head, size_t left, size_t right)
	{
		if (!head || !head->next)
			return head;
		if (left == 1)
			return reverse_n(head, right, &head);

		head->next = with_helper(head->next, left - 1, right - 1);
		return head;
	}

private:
	ListNode* reverse_n(ListNode* head, size_t k, ListNode** successor)
	{
		if (k == 1 || !head->next) {
			*successor = head->next;
			return head;
		}
		auto* new_head = reverse_n(head->next, k - 1, successor);
		head->next->next = head;
		head->next = *successor;

		return new_head;
	}

};

int main(int argc, char** argv)
{
	auto* head = get_list({3, 5});
	head = Solution().with_helper(head, 1, 2);
	print_list(head);
	delete_list(head);
}
