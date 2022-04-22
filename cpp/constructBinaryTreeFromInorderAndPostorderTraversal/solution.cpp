// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		if (postorder.empty())
			return nullptr;
		size_t idx = postorder.size() - 1;
		return build(inorder, 0, inorder.size() - 1, postorder, idx);
	}

private:
	TreeNode* build(const std::vector<int>& inorder, size_t lo, size_t hi,
			const std::vector<int>& postorder, size_t& idx)
	{
		if (lo > hi || hi >= inorder.size())
			return nullptr;

		auto* node = new TreeNode(postorder[idx--]);
		size_t pos = 0;
		while (inorder[pos] != node->val)
			++pos;
		node->right = build(inorder, pos + 1, hi, postorder, idx);
		node->left = build(inorder, lo, pos - 1, postorder, idx);
		return node;
	}
};

int main(int argc, char** argv)
{
}
