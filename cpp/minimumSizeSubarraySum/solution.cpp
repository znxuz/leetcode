// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
	return sliding_window(target, nums);
    }

private:
    // time: O(n)
    // space: O(1)
    int sliding_window(int target, const std::vector<int>& nums)
    {
	size_t n = nums.size();
	size_t min = n + 1;
	for (size_t i = 0, j = 0; j < nums.size(); ++j) {
	    target -= nums[j];
	    while (target <= 0) {
		min = std::min(min, j + 1 - i);
		target += nums[i++];
	    }
	}

	return min % (n + 1);
    }
};

int main(int argc, char** argv)
{
    std::vector<int> arr{1, 1, 1};
    std::cout << Solution().minSubArrayLen(11, arr);
}
