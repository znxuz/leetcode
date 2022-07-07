// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

#include <numeric>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    // time: O(nlog(n))
    // space: O(n)
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
	std::sort(begin(nums), end(nums));
	auto bound = begin(nums);
	while (bound != end(nums) && *bound < 0)
	    ++bound;

	for (auto i = begin(nums); i != bound && k; ++i, --k)
	    *i *= -1;
	if (k & 1) {
	    std::sort(begin(nums), end(nums));
	    nums.front() *= -1;
	}
	return std::accumulate(begin(nums), end(nums), 0, std::plus<int>());
    }
};

template<typename... types>
void test(types&&... args)
{
    std::cout <<
	Solution().largestSumAfterKNegations(std::forward<types>(args)...) <<
	'\n';
}

int main(int argc, char** argv)
{
    auto nums1 = std::vector<int>{2,-3,-1,5,-4};
    test(nums1, 2);
    auto nums2 = std::vector<int>{-8,3,-5,-3,-5,-2};
    test(nums2, 6);
}
