// https://leetcode.com/problems/maximum-difference-between-increasing-elements/

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		int maximumDifferenceForward(vector<int>& nums)
		{
			int diff = -1;
			for (int i = 0, min = nums[0]; i < nums.size(); ++i) {
				if (nums[i] <= min)
					min = std::min(min, nums[i]);
				else
					diff = std::max(diff, nums[i] - min);
			}

			return diff;
		}

		// time complexity: O(n)
		// space complexity: O(1)
		int maximumDifferenceBackward(vector<int>& nums)
		{
			int max = nums.back();
			int diff = -1;
			for (int i = nums.size() - 1; i >= 0; --i) {
				if (nums[i] >= max)
					max = nums[i];
				else
					diff = std::max(diff, max - nums[i]);
			}

			return diff;
		}
};

int main(int argc, char** argv)
{
}
