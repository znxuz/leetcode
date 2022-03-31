// https://leetcode.com/problems/minimum-path-sum/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		return dp_rec(grid, 0, 0);
	}

private:
	// time: O(n * m)
	// space: O(1)
	int dp_rec(std::vector<std::vector<int>>& grid, size_t i, size_t j)
	{
		if (i != 0 && j != 0)
			grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
		else if (i != 0)
			grid[i][j] += grid[i - 1][j];
		else if (j != 0)
			grid[i][j] += grid[i][j - 1];

		if (i + 1 == grid.size() && j + 1 == grid[i].size())
			return grid[i][j];
		++j;
		return dp_rec(grid, i + j / grid[i].size(), j % grid[i].size());
	}

	// time: O(n * m)
	// space: O(1)
	int dp_in_place(std::vector<std::vector<int>>& grid)
	{
		size_t n = grid.size();
		size_t m = grid[0].size();
		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < m; ++j) {
				if (i != 0 && j != 0)
					grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
				else if (i != 0)
					grid[i][j] += grid[i - 1][j];
				else if (j != 0)
					grid[i][j] += grid[i][j - 1];
			}
		}

		return grid.back().back();
	}

	// time: O(n * m)
	// space: O(n * m)
	int dp(const  std::vector<std::vector<int>>& grid)
	{
		size_t n = grid.size();
		size_t m = grid[0].size();
		std::vector<std::vector<int>> dp(n, vector<int>(m));
		for (size_t i = 0; i < grid.size(); ++i) {
			for (size_t j = 0; j < grid[i].size(); ++j) {
				dp[i][j] = grid[i][j];
				if (i != 0 && j != 0)
					dp[i][j] += std::min(dp[i - 1][j], dp[i][j - 1]);
				else if (i != 0)
					dp[i][j] += dp[i - 1][j];
				else if (j != 0)
					dp[i][j] += dp[i][j - 1];
			}
		}

		return dp.back().back();
	}
};

void test()
{
	std::vector<std::vector<int>> grid{{1,2,3},{4,5,6}};
	std::cout << Solution().minPathSum(grid) << '\n';
}

int main(int argc, char** argv)
{
	test();
}
