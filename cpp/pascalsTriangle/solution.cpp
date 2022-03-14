// https://leetcode.com/problems/pascals-triangle/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		vector<vector<int>> generate(int numRows)
		{
			vector<vector<int>> res;
			for (int i = 0; i < numRows; ++i) {
				if (i == 0) {
					res.push_back({1});
					continue;
				}
				const auto& prev_row = res[i - 1];
				const int n = prev_row.size();
				vector<int> cur_row;
				for (int j = 0; j < n + 1; ++j) {
					int prev = (j == 0 ? 0 : prev_row[j - 1]);
					int cur = (j == n ? 0 : prev_row[j]);
					cur_row.push_back(prev + cur);
				}
				res.push_back(cur_row);
			}

			return res;
		}
};

int main(int argc, char** argv)
{
	int n = 5;
	auto res = Solution().generate(n);
	for (const auto& row : res)
		iter_print(begin(row), end(row));
}
