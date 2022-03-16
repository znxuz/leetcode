// https://leetcode.com/problems/missing-ranges/

#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
		{
			if (nums.size() == 0)
				return {get_range(lower, upper)};

			vector<string> res;
			size_t i = 0;
			while (lower <= upper) {
				if (lower < nums[i])
					res.push_back(get_range(lower, nums[i] - 1));
				else if (lower > nums[i])
					res.push_back(get_range(nums[i] + 1, lower));

				if (lower == upper)
					break;
				lower = (i < nums.size() - 1 ? nums[i++] + 1 : upper);
			}

			return res;
		}

	private:
		string get_range(int begin, int end)
		{
			return to_string(begin) + (begin == end ? "" : "->" + to_string(end));
		}
};

int main(int argc, char** argv)
{
	int begin = 0;
	int end = std::numeric_limits<int>::max();
	vector<int> n{std::numeric_limits<int>::max()};
	vector<string> res = Solution().findMissingRanges(n, begin, end);
	iter_print(res.begin(), res.end());
}
