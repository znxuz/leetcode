// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"
#include "TreeNode.h"

using namespace std;

class Solution
{
	public:
		TreeNode* sortedArrayToBST(vector<int>& nums)
		{
			return rec(nums, 0, nums.size() - 1);
		}

		TreeNode* rec(const vector<int>& nums, int lo, int hi)
		{
			if (lo > hi)
				return nullptr;

			int md = lo + (hi - lo) / 2;
			auto* head = new TreeNode{nums[md]};
			head->left = rec(nums, lo, md - 1);
			head->right = rec(nums, md + 1, hi);

			return head;
		}
};

int main(int argc, char** argv)
{
}
