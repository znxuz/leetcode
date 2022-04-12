// https://leetcode.com/problems/island-perimeter/

#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int islandPerimeter(vector<vector<int>>& grid)
	{
		size_t i = 0;
		size_t j = 0;
		while (i < grid.size() && grid[i][j] == 0) {
			j = ++j % grid[i].size();
			if (j == 0)
				++i;
		}
		if (grid[i][j]) {
			int cnt = dfs(grid, i, j);
			for (auto& row : grid)
				for (auto& cell : row)
					if (cell == -1)
						cell = 1;
			return cnt;
		}

		return 0;
	}

private:
	// time: O(n * m)
	// space: O(1)
	int dfs(std::vector<std::vector<int>>& grid, size_t i, size_t j)
	{
		if (i >= grid.size() || j >= grid[i].size() || !grid[i][j])
			return 1;
		if (grid[i][j] < 0)
			return 0;

		grid[i][j] = -1;
		int cnt = 0;
		cnt += dfs(grid, i - 1, j);
		cnt += dfs(grid, i + 1, j);
		cnt += dfs(grid, i, j - 1);
		cnt += dfs(grid, i, j + 1);

		return cnt;
	}

};

int main(int argc, char** argv)
{
	std::vector<std::vector<int>> grid{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
	for (const auto& row : grid)
		iter_print(begin(row), end(row));
	std::cout << Solution().islandPerimeter(grid) << '\n';
	for (const auto& row : grid)
		iter_print(begin(row), end(row));
}
