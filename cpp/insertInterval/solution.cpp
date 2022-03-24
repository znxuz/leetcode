// https://leetcode.com/problems/insert-interval/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new_interval)
		{
			return improved(intervals, new_interval);
		}

		vector<vector<int>> improved(const vector<vector<int>>& intervals, vector<int>& new_interval)
		{
			vector<vector<int>> res;
			size_t i = 0;

			// append all previous
			while (i < intervals.size() && intervals[i][1] < new_interval[0])
				res.push_back(intervals[i++]);

			// merge
			while (i < intervals.size() && intervals[i][0] <= new_interval[1]) {
				new_interval[0] = std::min(new_interval[0], intervals[i][0]);
				new_interval[1] = std::max(new_interval[1], intervals[i][1]);
				++i;
			}
			res.push_back(new_interval);

			// append all next
			while (i < intervals.size())
				res.push_back(intervals[i++]);

			return res;
		}

		vector<vector<int>> mine(vector<vector<int>>& intervals, vector<int>& new_interval)
		{
			vector<vector<int>> res;
			size_t i = 0;
			while (i < intervals.size() && intervals[i][1] < new_interval[0])
				res.push_back(intervals[i++]);
			if (i == intervals.size()) {
				res.push_back(new_interval);
				return res;
			}

			auto& merged = intervals[i];
			if (merged[0] <= new_interval[1]) {
				merged[0] = std::min(merged[0], new_interval[0]);
				merged[1] = std::max(merged[1], new_interval[1]);
			} else {
				res.push_back(new_interval);
			}
			bool added = false;
			for (++i; i < intervals.size(); ++i) {
				if (intervals[i][1] < merged[0])
					continue;
				else if (intervals[i][0] <= merged[1]) {
					merged[1] = std::max(merged[1], intervals[i][1]);
				} else {
					if (!added)
						res.push_back(merged), added = true;
					res.push_back(intervals[i]);
				}
			}
			if (!added)
				res.push_back(merged);

			return res;
		}
};

static void test(vector<vector<int>>& intervals, vector<int> new_interval)
{
	const auto& res = Solution{}.insert(intervals, new_interval);
	for_each(begin(res), end(res), [](const auto& arr) { iter_print(begin(arr), end(arr)); });
}

int main(int argc, char** argv)
{
	// vector<vector<int>> i1{{1,2},{3,5},{6,7},{8,10},{12,16}};
	// vector<int> n1{4, 8};
	// test(i1, n1);

	vector<vector<int>> i2{{1, 5}};
	vector<int> n2{0, 0};
	test(i2, n2);
}
