// https://leetcode.com/problems/find-target-indices-after-sorting-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		vector<int> targetIndices(vector<int>& nums, int target)
		{
			vector<int> freq(101);
			for (int n : nums)
				freq[n]++;

			vector<int> ret;
			int idx = 0;
			for (int i = 0; i < target; ++i)
				idx += freq[i];
			while (freq[target]-- > 0)
				ret.push_back(idx++);

			return ret;
		}

		// time: O(n * log(n))
		// space: O(n)
		vector<int> targetIndicesSort(vector<int>& nums, int target)
		{
			sort(nums.begin(), nums.end());
			vector<int> ret;
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] == target)
					ret.push_back(i);
			}

			return ret;
		}
};

int main(int argc, char** argv)
{
}
