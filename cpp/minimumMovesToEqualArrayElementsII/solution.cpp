// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/solution/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    // time: O(nlog(n))
    // space: O(1)
    int minMoves2(vector<int>& nums) 
    {
	return with_median(nums);
    }

private:
    // proof: to equalize min and max to k:
    //	    ==> min + x = k, max - y = k
    //		sum of total moves(x + y) = max - k + (k - min) = max - min,
    //		for every min/max pairs
    int without_median(std::vector<int>& nums)
    {
	std::sort(begin(nums), end(nums));
	auto lo = 0ul;
	auto hi = nums.size() - 1;
	auto sum = 0;
	while (hi < nums.size() && lo < hi)
	    sum += nums[hi--] - nums[lo++];

	return sum;
    }

    int with_median(std::vector<int>& nums)
    {
	std::sort(begin(nums), end(nums));
	auto sum = 0;
	auto median = nums.size() / 2;
	for (auto n : nums)
	    sum += std::abs(nums[median] - n);
	return sum;
    }
};

int main(int argc, char** argv)
{
}
