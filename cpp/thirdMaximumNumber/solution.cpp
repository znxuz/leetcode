// https://leetcode.com/problems/third-maximum-number/

#include <set>
#include <iostream>
#include <limits>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int thirdMax(vector<int>& nums)
	{
		return set(nums);
	}

private:
	// time: O(n)
	// space: O(1)
	int set(const vector<int>& nums)
	{
		std::set<int> top3;
		for (auto n : nums)
			if (top3.insert(n).second && top3.size() > 3)
				top3.erase(top3.begin());

		return (top3.size() == 3 ? *top3.begin() : *top3.rbegin());
	}

	// time: O(n * log(n))
	// space: O(n)
	int sort(vector<int>& nums)
	{
		std::sort(std::begin(nums), std::end(nums), std::greater<int>());
		size_t cnt = 0;
		int prev;
		int max = std::numeric_limits<int>::min();
		for (size_t i = 0; i < nums.size() && cnt < 3; ++i) {
			if (i == 0 || prev != nums[i])
				++cnt, prev = nums[i];
			max = std::max(max, nums[i]);
		}

		return cnt < 3 ? max : prev;
	}
};

int main(int argc, char** argv)
{
}
