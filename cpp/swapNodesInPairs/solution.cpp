// https://leetcode.com/problems/swap-nodes-in-pairs/
#include <iostream>
#include <type_traits>
#include <utility>
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
		ListNode* swapPairs(ListNode* head)
		{
			return swapPairsIter(head);
		}

		ListNode* swapPairsIter(ListNode* head)
		{
			ListNode* ret = nullptr;
			ListNode* prev = nullptr;
			while (head && head->next) {
				auto* push = head->next;
				head->next = push->next;
				push->next = head;
				if (!ret)
					ret = push;
				else
					prev->next = push;
				prev = push->next;
				head = head->next;
			}

			return (ret ? ret : head);
		}

		ListNode* swapPairsRec(ListNode* head)
		{
			if (!head || !head->next)
				return head;

			auto* next = head->next;
			head->next = swapPairs(next->next);
			next->next = head;

			return next;
		}
};

int main(int argc, char** argv)
{
}
