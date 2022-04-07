// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include <iostream>
#include <vector>

#include "helper.h"
#include "ListNode.h"

using namespace std;
using namespace util;

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
		ListNode* new_head = nullptr;
		ListNode* prev = nullptr;
		while (head) {
			if (head->next && head->next->val == head->val) {
				int val = head->val;
				if (prev)	// remove from head but set prev->next to nullptr in case head and it's dups are the last ones
					prev->next = nullptr; 
				while (head && head->val == val) {
					auto* n = head->next;
					delete head;
					head = n;
				}
			} else {
				if (!prev)
					prev = new_head = head;
				else {
					prev->next = head;
					prev = head;
				}
				head = head->next;
			}
		}

		return new_head;
	}

	// brute force remove dup and set next
	// time: O(n)
	// space: O(n)
	ListNode* rec(ListNode* head)
	{
		if (!head || !head->next)
			return head;

		if (head->next && head->next->val == head->val) {
			auto val = head->val;
			while (head && head->val == val) {
				auto* n = head->next;
				delete head;
				head = n;
			}
			return rec(head); // check for this node again if it has dups
		}

		head->next = rec(head->next);
		return head;
	}
};

static void test(const std::vector<int>& vec)
{
	auto* list = get_list(vec);
	std::cout << "list before: ";
	print_list(list);
	list = Solution().deleteDuplicates(list);
	std::cout << "list after: ";
	print_list(list);
	delete_list(list);
}

int main(int argc, char** argv)
{
	test({1, 1, 2, 2, 3, 4, 5, 5, 5});
}
