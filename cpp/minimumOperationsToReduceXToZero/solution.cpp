// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <numeric>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int minOperations(vector<int>& nums, int x) 
    {
	return sliding_window(nums, x);
    }

private:
    int sliding_window(const std::vector<int>& nums, int x)
    {
	int total = std::accumulate(begin(nums), end(nums), 0, std::plus<int>());
	int min = std::numeric_limits<int>::max();
	for (size_t lo = 0, hi = 0; hi < nums.size(); ++hi) {
	    total -= nums[hi];
	    while (total < x && lo <= hi)
		total += nums[lo++];

	    if (total == x)
		min = std::min(min, static_cast<int>(nums.size() - 1 - hi + lo));
		// nums.size() - 1 - hi: count of all nums after idx hi
		// + lo: all nums before idx lo
	}

	return min == std::numeric_limits<int>::max() ? -1 : min;
    }
};

int main(int argc, char** argv)
{
    std::vector<int> vec1{3, 2, 20, 1, 1, 3};
    std::vector<int> vec2{5, 2, 3, 1, 1};
    std::cout << Solution().minOperations(vec1, 10) << '\n';
    std::cout << Solution().minOperations(vec2, 10) << '\n';
}
