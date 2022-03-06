// https://leetcode.com/problems/find-k-closest-elements/

#include <iostream>
#include <vector>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		vector<int> findClosestElements(vector<int>& nums, int k, int x)
		{
			return find_bs_sliding_window(nums, k, x);
		}

		// time: O(log(n - k) + k)
		// space: O(1)
		vector<int> find_bs_only(vector<int>& nums, int k, int x)
		{
			int lo = 0;
			int hi = nums.size() - k;

			while (lo < hi) {
				int md = lo + (hi - lo) / 2;
				if (x - nums[md] > nums[md + k] - x)
					lo = md + 1;
				else
					hi = md;
			}

			vector<int> res;
			for (int i = lo; i < lo + k; ++i)
				res.push_back(nums[i]);

			return res;
		}

		// binary search | sliding window
		// time: O(log(n) + k)
		// space: O(n)
		vector<int> find_bs_sliding_window(const vector<int>& nums, int k, int x)
		{
			int idx = binary_search(nums, x, 0, nums.size() - 1);

			int left = idx - 1;
			int right = left + 1;
			while (k > 0 && left >= 0 && right < nums.size()) {
				if (x - nums[left] <= nums[right] - x)
					left--;
				else
					right++;
				--k;
			}
			while (k-- > 0) {
				if (left >= 0)
					left--;
				if (right < nums.size())
					right++;
			}

			vector<int> res;
			for (int i = left + 1; i < right; ++i)
				res.push_back(nums[i]);

			return {res};
		}

	private:
		int binary_search(const vector<int>& nums, int target, int lo, int hi)
		{
			if (hi - 1 <= lo)
				return (hi == lo ? lo : std::abs(nums[lo] - target) <= std::abs(nums[hi] - target) ? lo : hi);

			int md = lo + (hi - lo) / 2;
			if (nums[md] >= target)
				return binary_search(nums, target, lo, md);
			return binary_search(nums, target, md, hi);
		}
};

int main(int argc, char** argv)
{
	Solution s;
	vector<int> nums {-2,-1,1,2,3,4,5};
	v_print(nums);
	vector<int> res = s.findClosestElements(nums, 7, 3);
	v_print(res);
}
