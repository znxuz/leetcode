// https://leetcode.com/problems/contains-duplicate/

#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		bool containsDuplicate(vector<int>& nums)
		{
			return set(nums);
		}

		bool sort(vector<int>& nums)
		{
			std::sort(begin(nums), end(nums));
			for (size_t i = 1; i < nums.size(); ++i)
				if (nums[i] == nums[i - 1])
					return true;
			return false;
		}

		bool set(const vector<int>& nums)
		{
			return nums.size() != unordered_set<int>(begin(nums), end(nums)).size();
		}
};

int main(int argc, char** argv)
{
}
