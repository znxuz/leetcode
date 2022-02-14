#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

class Solution
{
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
        {
            if (!l1 && !l2)
                return nullptr;
            if (!l1)
                return l2;
            if (!l2)
                return l1;

            ListNode* prev = nullptr;
            ListNode* head;
            while (l1 && l2) {
                ListNode** less = (l1->val < l2->val) ? &l1 : &l2;
                if (!prev) {
                    prev = *less;
                    head = prev;
                } else {
                    prev->next = *less;
                    prev = prev->next;
                }
                *less = (*less)->next;
            }
            prev->next = (!l1) ? l2 : l1;

            return head;
        }

        ListNode* mergeTwoListsRec(ListNode* l1, ListNode* l2)
        {
            if (!l1)
                return l2;
            if (!l2)
                return l1;
            if (l1->val < l2->val) {
                l1->next = mergeTwoListsRec(l1->next, l2);
                return l1;
            }
            l2->next = mergeTwoListsRec(l1, l2->next);
            return l2;
        }

        // time complexity: O(n + m)
        // space complexity: O(1)
        ListNode* mergeTwoListsOwn(ListNode* l1, ListNode* l2)
        {
            if (!l1 && !l2)
                return nullptr;
            if (!l1)
                return l2;
            if (!l2)
                return l1;

            ListNode* prev = (l1->val <= l2->val) ? l1 : l2;
            ListNode* head = prev;
            ListNode* next = (prev == l1) ? l2 : l1;
            while (next) {
                while (prev->next && (prev->next->val == prev->val || prev->next->val < next->val))
                    prev = prev->next;
                auto tmp = prev->next;
                prev->next = next;
                prev = next;
                next = tmp;
            }
            return head;
        }
};

int main(int argc, char** argv)
{
}
