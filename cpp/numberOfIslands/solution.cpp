// https://leetcode.com/problems/number-of-islands/

#include <queue>
#include <array>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
	return bfs_iter(grid);
    }

private:
    int bfs_iter(std::vector<std::vector<char>>& grid)
    {
	int cnt = 0;
	for (size_t i = 0; i < grid.size(); ++i) {
	    for (size_t j = 0; j < grid[i].size(); ++j) {
		if (grid[i][j] != '1')
		    continue;
		bfs(grid, i, j);
		++cnt;
	    }
	}

	for (auto& row : grid)
	    for (auto& cell : row)
		if (cell == 0)
		    cell = '1';

	return cnt;
    }

    void bfs(std::vector<std::vector<char>>& grid, size_t i, size_t j)
    {
	std::queue<std::pair<size_t, size_t>> que;
	que.push(std::pair(i, j));
	while (!que.empty()) {
	    size_t size = que.size();
	    while (size-- > 0) {
		auto [x, y] = que.front();
		que.pop();
		constexpr static std::array<std::array<int, 2>, 4> directions {
		    {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
		};
		for (const auto& [dx, dy] : directions) {
		    size_t new_x = x + static_cast<size_t>(dx);
		    size_t new_y = y + static_cast<size_t>(dy);
		    if (new_x >= grid.size() ||
			    new_y >= grid[new_x].size() ||
			    grid[new_x][new_y] != '1')
			continue;
		    grid[new_x][new_y] = 0;
		    que.push(std::pair(new_x, new_y));
		}
	    }
	}
    }

    int dfs_rec(std::vector<std::vector<char>>& grid)
    {
	int cnt = 0;
	for (size_t i = 0; i < grid.size(); ++i) {
	    for (size_t j = 0; j < grid[i].size(); ++j) {
		if (grid[i][j] == '1') {
		    dfs(grid, i, j);
		    ++cnt;
		}
	    }
	}

	for (auto& row : grid)
	    for (auto& cell : row)
		if (cell == 0)
		    cell = 1;

	return cnt;
    }

    void dfs(std::vector<std::vector<char>>& grid, size_t i, size_t j)
    {
	if (i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0' ||
		grid[i][j] == 0)
	    return;

	grid[i][j] = 0;
	constexpr static std::array<std::array<int, 2>, 4> directions{
	    {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	};
	for (const auto& [di, dj] : directions)
	    dfs(grid, i + di, j + dj);
    }
};

int main(int argc, char** argv)
{
}
