// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int dominantIndex(vector<int>& nums)
    {
	size_t max1 = -1;
	size_t max2 = -1;
	size_t n = nums.size();
	for (size_t i = 0; i < nums.size(); ++i) {
	    if (max1 >= n) {
		max1 = i;
	    } else if (max2 >= n) {
		max2 = max1;
		max1 = (nums[i] > nums[max1] ? i : max1);
		max2 = (max2 == max1 ? i : max2);
	    } else if (nums[i] >= nums[max1]) {
		max2 = max1;
		max1 = i;
	    } else if (nums[i] > nums[max2]) {
		max2 = i;
	    }
	}

	return (max2 < n && nums[max2] * 2 > nums[max1] ? -1 : max1);
    }
};

int main(int argc, char** argv)
{
}
