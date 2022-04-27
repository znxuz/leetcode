// https://leetcode.com/problems/binary-tree-tilt/

#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int findTilt(TreeNode* root)
	{
		int res = 0;
		rec(root, res);

		return res;
	}

private:
	int rec(TreeNode* root, int& res)
	{
		if (!root)
			return 0;

		int left = rec(root->left, res);
		int right = rec(root->right, res);
		res += std::abs(left - right);
		return left + right + root->val;
	}

	// time: O(n)
	// space: O(n)
	int hashmap(const TreeNode* root)
	{
		if (!root)
			return 0;

		int left = hashmap(root->left);
		int right = hashmap(root->right);
		int left_sum = 0;
		int right_sum = 0;
		if (root->left)
			left_sum = sum[root->left];
		if (root->right)
			right_sum = sum[root->right];
		sum[root] = left_sum + right_sum + root->val;
		return left + right + std::abs(left_sum - right_sum);
	}

private:
	std::unordered_map<const TreeNode*, int> sum;
};

int main(int argc, char** argv)
{
}
