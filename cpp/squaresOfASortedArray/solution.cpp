// https://leetcode.com/problems/squares-of-a-sorted-array/

#include <cmath>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
	return use_lower_bound(nums);
    }

private:
    // time: O(nlog(n))
    // space: O(1)
    auto use_lower_bound(const std::vector<int>& nums) -> std::vector<int>
    {
	auto res = std::vector<int>();
	for (auto elem : nums) {
	    auto squared = static_cast<int>(std::pow(elem, 2));
	    auto inserter = std::lower_bound(begin(res), end(res), squared);
	    res.insert(inserter, squared);
	}

	return res;
    }

    // time: O(nlog(n))
    // space: O(n)
    auto use_transform(const std::vector<int>& nums) -> std::vector<int>
    {
	auto res = std::vector<int>(size(nums));
	std::transform(begin(nums), end(nums), begin(res),
		[](auto elem) { return static_cast<int>(std::pow(elem, 2)); });
	std::sort(begin(res), end(res));
	return res;
    }

    // time: O(n)
    // space: O(1)
    auto two_ptrs_improved(const std::vector<int>& nums) -> std::vector<int>
    {
	auto n = nums.size();
	auto lo = 0ul;
	auto hi = n - 1;
	auto res = std::vector<int>(n);
	for (auto i = n - 1; i < res.size(); --i) {
	    auto to_square = 0;
	    if (std::abs(nums[lo]) >= std::abs(nums[hi]))
		to_square = nums[lo++];
	    else
		to_square = nums[hi--];
	    res[i] = static_cast<int>(std::pow(to_square, 2));
	}
	return res;
    }

    auto two_ptrs(const std::vector<int>& nums) -> std::vector<int>
    {
	auto n = nums.size();
	auto res = std::vector<int>(n);
	auto i = 0ul;
	auto bound = 0ul;
	while (bound < n && nums[bound] < 0)
	    ++bound;
	auto neg = bound - 1;
	auto pos = bound;
	while (neg < n && pos < n) {
	    if (!nums[pos])
		res[i++] = 0, ++pos;
	    else if (std::abs(nums[neg]) < nums[pos])
		res[i++] = static_cast<int>(std::pow(nums[neg--], 2));
	    else
		res[i++] = static_cast<int>(std::pow(nums[pos++], 2));
	}
	while (neg < n)
	    res[i++] = static_cast<int>(std::pow(nums[neg--], 2));
	while (pos < n)
	    res[i++] = static_cast<int>(std::pow(nums[pos++], 2));
	return res;
    }
};

int main(int argc, char** argv)
{
    auto vec = std::vector<int>{-4, -1, 0, 3, 10};
    print_container(Solution().sortedSquares(vec));
}
