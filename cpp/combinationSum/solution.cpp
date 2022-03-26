// https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		return rec(candidates, target);
	}

private:
	// n = candicates.size()
	// t = target
	// m = minimum value of candidates
	// TIME: O(n^{t/m+1})
	// space: O(t/m)
	std::vector<std::vector<int>> rec(std::vector<int>& nums, int target)
	{
		std::vector<std::vector<int>> res;
		backtrack(nums, 0, res, {}, target);
		return res;
	}

	void backtrack(std::vector<int>& nums, size_t i,
			std::vector<std::vector<int>>& res, std::vector<int> cmb, int target)
	{
		if (target <= 0) {
			if (target == 0)
				res.push_back(cmb);
			return;
		}

		while (i < nums.size()) {
			cmb.push_back(nums[i]);
			backtrack(nums, i, res, cmb, target - nums[i]);
			cmb.pop_back();
			++i;
		}
	}
};

int main(int argc, char** argv)
{
	Solution s;
	vector<int> arr{2, 3, 5};
	int target = 8;
	const auto res = s.combinationSum(arr, target);
	for_each(begin(res), end(res), [](const auto& row) { iter_print(begin(row), end(row)); });
}
