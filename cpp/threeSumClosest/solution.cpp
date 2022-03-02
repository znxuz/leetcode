// https://leetcode.com/problems/3sum-closest/submissions/

#include <climits>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		// time: O(n^2)
		// space: O(n)
		int threeSumClosest(vector<int>& nums, int target)
		{
			return two_pointer(nums, target);
		}

		int two_pointer(vector<int>& nums, int target)
		{
			sort(begin(nums), end(nums));
			int closest = INT_MAX;
			int res = 0;
			for (size_t i = 0; i < nums.size() - 2; ++i) {
				if (i > 0 && nums[i] == nums[i - 1])
					continue;
				int lo = i + 1;
				int hi = nums.size() - 1;
				while (lo < hi) {
					int sum = nums[i] + nums[lo] + nums[hi];
					if (sum > target) {
						--hi;
						while (hi > lo && nums[hi] == nums[hi + 1])
							--hi;
					} else if (sum < target) {
						++lo;
						while (lo < hi && nums[lo] == nums[lo - 1])
							++lo;
					} else {
						return sum;
					}
					int diff = std::abs(sum - target);
					if (diff < closest) {
						closest = diff;
						res = sum;
					}
				}
			}

			return res;
		}

};

int main(int argc, char** argv)
{
	vector<int> arr = {-1,0,1,1,55};
	print_vector(arr);
	cout << Solution().threeSumClosest(arr, 3) << '\n';
}
