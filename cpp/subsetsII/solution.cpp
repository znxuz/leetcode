// https://leetcode.com/problems/subsets-ii/

#include <iterator>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		return rec(nums);
	}

private:
	std::vector<std::vector<int>> rec(vector<int>& nums)
	{
		using std::begin, std::end;
		std::sort(begin(nums), end(nums));
		std::vector<std::vector<int>> res;
		std::vector<int> cmb;
		backtrack(nums, 0, res, cmb);
		return res;
	}

	void backtrack(const std::vector<int>& nums, size_t idx,
			std::vector<std::vector<int>>& res, std::vector<int>& cmb)
	{
		res.push_back(cmb);
		for (size_t i = idx; i < nums.size(); ++i) {
			if (i != idx && nums[i] == nums[i - 1])
				continue;
			cmb.push_back(nums[i]);
			backtrack(nums, i + 1, res, cmb);
			cmb.pop_back();
		}
	}
};

int main(int argc, char** argv)
{
	std::vector<int> nums{0};
	const auto res = Solution().subsetsWithDup(nums);
	std::cout << "res size: " << res.size() << '\n';
	for (const auto& row : res)
		iter_print(std::begin(row), std::end(row));
}
