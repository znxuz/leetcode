// https://leetcode.com/problems/recover-binary-search-tree/

#include <random>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	void recoverTree(TreeNode* root)
	{
		return extra_space(root);
	}

	// time: O(n)
	// space: O(n)
	void extra_space(TreeNode* root)
	{
		std::vector<TreeNode*> vec;
		inorder(root, vec);
		swap_val(vec);
	}

	void inorder(TreeNode* root, std::vector<TreeNode*>& vec)
	{
		if (!root)
			return;

		inorder(root->left, vec);
		vec.push_back(root);
		inorder(root->right, vec);
	}

	void swap_val(const std::vector<TreeNode*>& vec)
	{
		if (!vec.size())
			return;

		size_t i = 0;
		size_t j = vec.size() - 1;
		while (i < j) {
			if (vec[i]->val < vec[i + 1]->val) {
				++i;
			} else if (vec[j]->val > vec[j - 1]->val) {
				--j;
			} else {
				std::swap(vec[i++]->val, vec[j--]->val);
				break;
			}
		}
	}
};

void swap(std::vector<int>& vec)
{
	if (!vec.size())
		return;

	size_t i = 0;
	size_t j = vec.size() - 1;
	while (i < j) {
		if (vec[i] < vec[i + 1])
			++i;
		else if (vec[j] > vec[j - 1])
			--j;
		else
			std::swap(vec[i++], vec[j--]);
	}
}


bool is_sorted(const std::vector<int>& vec)
{
	for (size_t i = 1; i < vec.size(); ++i)
		if (vec[i] < vec[i - 1])
			return false;
	return true;
}

void test(std::vector<int>& vec)
{
	std::mt19937 mt;
	size_t i, j;
	i = mt() % vec.size();
	do {
		j = mt() % vec.size();
	} while (i == j);

	std::swap(vec[i], vec[j]);
	::swap(vec);

	if (!is_sorted(vec))
		std::cout << "ERROR\n";
}

int main(int argc, char** argv)
{
	std::mt19937 mt;
	for (size_t i = 0; i < 1000; ++i) {
		size_t size = mt() % 10 + 3;
		std::vector<int> vec(size);
		for (size_t j = 0; j < size; ++j)
			vec[j] = static_cast<int>(j);
		test(vec);
	}
}
