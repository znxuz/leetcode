// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    bool isMajorityElement(vector<int> &nums, int target)
    {
	return one_bsearch(nums, target);
    }

private:
    bool one_bsearch(const std::vector<int> &nums, int target)
    {
	auto lo = 0ul;
	auto hi = size(nums) - 1;
	while (lo < hi) {
	    auto md = lo + (hi - lo) / 2;
	    if (nums[md] < target)
		lo = md + 1;
	    else
		hi = md;
	}
	lo += size(nums) / 2;
	return lo < size(nums) && nums[lo] == target;
    }

    bool two_bsearches(const std::vector<int> &nums, int target)
    {
	auto lo = 0ul;
	auto hi = nums.size() - 1;
	while (lo < hi) {
	    auto md = lo + (hi - lo) / 2;
	    if (nums[md] < target)
		lo = md + 1;
	    else
		hi = md;
	}
	if (lo >= nums.size() || nums[lo] != target)
	    return false;

	auto first = lo;
	lo = 0;
	hi = nums.size() - 1;
	while (lo < hi) {
	    auto md = lo + (hi - lo) / 2;
	    if (nums[md] <= target)
		lo = md + 1;
	    else
		hi = md;
	}
	return lo - first + 1 > nums.size() / 2;
    }

    bool built_in(const std::vector<int> &nums, int target)
    {
	auto [first, last] = std::equal_range(begin(nums), end(nums), target);
	return static_cast<size_t>(last - first) > nums.size() / 2;
    }
};

int main(int argc, char **argv)
{
    auto vec = std::vector<int>{10,100,101,101};
    std::cout << Solution().isMajorityElement(vec, 101) << '\n';
}
