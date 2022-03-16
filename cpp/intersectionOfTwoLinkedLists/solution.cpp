// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <iostream>
#include <vector>

#include "helper.h"
#include "ListNode.h"

using namespace std;

class Solution
{
	public:
		// time: O(n + m)
		// space: O(1)
		ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
		{
			ListNode* p1 = headA;
			ListNode* p2 = headB;
			while (p1 != p2) {
				p1 = (!p1 ? headB : p1->next);
				p2 = (!p2 ? headA : p2->next);
			}

			return p1;
		}
};

int main(int argc, char** argv)
{
}
