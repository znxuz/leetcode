// https://leetcode.com/problems/two-sum-less-than-k/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int twoSumLessThanK(vector<int>& nums, int k) 
    {
	return srt_bsearch(nums, k);
    }

private:
    // time: O(nlog(n))
    // space: O(nlog(n))
    int srt_bsearch(std::vector<int>& nums, int k)
    {
	std::sort(begin(nums), end(nums));
	auto max = -1;
	for (auto i = 0ul; i < nums.size(); ++i) {
	    auto lo = 0ul;
	    auto hi = i - 1;
	    while (hi < nums.size() && lo <= hi) {
		auto md = lo + (hi - lo) / 2;
		auto sum = nums[md] + nums[i];
		if (sum < k) {
		    max = std::max(max, sum);
		    lo = md + 1;
		} else {
		    hi = md - 1;
		}
		// std::lower_bound
		// or two pointer O(n)
	    }
	}

	return max;
    }
};

int main(int argc, char** argv)
{
}
