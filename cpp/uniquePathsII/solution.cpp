// https://leetcode.com/problems/unique-paths-ii/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& grid)
	{
		return dp_improved(grid);
	}

private:
	int dp_improved(const std::vector<std::vector<int>>& grid)
	{
		size_t row = grid.size();
		size_t col = grid[0].size();
		std::vector<int> dp(col, 0);
		dp[0] = 1;
		for (size_t i = 0; i < row; ++i) {
			for (size_t j = 0; j < col; ++j) {
				if (grid[i][j])
					dp[j] = 0;
				else if (j != 0)
					dp[j] += dp[j - 1];
			}
		}

		return dp.back();
	}

	// time: O(n * m)
	// space: O(n * m)
	int dp(const std::vector<std::vector<int>>& grid)
	{
		size_t n = grid.size();
		size_t m = grid[0].size();
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
		dp[0][1] = 1;
		for (size_t i = 1; i <= n; ++i) {
			for (size_t j = 1; j <= m; ++j) {
				if (grid[i - 1][j - 1] == 0)
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[n][m];
	}
};

int main(int argc, char** argv)
{
	std::vector<std::vector<int>> grid{{0,0,0},{0,1,0},{0,0,0}};
	std::vector<std::vector<int>> grid2{{0,1},{0,0}};
	std::cout << Solution().uniquePathsWithObstacles(grid) << '\n';
}
