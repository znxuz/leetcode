#pragma once

struct ListNode
{
    int val;
    ListNode* next;

    ListNode();
    ListNode(int val);
    ListNode(int val, ListNode* next);
};
