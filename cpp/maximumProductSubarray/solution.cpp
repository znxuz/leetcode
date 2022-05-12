// https://leetcode.com/problems/maximum-product-subarray/

#include <algorithm>
#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
	if (nums.empty())
	    return 0;

	int max = nums.front();
	int min = nums.front();
	int res = max;
	for (size_t i = 1; i < nums.size(); ++i) {
	    int cur_max = std::max(nums[i], std::max(max * nums[i], min * nums[i]));
	    min = std::min(nums[i], std::min(max * nums[i], min * nums[i]));
	    max = cur_max;
	    res = std::max(res, max);
	}

	return res;
    }
};

int main(int argc, char** argv)
{
    std::vector<int> vec1{-2, 0, -1};
    std::vector<int> vec2{-2, 3, -4};
    std::cout << Solution().maxProduct(vec1) << '\n';
    std::cout << Solution().maxProduct(vec2) << '\n';
}
