// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		return binary_search_rec(nums, target, 0, nums.size() - 1);
	}

	int binary_search_rec(const vector<int>& nums, int t, int lo, int hi)
	{
		if (lo > hi)
			return false;

		while (lo + 1 < hi && nums[lo + 1] == nums[lo])
			++lo;
		while (hi - 1 > lo && nums[hi - 1] == nums[hi])
			--hi;

		auto md = lo + (hi - lo) / 2;
		if (nums[md] == t)
			return true;
		if (nums[md] >= nums[lo]) {
			if (t < nums[md] && t >= nums[lo])
				return binary_search_rec(nums, t, lo, md - 1);
			return binary_search_rec(nums, t, md + 1, hi);
		} else {
			if (t > nums[md] && t <= nums[hi])
				return binary_search_rec(nums, t, md + 1, hi);
			return binary_search_rec(nums, t, lo, md - 1);
		}
	}
};

int main(int argc, char** argv)
{
	std::vector<int> nums{5, 6, 7, 8};
	std::cout << Solution().search(nums, 3) << '\n';
}
