// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		vector<int> searchRange(vector<int>& nums, int target)
		{
			int left_most = -1;
			int right_most = -1;

			if (nums.size() == 0)
				return {left_most, right_most};

			int lo = 0;
			int hi = nums.size() - 1;
			while (lo < hi - 1) {
				int md = lo + (hi - lo) / 2;
				if (nums[md] >= target)
					hi = md;
				else
					lo = md;
			}
			left_most = (nums[lo] == target ? lo : nums[hi] == target ? hi : -1);

			lo = 0;
			hi = nums.size() - 1;
			while (lo < hi - 1) {
				int md = lo + (hi - lo) / 2;
				if (nums[md] <= target)
					lo = md;
				else
					hi = md;
			}
			right_most = (nums[hi] == target ? hi : nums[lo] == target ? lo : -1);

			return {left_most, right_most};
		}
};

int main(int argc, char** argv)
{
	Solution s;
	vector<int> nums {1};
	auto range = s.searchRange(nums, 0);
	v_print(range);
}
