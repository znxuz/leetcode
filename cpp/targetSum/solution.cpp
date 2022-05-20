// https://leetcode.com/problems/target-sum/

#include <numeric>
#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
	int total = std::accumulate(begin(nums), end(nums), 0, std::plus<int>());
	std::vector<std::vector<int>> memoi(nums.size(),
		std::vector<int>(2 * total + 1, std::numeric_limits<int>::min()));

	return memoization(nums, 0, 0, total, target, memoi);
    }

private:
    // time/space: O(t * n) where:
    //	t = sum of the nums array
    //	n = length of the nums array
    int memoization(const std::vector<int>& nums, size_t i, int sum,
	    const int total, int target, std::vector<std::vector<int>>& memo)
    {
	if (i == nums.size())
	    return (sum == target);

	if (memo[i][total + sum] != std::numeric_limits<int>::min())
	    return memo[i][total + sum];

	int add = memoization(nums, i + 1, sum + nums[i], total, target, memo);
	int subtr = memoization(nums, i + 1, sum - nums[i], total, target, memo);
	return memo[i][total + sum] = add + subtr;
    }

    // time: O(2^n)
    // space: O(n)
    void backtrack(const std::vector<int>& nums, size_t idx, int sum,
	    const int target, int& cnt)
    {
	if (idx >= nums.size()) {
	    cnt += (sum == target);
	    return;
	}

	int cur = nums[idx];
	for (size_t i = 0; i < 2; ++i) {
	    cur *= -1;
	    backtrack(nums, idx + 1, sum + cur, target, cnt);
	}
    }
};

int main(int argc, char** argv)
{
}
