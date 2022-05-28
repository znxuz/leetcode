// https://leetcode.com/problems/house-robber/

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
	return dp(nums);
    }

private:
    int dp(const std::vector<int>& nums)
    {
	if (nums.empty() || nums.size() == 1)
	    return nums.back();

	size_t n = nums.size();
	std::vector<int> dp(n);
	for (size_t i = 0; i < n; ++i) {
	    dp[i] = nums[i];
	    if (i < 2)
		continue;
	    int prev = dp[i - 2];
	    if (i >= 3)
		prev = std::max(prev, dp[i - 3]);
	    dp[i] += prev;
	}

	return std::max(dp[n - 1], dp[n - 2]);
    }
};

int main(int argc, char** argv)
{
}
