// https://leetcode.com/problems/4sum/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		// time: O(n^3)
		// space: O(n)
		vector<vector<int>> fourSum(vector<int>& nums, int target)
		{
			int n = nums.size();

			sort(begin(nums), end(nums));
			vector<vector<int>> res;
			for (int i = 0; i < n; ++i) {
				if (i > 0 && nums[i] == nums[i - 1])
					continue;
				for (int j = i + 1; j < n; ++j) {
					if (j > i + 1 && nums[j] == nums[j - 1])
						continue;
					int lo = j + 1;
					int hi = n - 1;
					while (lo < hi) {
						long sum = static_cast<long>(nums[i]) + nums[j] + nums[lo] + nums[hi];
						if (sum < target || (lo > j + 1 && nums[lo] == nums[lo - 1]))
							++lo;
						else if (sum > target || (hi < n - 1 && nums[hi] == nums[hi + 1]))
							--hi;
						else
							res.push_back({nums[i], nums[j], nums[lo++], nums[hi--]});
					}
				}
			}

			return res;
		}
};

class Solution2
{
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target)
		{
			sort(begin(nums), end(nums));
			return k_sum(nums, target, 0, 4);
		}

		vector<vector<int>> k_sum(vector<int>& nums, int target, int start, int k)
		{
			vector<vector<int>> res;

			if (start == nums.size()) // If we have run out of numbers to add, return res.
				return res;
			int average = target / k;
			if  (nums[start] > average || average > nums.back())
				return res;

			if (k == 2)
				return two_sum(nums, target, start);
			for (int i = start; i < nums.size(); ++i) {
				if (i > start && nums[i] == nums[i - 1])
					continue;
				for (vector<int>& subset : k_sum(nums, static_cast<long>(target) - nums[i], i + 1, k - 1)) {
					res.push_back({nums[i]});
					res.back().insert(end(res.back()), begin(subset), end(subset));
				}
			}

			return res;
		}

		vector<vector<int>> two_sum(vector<int>& nums, int target, int start)
		{
			vector<vector<int>> res;
			int lo = start;
			int hi = nums.size() - 1;

			while (lo < hi) {
				int sum = nums[lo] + nums[hi];
				if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
					++lo;
				else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
					--hi;
				else
					res.push_back({nums[lo++], nums[hi--]});
			}

			return res;
		}
};

int main(int argc, char** argv)
{
}
