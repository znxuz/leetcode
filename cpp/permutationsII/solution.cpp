// https://leetcode.com/problems/permutations-ii/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		vector<vector<int>> res;
		std::sort(begin(nums), end(nums));
		backtrack(nums, nums.size(), 0, res);
		return res;
	}

private:
	// ! pass nums by value
	void backtrack(vector<int> nums, size_t n, size_t idx, vector<vector<int>>& res)
	{
		if (idx + 1 == n) {
			res.push_back(nums);
			return;
		}
		for (size_t i = idx; i < nums.size(); ++i) {
			if (i != idx && nums[i] == nums[idx])
				continue;
			std::swap(nums[i], nums[idx]);
			backtrack(nums, n, idx + 1, res);
		}
	}
};

int main(int argc, char** argv)
{
	vector<int> arr{2, 2, 1, 1};
	const auto& res = Solution().permuteUnique(arr);
	std::for_each(begin(res), end(res), [](const auto& row) { iter_print(begin(row), end(row)); });
}
