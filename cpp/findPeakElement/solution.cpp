// https://leetcode.com/problems/find-peak-element/

#include <climits>
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
		int findPeakElement(vector<int>& nums)
		{
			return binary_search_rec(nums, 0, nums.size() - 1);
		}

		int binary_search_rec(const vector<int>& nums, int lo, int hi)
		{
			if (lo == hi)
				return lo;

			int md = lo + (hi - lo) / 2;
			if (nums[md] < nums[md + 1])
				return binary_search_rec(nums, md + 1, hi);
			return binary_search_rec(nums, lo, md);
		}
};

int main(int argc, char** argv)
{
}
