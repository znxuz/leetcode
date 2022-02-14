#include "ListNode.h"

ListNode::ListNode() : val{0}
{}

ListNode::ListNode(int v) : val{v}, next{nullptr}
{}

ListNode::ListNode(int v, ListNode* n) : val{v}, next{n}
{}
