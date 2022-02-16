#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// iter
		// time complexity: O(logn)
		// space complexity: O(1)
		int searchInsert(vector<int>& nums, int t)
		{
			int idx = 0;
			int l = 0;
			int r = nums.size() - 1;
			while (l <= r) {
				int m = l + (r - l) / 2;
				if (nums[m] == t)
					return m;
				if (nums[m] < t)
					l = m + 1;
				else
					r = m - 1;
			}

			return l;
		}

		// rec
		// time complexity: O(logn)
		// space complexity: O(1)
		int searchInsertRec(vector<int>& nums, int target)
		{
			return binary_search(nums, 0, nums.size() - 1, target);
		}

		int binary_search(vector<int>& nums, int l, int r, int t)
		{
			if (l >= r)
				return t <= nums[l] ? l : l + 1;

			int m = l + (r - l) / 2;
			if (nums[m] > t)
				return binary_search(nums, l, m, t);
			else if (nums[m] < t)
				return binary_search(nums, m + 1, r, t);
			return m;
		}

		int binary_search_2(vector<int>& nums, int l, int r, int t)
		{
			if (l > r)
				return l;

			int m = l + (r - l) / 2;
			if (nums[m] > t)
				return binary_search(nums, l, m - 1, t);
			else if (nums[m] < t)
				return binary_search(nums, m + 1, r, t);
			return m;
		}
};

int main(int argc, char** argv)
{
}

