#pragma once

#include <algorithm>
#include <iostream>

namespace util
{
	class ListNode
	{
		public:
			int val;
			ListNode* next;

			ListNode() : val{0}
			{}

			ListNode(int val) : val{val}, next{nullptr}
			{}

			ListNode(int val, ListNode* next) : val{val}, next{next}
			{}
	};

	inline void print_list(const ListNode* list)
	{
		while (list)
			std::cout << std::exchange(list, list->next)->val << ' ';
		std::cout << '\n';
	}

	inline void delete_list(ListNode* list)
	{
		while (list)
			delete std::exchange(list, list->next);
	}
};
