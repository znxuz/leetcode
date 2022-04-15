// https://leetcode.com/problems/trim-a-binary-search-tree/

#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	TreeNode* trimBST(TreeNode* root, int lo, int hi)
	{
		return rec(root, lo, hi);
	}

private:
	TreeNode* rec(TreeNode* root, int lo, int hi)
	{
		if (!root)
			return root;

		TreeNode* ret;
		root->left = rec(root->left, lo, hi);
		root->right = rec(root->right, lo, hi);
		if (root->val < lo)
			ret = root->right;
		else if (root->val > hi)
			ret = root->left;
		else
			return root;

		// delete root;
		return ret;
	}
};

int main(int argc, char** argv)
{
	TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, nullptr, nullptr));
	auto *res = Solution().trimBST(root, 3, 5);
	inorder(res, [](int i) { std::cout << i << '\n'; });
}
