// https://leetcode.com/problems/move-zeroes/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		shift(nums);
	}

private:
	void shift(vector<int>& nums)
	{
		size_t i = 0;
		for (size_t j = 0; j < nums.size(); ++j)
			if (nums[j])
				nums[i++] = nums[j];
		while (i < nums.size())
			nums[i++] = 0;
	}

	void swaps(vector<int>& nums)
	{
		size_t i = 0;
		size_t j = 0;
		size_t n = nums.size();
		while (i < n && j < n) {
			if (nums[i])
				++i;
			else if (!nums[j])
				++j;
			else if (i < j)
				std::swap(nums[i], nums[j]), ++i, ++j;
			else
				std::swap(i, j);
		}
	}
};

int main(int argc, char** argv)
{
	std::vector<int> nums {0,1,0,3,12};
	Solution().moveZeroes(nums);
	iter_print(begin(nums), end(nums));
}
