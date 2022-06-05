// https://leetcode.com/problems/monotonic-array/

#include <utility>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    bool isMonotonic(vector<int>& nums)
    {
	return two_bools(nums);
    }

private:
    bool cmp_diff(const std::vector<int>& nums)
    {
	long asc = 0;
	for (size_t i = 1; i < nums.size(); ++i) {
	    if (!asc)
		asc = nums[i] - nums[i - 1];
	    else if ((asc > 0 && nums[i] < nums[i - 1]) ||
		    (asc < 0 && nums[i] > nums[i - 1]))
		return false;
	}

	return true;
    }

    bool two_bools(const std::vector<int>& nums)
    {
	bool asc = true;
	bool des = true;
	for (size_t i = 1; i < nums.size(); ++i) {
	    asc &= nums[i] >= nums[i - 1];
	    des &= nums[i] <= nums[i - 1];
	}

	return asc || des;
    }
};

int main(int argc, char** argv)
{
}
