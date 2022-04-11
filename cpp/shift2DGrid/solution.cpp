// https://leetcode.com/problems/shift-2d-grid/

#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, size_t k)
	{
		return queue(grid, k);
	}

private:
	std::vector<std::vector<int>> queue(const std::vector<std::vector<int>>& grid, size_t k)
	{
		size_t total = grid.size() * grid[0].size();
		k = total - k % total;
		if (k == 0)
			return grid;

		std::queue<int> que;
		for (const auto& row : grid)
			for (int n : row)
				que.push(n);
		while (k-- > 0)
			que.push(que.front()), que.pop();

		std::vector<std::vector<int>> res(grid.size(), std::vector<int>(grid[0].size()));
		for (size_t i = 0; i < res.size(); ++i)
			for (size_t j = 0; j < res[i].size(); ++j)
				res[i][j] = que.front(), que.pop();

		return res;
	}

	std::vector<std::vector<int>> idx(const std::vector<std::vector<int>>& grid, size_t k)
	{
		size_t n = grid.size();
		size_t m = grid[0].size();
		size_t total = n * m;
		k = (total - (k % total));
		if (k == 0)
			return grid;

		std::vector<std::vector<int>> res(n, std::vector<int>(m));
		size_t row = k / m;
		size_t col = k % m;

		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < m; ++j) {
				res[i][j] = grid[row][col];
				col = ++col % m;
				if (col == 0)
					row = ++row % n;
			}
		}

		return res;
	}
};

int main(int argc, char** argv)
{
	std::vector<std::vector<int>> grid{{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}};
	auto res = Solution().shiftGrid(grid, 4);
	for (const auto& row : res)
		iter_print(begin(row), end(row));
}
