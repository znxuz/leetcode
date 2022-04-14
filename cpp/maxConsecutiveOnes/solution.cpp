// https://leetcode.com/problems/max-consecutive-ones/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int findMaxConsecutiveOnes(vector<int>& nums)
	{
		return rec(nums, 0, 0, 0);
	}

private:
	int rec(const std::vector<int>& nums, size_t idx, size_t max, size_t cnt)
	{
		if (idx == nums.size())
			return max;
		cnt = (nums[idx] == 1 ? ++cnt : 0);
		return rec(nums, ++idx, std::max(max, cnt), cnt);
	}

	int iter(const std::vector<int>& nums)
	{
		size_t max = 0;
		size_t cnt = 0;
		for (auto n : nums) {
			cnt = (n == 1 ? ++cnt : 0);
			max = std::max(max, cnt);
		}

		return max;
	}
};

int main(int argc, char** argv)
{
}
