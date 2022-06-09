// https://leetcode.com/problems/smallest-range-i/

#include <limits>
#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int smallestRangeI(vector<int>& nums, int k)
    {
	return built_in_minmax(nums, k);
    }

private:
    int built_in_minmax(const std::vector<int>& nums, int k)
    {
	auto [min, max] = std::minmax_element(begin(nums), end(nums));
	return std::max(0, *max - *min - k * 2);
    }
};

int main(int argc, char** argv)
{
    std::vector<int> vec{0, 10};
    std::cout << Solution().smallestRangeI(vec, 2) << '\n';
}
