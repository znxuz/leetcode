// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		size_t size = get_list_size(head);
		return inorder_traverse(0, size - 1, size, &head);
	}

private:
	// time: O(n)
	// space:  O(H) = O(log(n))
	TreeNode* inorder_traverse(size_t lo, size_t hi, size_t size, ListNode** head)
	{
		if (lo > hi || hi >= size)
			return nullptr;

		size_t md = lo + (hi - lo) / 2;
		TreeNode* left = inorder_traverse(lo, md - 1, size, head);
		TreeNode* root = new TreeNode(std::exchange(*head, (*head)->next)->val);
		root->left = left;
		root->right = inorder_traverse(md + 1, hi, size, head);
		return root;
	}

	size_t get_list_size(const ListNode* head)
	{
		if (!head)
			return 0;
		return 1 + get_list_size(head->next);
	}

	// time: O(n)
	// space: O(n)
	TreeNode* list_to_vec(ListNode* head)
	{
		std::vector<int> vec;
		while (head)
			vec.push_back(std::exchange(head, head->next)->val);
		return build_tree(vec, 0, vec.size() - 1);
	}

	TreeNode* build_tree(const vector<int>& vec, size_t lo, size_t hi)
	{
		if (lo > hi || hi >= vec.size())
			return nullptr;

		size_t md = lo + (hi - lo) / 2;
		TreeNode* root = new TreeNode(vec[md]);
		root->left = build_tree(vec, lo, md - 1);
		root->right = build_tree(vec, md + 1, hi);
		return root;
	}
};

int main(int argc, char** argv)
{
}
