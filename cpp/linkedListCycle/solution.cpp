// https://leetcode.com/problems/linked-list-cycle/

#include <memory>
#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"
#include "ListNode.h"

using namespace std;

class Solution
{
	public:
		bool hasCycle(ListNode *head)
		{
			return optimal(head);
		}

		// time: O(n)
		// space: O(1)
		bool optimal(const ListNode* head)
		{
			const ListNode* slow = head;
			const ListNode* fast = head;
			while (slow && fast && fast->next) {
				slow = slow->next;
				fast = fast->next->next;
				if (slow == fast)
					return true;
			}

			return false;
		}

		// time: O(n)
		// space: O(n)
		bool set(const ListNode* head)
		{
			unordered_set<const ListNode*> set;
			while (head)
				if (!set.insert(std::exchange(head, head->next)).second)
					return true;

			return false;
		}
};

int main(int argc, char** argv)
{
}
