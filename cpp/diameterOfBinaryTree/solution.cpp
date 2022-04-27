// https://leetcode.com/problems/diameter-of-binary-tree/

#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int diameterOfBinaryTree(TreeNode* root)
	{
		int max = 0;
		rec(root, max);
		return max;
	}

private:
	int rec(const TreeNode* root, int& max)
	{
		if (!root)
			return 0;
		int left = rec(root->left, max);
		int right = rec(root->right, max);
		max = std::max(max, left + right);
		return std::max(left, right) + 1;
	}
};

int main(int argc, char** argv)
{
}
