// https://leetcode.com/problems/3sum-smaller/

#include <algorithm>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    // time: O(n^2)
    // space: O(1)
    int threeSumSmaller(vector<int>& nums, int target) 
    {
	if (nums.size() < 3)
	    return 0;

	int cnt = 0;
	std::sort(begin(nums), end(nums));
	for (auto i = 1ul; i < nums.size() - 1; ++i) {
	    for (auto j = i + 1; j < nums.size(); ++j) {
		auto sum = nums[i] + nums[j];
		auto k = i - 1;
		while (k < nums.size() && sum + nums[k] >= target)
		    --k;
		if (!(k < nums.size()))
		    break;
		cnt += k + 1;
	    }
	}

	return cnt;
    }
};

int main(int argc, char** argv)
{
}
