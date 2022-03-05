// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <algorithm>
#include <functional>
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
		int search(vector<int>& nums, int target)
		{
			return binary_search_rec(nums, target, 0, nums.size() - 1);
		}

		int binary_search_iter(vector<int>& nums, int target)
		{
			int start = 0, end = nums.size() - 1;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (nums[mid] == target)
					return mid;
				if (nums[mid] >= nums[start]) {
					if (target >= nums[start] && target < nums[mid])
						end = mid - 1;
					else
						start = mid + 1;
				} else {
					if (target <= nums[end] && target > nums[mid])
						start = mid + 1;
					else
						end = mid - 1;
				}
			}

			return -1;
		}

		int binary_search_rec(const vector<int>& nums, int target, int lo, int hi)
		{
			if (lo > hi)
				return -1;

			int md = lo + (hi - lo) / 2;
			if (target == nums[md])
				return md;
			if (nums[md] >= nums[lo]) {
				if (target >= nums[lo] && target <= nums[md])
					return binary_search_rec(nums, target, lo, md - 1);
				return binary_search_rec(nums, target, md + 1, hi);
			} else {
				if (target <= nums[hi] && target >= nums[md])
					return binary_search_rec(nums, target, md + 1, hi);
				return binary_search_rec(nums, target, lo, md - 1);
			}
		}
};

void shift(vector<int>& nums)
{
	int tmp = nums[0];
	for (int i = 0; i < nums.size(); ++i)
		nums[i] = nums[(i + 1) % nums.size()];
	nums[nums.size() - 1] = tmp;
}

int main(int argc, char** argv)
{
	Solution s;
	vector<int> nums {0, 1, 2, 3, 4};
	for (int i = 0; i < 5; ++i) {
		shift(nums);
		v_print(nums);
		for (int j = 0; j < nums.size(); ++j)
			cout << "find " << j << ", idx: " << s.search(nums, j) << '\n';
	}
}
