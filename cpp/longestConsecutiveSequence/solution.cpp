// https://leetcode.com/problems/longest-consecutive-sequence/

#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		std::unordered_set<int> st(begin(nums), end(nums));

		int max_streak = 0;
		for (int n : nums) {
			if (!st.erase(n))
				continue;

			int cur_streak = 1;
			for (int m = n - 1; st.erase(m); --m)
				++cur_streak;
			for (int m = n + 1; st.erase(m); ++m)
				++cur_streak;
			max_streak = std::max(max_streak, cur_streak);
		}

		return max_streak;
	}
};

int main(int argc, char** argv)
{
}
