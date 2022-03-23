// https://leetcode.com/problems/merge-intervals/

#include <map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
	public:
		vector<vector<int>> merge(vector<vector<int>>& intervals)
		{
			return sort(intervals);
		}

		// time: O(n * log(n))
		// space: O(n)
		vector<vector<int>> sort(vector<vector<int>>& intervals)
		{
			vector<vector<int>> res;
			std::sort(begin(intervals), end(intervals));

			vector<int> range;
			for (const auto& iv : intervals) {
				if (range.empty() || iv[0] > range[1]) {
					if (!range.empty())
						res.push_back(range);
					range = iv;
				} else if (iv[1] > range[1]) {
					range[1] = iv[1];
				}
			}
			res.push_back(range);

			return res;
		}
};

int main(int argc, char** argv)
{
	std::vector<std::vector<int>> vec{{3, 5}, {1, 2}, {4, 5}};
	Solution s;
	auto res{s.merge(vec)};
	for_each(begin(res), end(res), [](const auto& row) { iter_print(begin(row), end(row)); });
}
