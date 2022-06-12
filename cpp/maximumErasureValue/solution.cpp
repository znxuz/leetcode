// https://leetcode.com/problems/maximum-erasure-value/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
	return counting_sort_sliding(nums);
    }

private:
    // time: O(n)
    // space: O(1)
    int counting_sort_sliding(const std::vector<int>& nums)
    {
	auto flags = std::array<int, 10001>();
	int max = 0;
	int sum = 0;
	for (size_t i = 0, j = 0; j < nums.size(); ++j) {
	    sum += nums[j];
	    while (flags[nums[j]]) {
		sum -= nums[i];
		flags[nums[i++]] = false;
	    }
	    flags[nums[j]] = true;
	    max = std::max(max, sum);
	}

	return max;
    }

    // time: O(n)
    // space: O(n)
    int sliding_window(const std::vector<int>& nums)
    {
	int max = 0;
	int sum = 0;
	std::unordered_map<int, size_t> idx_mp;
	for (size_t i = 0, j = 0; j < nums.size(); ++j) {
	    sum += nums[j];
	    if (idx_mp.count(nums[j])) {
		size_t end = idx_mp[nums[j]];
		while (i <= end) {
		    idx_mp.erase(nums[i]);
		    sum -= nums[i++];
		}
	    }
	    max = std::max(max, sum);
	    idx_mp[nums[j]] = j;
	}

	return max;
    }
};

int main(int argc, char** argv)
{
}
