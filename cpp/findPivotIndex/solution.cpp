// https://leetcode.com/problems/find-pivot-index/

#include <numeric>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	int pivotIndex(vector<int>& nums)
	{
	    return two_passes(nums);
	}

    private:
	int two_passes(const std::vector<int>& nums)
	{
	    int sum = std::accumulate(begin(nums), end(nums), 0, std::plus<int>());
	    int left = 0;
	    for (size_t i = 0; i < nums.size(); ++i) {
		if (left == (sum -= nums[i]))
		    return static_cast<int>(i);
		left += nums[i];
	    }

	    return -1;
	}
};

int main(int argc, char** argv)
{
}
