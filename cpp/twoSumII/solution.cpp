// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
	return binary_search_two_ptr(nums, target);
    }

private:
    // time: O(log(n))
    // space: O(1)
    std::vector<int> binary_search_two_ptr(const std::vector<int>& nums, int target)
    {
	size_t lo = 0;
	size_t hi = nums.size() - 1;

	while (hi < nums.size() && lo < hi) {
	    size_t md = lo + (hi - lo) / 2;
	    int sum = nums[lo] + nums[hi];
	    if (sum == target)
		return {static_cast<int>(lo + 1), static_cast<int>(hi + 1)};
	    if (sum < target)
		lo = (nums[md] + nums[hi] < target ? md + 1 : lo + 1);
	    else
		hi = (nums[lo] + nums[md] > target ? md - 1 : hi - 1);
	}

	return {};
    }

    // time: O(n)
    // space: O(1)
    std::vector<int> two_ptr(const std::vector<int>& nums, int target)
    {
	size_t lo = 0;
	size_t hi = nums.size() - 1;

	while (hi < nums.size() && lo < hi) {
	    int sum = nums[lo] + nums[hi];
	    if (sum == target)
		return {static_cast<int>(lo + 1), static_cast<int>(hi + 1)};
	    if (sum < target)
		++lo;
	    else
		--hi;
	}

	return {};
    }

    std::vector<int> extra_space(const std::vector<int>& nums, int target)
    {
	std::unordered_map<int, size_t> indices;
	for (size_t i = 0; i < nums.size(); ++i) {
	    int cmpl = target - nums[i];
	    if (indices.count(cmpl))
		return {static_cast<int>(indices[cmpl] + 1), static_cast<int>(i + 1)};
	    indices[nums[i]] = i;
	}

	return {};
    }

};

int main(int argc, char** argv)
{
}
