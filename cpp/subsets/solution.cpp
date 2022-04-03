// https://leetcode.com/problems/subsets/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		return iter(nums);
	}

private:
	std::vector<std::vector<int>> iter(const vector<int>& nums)
	{
		std::vector<std::vector<int>> res{{}};
		for (int n : nums) {
			auto size = res.size();
			for (size_t i = 0; i < size; ++i) {
				res.push_back(res[i]);
				res.back().push_back(n);
			}
		}

		return res;
	}

	void backtrack(const std::vector<int>& nums, size_t idx,
			std::vector<std::vector<int>>& res, std::vector<int>& set)
	{
		res.push_back(set);
		for (size_t i = idx; i < nums.size(); ++i) {
			set.push_back(nums[i]);
			backtrack(nums, i + 1, res, set);
			set.pop_back();
		}
	}
};

int main(int argc, char** argv)
{
}
