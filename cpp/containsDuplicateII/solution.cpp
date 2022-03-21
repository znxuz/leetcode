// https://leetcode.com/problems/contains-duplicate-ii/

#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		bool containsNearbyDuplicate(vector<int>& nums, int k)
		{
			return set(nums, k);
		}

		bool set(const vector<int>& nums, size_t k)
		{
			unordered_set<int> s;
			for (size_t i = 0; i < nums.size(); ++i) {
				if (!s.insert(nums[i]).second)
					return true;
				if (i >= k)
					s.erase(nums[i - k]);
			}

			return false;
		}
};

int main(int argc, char** argv)
{
}
