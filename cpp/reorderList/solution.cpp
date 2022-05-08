// https://leetcode.com/problems/reorder-list/

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
	void reorderList(ListNode* head)
	{
	    return optimal(head);
	}

	ListNode* find_middle(ListNode* head)
	{
	    ListNode* slow = head;
	    ListNode* fast = head;
	    while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	    }
	    return slow;
	}

	ListNode* reverse(ListNode* head)
	{
	    if (!head || !head->next)
		return head;

	    auto* tail = reverse(head->next);
	    head->next->next = head;
	    head->next = nullptr;
	    return tail;
	}

	ListNode* merge(ListNode* h1, ListNode* h2)
	{
	    if (!h1 && !h2)
		return h1;
	    if (!h1 || !h2)
		return (!h1 ? h2 : h1);
	    if (h1 == h2)
		return h1;

	    h2->next = merge(h1->next, h2->next);
	    h1->next = h2;
	    return h1;
	}

	void optimal(ListNode* head)
	{
	    auto* md = find_middle(head);
	    for (auto* iter = head; iter && iter != md; iter = iter->next)
		if (iter->next == md)
		    iter->next = nullptr;
	    md = reverse(md);
	    merge(head, md);
	}

	// time: O(n)
	// space: O(n)
	void extra_space(ListNode* head)
	{
	    if (!head)
		return;

	    std::vector<ListNode*> vec;
	    for (auto* iter = head; iter; iter = iter->next)
		vec.push_back(iter);
	    size_t begin = 0;
	    size_t end = vec.size() - 1;
	    size_t turn = 0;
	    ListNode** iter = &head;
	    while (begin <= end) {
		*iter = (!(turn++ % 2) ? vec[begin++] : vec[end--]);
		iter = &(*iter)->next;
	    }
	    *iter = nullptr;
	}
};

int main(int argc, char** argv)
{
    auto* h1 = util::make_list({1, 2, 3, 4, 5, 6});
    Solution().reorderList(h1);
    
    print_list(h1);
    delete_list(h1);
}
