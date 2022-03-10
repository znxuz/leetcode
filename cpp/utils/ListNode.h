#pragma once

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val{0}
	{}

    ListNode(int val) : val{val}, next{nullptr}
	{}

    ListNode(int val, ListNode* next) : val{val}, next{next}
	{}
};
