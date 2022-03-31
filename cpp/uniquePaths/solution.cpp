// https://leetcode.com/problems/unique-paths/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		return dp_improved(m, n);
	}

private:
	int dp_improved(size_t n, size_t m)
	{
		std::vector<int> row(m, 1);
		while (n-- > 1) {
			for (size_t i = 0; i < m; ++i) {
				if (i != 0)
					row[i] += row[i - 1];
			}
		}

		return row.back();
	}

	// time: O(n * m)
	// space: O(n * m)
	int dp(size_t n, size_t m)
	{
		std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));
		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < m; ++j) {
				if (i != 0 && j != 0)
					grid[i][j] += grid[i - 1][j] + grid[i][j - 1];
				else if (i == 0 || j == 0)
					grid[i][j] = 1;
			}
		}

		return grid.back().back();
	}

	// TLE
	void backtrack(int& cnt, size_t i, size_t j, size_t n, size_t m)
	{
		if (i + 1 == n && j + 1 == m) {
			++cnt;
			return;
		}

		if (i + 1 < n)
			backtrack(cnt, i + 1, j, n, m);
		if (j + 1 < m)
			backtrack(cnt, i, j + 1, n, m);
	}
};

int main(int argc, char** argv)
{
	int n = 3;
	int m = 7;
	std::cout << Solution().uniquePaths(n, m) << '\n';
}
