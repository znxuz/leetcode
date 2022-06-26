// https://leetcode.com/problems/find-the-duplicate-number/

#include <algorithm>
#include <numeric>

#include "helper.h"

using namespace std;
using namespace util;

// unqualified solutions:
//  - set
//  - map
//  - negative marking modify array
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
	return floyd_cycle_detect(nums);
    }

private:
    int floyd_cycle_detect(const std::vector<int>& nums)
    {
	auto slow = nums[0];
	auto fast = nums[0];
	do {
	    slow = nums[slow], fast = nums[nums[fast]];
	} while (slow != fast);

	slow = nums[0];
	while (slow != fast)
	    slow = nums[slow], fast = nums[fast];
	return slow;
    }

    // time: O(nlog(n))
    // space: O(1)
    int bsearch(const std::vector<int>& nums)
    {
	auto less_eq_count = [&nums](size_t x) {
	    return std::count_if(begin(nums), end(nums),
		    [x] (int n) { return n <= x; });
	};

	auto lo = 1ul;
	auto hi = nums.size()- 1;
	auto dup = 0ul;
	while (lo <= hi) {
	    auto md = lo + (hi - lo) / 2;
	    if (less_eq_count(md) <= md)
		lo = md + 1;
	    else
		dup = md, hi = md - 1;
	}
	return dup;
    }
};

int main(int argc, char** argv)
{
}
