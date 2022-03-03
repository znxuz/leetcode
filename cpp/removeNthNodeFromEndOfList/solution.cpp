// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <iostream>
#include <stdexcept>
#include <vector>
#include <stack>

#include "helper.h"
#include "ListNode.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n)
		{
			return removeNthFromEndOnePass(head, n);
		}

		ListNode* removeNthFromEndOnePass(ListNode* head, int n)
		{
			ListNode ret(-1, head);
			ListNode* slow;
			ListNode* fast;
			slow = fast = &ret;
			for (int i = 0; i <= n; ++i)
				fast = fast->next;
			while (fast) {
				slow = slow->next;
				fast = fast->next;
			}
			auto* next = slow->next->next;
			delete slow->next;
			slow->next = next;

			return ret.next;
		}
		ListNode* removeNthFromEndOnePassWithoutDummy(ListNode* head, int n)
		{
			ListNode* fast;
			ListNode* slow;

			fast = slow = head;
			for (int i = 0; i < n; ++i)
				fast = fast->next;

			ListNode* next;
			if (!fast) {
				next = head->next;
				delete head;
				return next;
			}
			while (fast->next) {
				slow = slow->next;
				fast = fast->next;
			}
			next = slow->next->next;
			delete slow->next;
			slow->next = next;

			return head;
		}

		ListNode* removeNthFromEndStackTwoPasses(ListNode* head, int n)
		{
			stack<ListNode*> st;
			while (head) {
				st.push(head);
				head = head->next;
			}
			while (!st.empty()) {
				auto* cur = st.top();
				st.pop();
				if (n != 1) {
					cur->next = head;
					head = cur;
				} else {
					delete cur;
				}
				n--;
			}

			return head;
		}

		ListNode* removeNthFromEndHelperTwoPasses(ListNode* head, int n)
		{
			int size = get_list_size(head);
			return remove_nth_node(head, size - n);
		}

		int get_list_size(ListNode* head)
		{
			if (!head)
				return 0;
			return 1 + get_list_size(head->next);
		}

		ListNode* remove_nth_node(ListNode* head, int n)
		{
			if (n < 0)
				throw std::invalid_argument("");
			if (n == 0) {
				auto* next = head->next;
				delete head;
				return next;
			}

			head->next = remove_nth_node(head->next, n - 1);
			return head;
		}
};

int main(int argc, char** argv)
{
}
