// https://leetcode.com/problems/rotate-list/

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
		ListNode* rotateRight(ListNode* head, int k)
		{
			return iter(head, k);
		}

		// time: O(n)
		// space: O(1)
		ListNode* iter(ListNode* head, int k)
		{
			if (!head)
				return head;

			int size = get_size(head);
			k = size - (k % size);

			auto* it = head;
			while (it && k-- > 0)
				it = it->next;
			if (!it)
				return head;

			auto* new_head = it;
			auto* n = it->next;
			while (n != new_head) {
				if (!n)
					n = head;
				it->next = std::exchange(n, n->next);
				it = it->next;
			}
			it->next = nullptr;

			return new_head;
		}

	private:
		size_t get_size(const ListNode* head)
		{
			return (!head ? 0 : 1 + get_size(head->next));
		}
};

static void test(ListNode* list)
{
	print_list(list);
	auto* res{Solution().rotateRight(nullptr, 1)};
}

int main(int argc, char** argv)
{
	ListNode* n1 = new ListNode {1};

	test(n1);
	delete_list(n1);
}
