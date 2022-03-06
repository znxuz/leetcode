// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <string>
#include <vector>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		int findMin(vector<int>& nums)
		{
			return binary_search(nums, 0, nums.size() - 1);
		}

		int binary_search(vector<int>& nums, int lo, int hi)
		{
			if (lo == hi)
				return nums[lo];
			if (nums[lo] < nums[hi])
				return nums[lo];

			int md = lo + (hi - lo) / 2;
			if (nums[md] < nums[hi])
				return binary_search(nums, lo, md);
			return binary_search(nums, md + 1, hi);
		}
};

int main(int argc, char** argv)
{
	Solution s;
	vector<int> nums {3, 4, 5, 1, 2};

	cout << s.findMin(nums) << '\n';
}
