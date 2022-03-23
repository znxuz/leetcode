// https://leetcode.com/problems/summary-ranges/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
	public:
		vector<string> summaryRanges(vector<int>& nums)
		{
			size_t n = nums.size();
			size_t start = 0;
			size_t end = 1;
			vector<string> res;
			while (start < n) {
				if (end >= n || nums[end] != nums[end - 1] + 1) {
					res.push_back(make_range(nums, start, end));
					start = end;
				}
				end++;
			}

			return res;
		}

		string make_range(const vector<int>& nums, int start, int end)
		{
			return to_string(nums[start]) + (start == end - 1 ? "" : "->" + to_string(nums[end - 1]));
		}
};

int main(int argc, char** argv)
{
}
