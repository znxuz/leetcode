// https://leetcode.com/problems/flood-fill/

#include <queue>
#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, size_t row, size_t col, int color)
	{
	    if (row < image.size() && col < image[row].size() && image[row][col] != color)
		dfs_iter(image, row, col, color);
	    return image;
	}

    private:
	// for bfs version just swap stack with queue
	void dfs_iter(std::vector<std::vector<int>>& image, size_t i, size_t j, int color)
	{
	    int old = image[i][j];
	    if (old == color)
		return;

	    std::stack<std::pair<size_t, size_t>> stk;
	    stk.push(std::pair(i, j));
	    while (!stk.empty()) {
		auto [row, col] = stk.top();
		stk.pop();
		if (row >= image.size() || col >= image[i].size() || image[row][col] != old || image[row][col] == color)
		    continue;
		image[row][col] = color;
		stk.push(std::pair(row - 1, col));
		stk.push(std::pair(row + 1, col));
		stk.push(std::pair(row, col - 1));
		stk.push(std::pair(row, col + 1));
	    }
	}

	void dfs_rec(std::vector<std::vector<int>>& image, size_t i, size_t j, int color)
	{
	    int old = image[i][j];
	    image[i][j] = color;
	    if (i - 1 < image.size() && image[i - 1][j] == old)
		dfs_rec(image, i - 1, j, color);
	    if (i + 1 < image.size() && image[i + 1][j] == old)
		dfs_rec(image, i + 1, j, color);
	    if (j - 1 < image[i].size() && image[i][j - 1] == old)
		dfs_rec(image, i, j - 1, color);
	    if (j + 1 < image[i].size() && image[i][j + 1] == old)
		dfs_rec(image, i, j + 1, color);
	}
};

int main(int argc, char** argv)
{
}
