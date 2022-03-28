// https://leetcode.com/problems/permutations/

#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> res;
		backtrack_swap(nums, nums.size(), 0, res);
		// backtrack_set(nums, unordered_set<int>{}, res, {});
		return res;
	}

private:
	void backtrack_swap(vector<int>& nums, size_t n, size_t idx, vector<vector<int>>& res)
	{
		if (idx == n)
			res.push_back(nums);
		for (size_t i = idx; i < n; ++i) {
			std::swap(nums[idx], nums[i]);
			backtrack_swap(nums, n, idx + 1, res);
			std::swap(nums[idx], nums[i]);
		}
	}

	void backtrack_set(const vector<int>& nums, unordered_set<int> visited, vector<vector<int>>& res, vector<int> cmb)
	{
		if (cmb.size() == nums.size()) {
			res.push_back(std::move(cmb));
			return;
		}

		for (size_t i = 0; i < nums.size(); ++i) {
			if (visited.insert(nums[i]).second) {
				cmb.push_back(nums[i]);
				backtrack_set(nums, visited, res, cmb);
				cmb.pop_back();
				visited.erase(nums[i]);
			}
		}
	}
};

int main(int argc, char** argv)
{
}
