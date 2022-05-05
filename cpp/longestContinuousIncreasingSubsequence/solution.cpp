// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	int findLengthOfLCIS(vector<int>& nums)
	{
	    int cnt = 0;
	    int max = 0;
	    for (size_t i = 0; i < nums.size(); ++i) {
		if (i > 0 && nums[i] <= nums[i - 1])
		    cnt = 0;
		++cnt;
		max = std::max(max, cnt);
	    }

	    return max;
	}
};

int main(int argc, char** argv)
{
}
