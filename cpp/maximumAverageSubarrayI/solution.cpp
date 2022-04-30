// https://leetcode.com/problems/maximum-average-subarray-i/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	double findMaxAverage(vector<int>& nums, int k)
	{
		return sliding_window(nums, k);
	}

private:
	// time: O(n)
	// space: O(1)
	double sliding_window(const vector<int>& nums, size_t k)
	{
		size_t n = nums.size();
		double sum = 0;
		for (size_t i = std::min(k, n); i-- > 0;)
			sum += nums[i];

		double max = sum;
		for (size_t i = k; i < n; ++i) {
			sum += nums[i];
			sum -= nums[i - k];
			max = std::max(max, sum);
		}

		return max / k;
	}
};

int main(int argc, char** argv)
{
}
