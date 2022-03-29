// https://leetcode.com/problems/jump-game/

#include <ios>
#include <iostream>
#include <limits>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		return improved_greedy(nums);
	}

private:
	// backtrack TLE

	// TIME: O(n)
	// space: O(1)
	bool improved_greedy(const vector<int>& nums)
	{
        size_t len = nums.size();
        size_t max = 0;
        for(size_t i = 0; i <= max; ++i) {
            max = std::max(max, i + static_cast<size_t>(nums[i]));
			if (max + 1 >= len)
				return true;
        }
        return false;
	}

	// TIME: O(n)
	// SPACE: O(1)
	bool greedy_rec(const vector<int>& nums, size_t idx)
	{
		size_t steps = static_cast<size_t>(nums[idx]);
		if (idx + 1 >= nums.size() || idx + 1 + steps >= nums.size())
			return true;

		size_t max = 0;
		for (size_t i = idx + 1, limit = idx + steps; i <= limit; ++i) {
			if (max <= static_cast<size_t>(nums[i])) {
				max = static_cast<size_t>(nums[i]);
				idx = i;
			} else if (nums[i] == 0 && idx + max == i) {
				max = 0;
			}
		}
		return (max == 0 ? false : greedy_rec(nums, idx));
	}
};

int main(int argc, char** argv)
{
	vector<int> arr1{4, 2, 0, 0, 1, 1, 4, 4, 4, 0, 4, 0};
	vector<int> arr{5,9,3,2,1,0,2,3,3,1,0,0};
	std::cout << std::boolalpha << Solution().canJump(arr1) << '\n';
}
