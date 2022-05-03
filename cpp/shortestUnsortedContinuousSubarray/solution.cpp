// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	// time: O(n)
	int findUnsortedSubarray(vector<int>& nums)
	{
	    return sort(nums);
	}

    private:
	int optimal(const std::vector<int>& nums)
	{
	    size_t n = nums.size();

	    size_t lo = 0;
	    while (lo + 1 < n) {
		if (nums[lo + 1] < nums[lo])
		    break;
		++lo;
	    }
	    size_t hi = n - 1;
	    while (hi - 1 < n) {
		if (nums[hi - 1] > nums[hi])
		    break;
		--hi;
	    }
	    if (lo >= hi)
		return 0;

	    int min = std::numeric_limits<int>::max();
	    int max = std::numeric_limits<int>::min();
	    while (lo <= hi) {
		min = std::min(min, nums[lo]);
		max = std::max(max, nums[lo]);
		++lo;
	    }

	    lo = 0, hi = n - 1;
	    while (nums[lo] <= min || nums[hi] >= max) {
		if (nums[lo] <= min)
		    ++lo;
		if (nums[hi] >= max)
		    --hi;
	    }

	    return hi - lo + 1;
	}

	// time: O(n * log(n))
	// space: O(n)
	int sort(const std::vector<int>& nums)
	{
	    auto sorted = nums;
	    std::sort(begin(sorted), end(sorted));
	    size_t lo = 0;
	    size_t hi = nums.size() - 1;
	    while (lo < hi) {
		if (nums[lo] == sorted[lo])
		    ++lo;
		else if (nums[hi] == sorted[hi])
		    --hi;
		else
		    break;
	    }
	    return (hi == lo ? 0 : hi - lo + 1);
	}
};

int main(int argc, char** argv)
{
    Solution s;
    std::vector<int> vec1{2,6,4,8,10,9,15};
    std::cout << s.findUnsortedSubarray(vec1) << '\n';
    std::vector<int> vec2{1, 3, 2, 3, 3};
    std::cout << s.findUnsortedSubarray(vec2) << '\n';
}
