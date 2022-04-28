// https://leetcode.com/problems/triangle/

#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int minimumTotal(vector<vector<int>>& triangle)
	{
		return dp(triangle);
	}

private:
	// time: O(n * m)
	// space: O(m)
	int dp_improved(const std::vector<std::vector<int>>& triangle)
	{
		std::vector<int> dp(triangle.back().size());
		for (size_t i = 0; i < triangle.size(); ++i) {
			for (size_t j = 0; j < triangle[i].size(); ++j) {
				int cur = triangle[i][j];
				if (i != 0) {
					if (j == 0)
						cur += dp[j];
					else if (j + 1 < triangle[i].size())
						cur += std::min(dp[j - 1], dp[j]);
					else
						cur += dp[j - 1];
				}
				dp[j] = cur;
			}
		}

		return *std::min_element(begin(dp), end(dp));
	}

	int dp(const std::vector<std::vector<int>>& triangle)
	{
		std::vector<std::vector<int>> dp(triangle.size());
		for (size_t i = 0; i < triangle.size(); ++i) {
			for (size_t j = 0; j < triangle[i].size(); ++j) {
				int cur = triangle[i][j];
				if (i != 0) {
					if (j == 0)
						cur += dp[i - 1][j];
					else if (j + 1 < triangle[i].size())
						cur += std::min(dp[i - 1][j - 1], dp[i - 1][j]);
					else
						cur += dp[i - 1][j - 1];
				}
				dp[i].push_back(cur);
			}
		}

		int min = std::numeric_limits<int>::max();
		for (auto n : dp.back())
			min = std::min(min, n);
		return min;
	}

	// TLE
	int backtrack(const std::vector<std::vector<int>>& triangle)
	{
		int min = std::numeric_limits<int>::max();
		bt_helper(triangle, 0, 0, 0, min);
		return min;
	}

	void bt_helper(const std::vector<std::vector<int>>& triangle, size_t i, size_t j, int sum, int& min)
	{
		if (i >= triangle.size()) {
			min = std::min(min, sum);
			return;
		}

		for (size_t k = j; k < j + 2 && k < triangle[i].size(); ++k) {
			sum += triangle[i][k];
			bt_helper(triangle, i + 1, k, sum, min);
			sum -= triangle[i][k];
		}
	}
};

int main(int argc, char** argv)
{
	std::vector<std::vector<int>> vec{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	std::cout << Solution().minimumTotal(vec) << '\n';
}
