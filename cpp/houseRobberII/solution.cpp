// https://leetcode.com/problems/house-robber-ii/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
	if (nums.empty())
	    return 0;
	if (nums.size() == 1)
	    return nums.front();
	return std::max(rob_range(nums, 0, nums.size() - 2),
		rob_range(nums, 1, nums.size() - 1));
    }

private:
    int rob_range(const std::vector<int>& nums, size_t lo, size_t hi)
    {
	int prev1 = 0;
	int prev2 = 0;
	while (lo <= hi) {
	    int tmp = prev1;
	    prev1 = std::max(nums[lo++] + prev2, prev1);
	    prev2 = tmp;
	}

	return prev1;
    }
};

int main(int argc, char** argv)
{
    std::vector<int> houses1{1, 2, 3};
    std::vector<int> houses2{1, 3, 1, 3, 100};
    std::vector<int> houses3{2, 1, 1, 2};
    std::cout << Solution().rob(houses1) << '\n';
    std::cout << Solution().rob(houses2) << '\n';
    std::cout << Solution().rob(houses3) << '\n';
}
