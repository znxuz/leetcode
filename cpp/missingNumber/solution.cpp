// https://leetcode.com/problems/missing-number/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	// time: O(n)
	// space: O(1)
	int missingNumber(vector<int>& nums)
	{
		return xor_op(nums);
	}

private:
	size_t xor_op(const vector<int>& nums)
	{
		size_t rest = nums.size();
		for (size_t i = 0; i < nums.size(); ++i)
			rest ^= i ^ nums[i];

		return rest;
	}

	size_t gauss(const vector<int>& nums)
	{
		using std::begin;
		using std::end;

		size_t n = nums.size();
		size_t sum = n * (n + 1) / 2;

		for_each(begin(nums), end(nums), [&sum](auto n) { sum -= n; });
		return sum;
	}
};

int main(int argc, char** argv)
{
	std::vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
	std::cout << Solution().missingNumber(nums) << '\n';
}
