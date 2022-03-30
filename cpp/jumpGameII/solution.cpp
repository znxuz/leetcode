// https://leetcode.com/problems/jump-game-ii/

#include <iostream>
#include <limits>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int jump(vector<int>& nums)
	{
		return dp(nums);
	}

private:
	// TIME: O(n^2)
	// SPACE: O(n)
	int dp(const vector<int>& nums)
	{
		size_t n = nums.size();

		vector<int> jumps(n, std::numeric_limits<int>::max());
		jumps[0] = 0;
		for (size_t i = 0; i < n; ++i) {
			size_t max_reach = std::min(n - 1, i + nums[i]);
			for (size_t j = i + 1; j <= max_reach; ++j)
				jumps[j] = std::min(jumps[j], jumps[i] + 1);
		}

		return jumps.back();
	}
};

int main(int argc, char** argv)
{
	vector<int> arr{2, 3, 0, 1, 4};
	std::cout << Solution().jump(arr) << '\n';
}
