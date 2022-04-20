// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <unordered_map>
#include <queue>
#include <queue>
#include <iostream>
#include <vector>

#include "TreeNode.h"
#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		size_t idx = 0;
		std::unordered_map<int, size_t> idx_table;
		for (size_t i = 0; i < inorder.size(); ++i)
			idx_table[inorder[i]] = i;
		return rec_w_map(preorder, idx, 0, static_cast<int>(inorder.size()) - 1, idx_table);
	}

private:
	TreeNode* rec_w_map(const std::vector<int>& preorder, size_t& root_idx,
			int lo, int hi, const std::unordered_map<int, size_t>& idx_table)
	{
		if (lo > hi)
			return nullptr;

		auto* root = new TreeNode(preorder[root_idx++]);

		int idx = static_cast<int>(idx_table.at(root->val));
		root->left = rec_w_map(preorder, root_idx, lo, idx - 1, idx_table);
		root->right = rec_w_map(preorder, root_idx, idx + 1, hi, idx_table);

		return root;
	}

	TreeNode* rec(const std::vector<int>& preorder, size_t idx, const std::vector<int> inorder)
	{
		auto* node = (idx >= preorder.size() ? nullptr : new TreeNode(preorder[idx]));
		if (!node || inorder.size() == 1)
			return node;

		unsigned pos = 0;
		while (preorder[idx] != inorder[pos])
			++pos;

		std::vector<int> left(begin(inorder), begin(inorder) + pos);
		std::vector<int> right(begin(inorder) + pos + 1, end(inorder));
		if (!left.empty())
			node->left = rec(preorder, ++idx, left);
		idx = (left.empty() ? ++idx : idx + left.size());
		if (!right.empty())
			node->right = rec(preorder, idx, right);

		return node;
	}
};

int main(int argc, char** argv)
{
}
