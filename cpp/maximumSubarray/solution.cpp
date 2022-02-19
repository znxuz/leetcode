// https://leetcode.com/problems/maximum-subarray/

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		int maxSubArray(vector<int>& nums)
		{
			return max_sub_array(nums, 0, nums.size() - 1);
		}

		int max_sub_array(vector<int>& nums, int l, int r)
		{
			if (l == r)
				return nums[l];

			int m = l + (r - l) / 2;

			int lmax = INT32_MIN;
			int rmax = INT32_MIN;
			for (int i = m, sum = 0; i >= l; i--) {
				sum += nums[i];
				lmax = std::max(lmax, sum);
			}
			for (int i = m + 1, sum = 0; i <= r; ++i) {
				sum += nums[i];
				rmax = std::max(rmax, sum);
			}

			return std::max(std::max(std::max(lmax, rmax), lmax + rmax),
					std::max(max_sub_array(nums, l, m), max_sub_array(nums, m + 1, r)));
		}

		int maxSubArrayKadane(vector<int>& nums)
		{
			int max = INT32_MIN;
			int sum = 0;
			for (int n : nums) {
				sum = std::max(n, sum + n);
				max = std::max(max, sum);
			}

			return max;
		}
};

int main(int argc, char** argv)
{
}
