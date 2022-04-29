// https://leetcode.com/problems/maximum-product-of-three-numbers/

#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int maximumProduct(vector<int>& nums)
	{
		return one_pass(nums);
	}

private:
	int one_pass(const std::vector<int>& nums)
	{
		int min1, min2;
		int max1, max2, max3;
		min1 = min2 = std::numeric_limits<int>::max();
		max1 = max2 = max3 = std::numeric_limits<int>::min();
		for (int n : nums) {
			if (n < min1) {
				min2 = min1;
				min1 = n;
			} else if (n < min2) {
				min2 = n;
			}
			if (n > max1) {
				max3 = max2;
				max2 = max1;
				max1 = n;
			} else if (n > max2) {
				max3 = max2;
				max2 = n;
			} else if (n > max3) {
				max3 = n;
			}
		}

		return std::max(min1 * min2 * max1, max1 * max2 * max3);
	}

	int sort(std::vector<int> nums)
	{
		std::sort(begin(nums), end(nums));
		size_t n = nums.size();
		return std::max(nums[0] * nums[1] * nums.back(), nums.back() * nums[n - 2] * nums[n - 3]);
	}
};

int main(int argc, char** argv)
{
	std::vector<int> vec{1000,1000,2,1,2,5,3,1};
	std::cout << Solution().maximumProduct(vec) << '\n';
}
