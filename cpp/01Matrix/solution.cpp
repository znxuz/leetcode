// https://leetcode.com/problems/01-matrix/

#include <limits>
#include <array>
#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    // time: O(r * c)
    // space: O(r * c)
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
	size_t row = mat.size();
	size_t col = mat.front().size();
	std::vector<std::vector<int>> res(row,
		std::vector<int>(col, std::numeric_limits<int>::max()));
	std::queue<std::pair<size_t, size_t>> que;
	for (size_t i = 0; i < row; ++i) {
	    for (size_t j = 0; j < col; ++j) {
		if (!mat[i][j]) {
		    res[i][j] = 0;
		    que.push({i, j});
		}
	    }
	}

	while (!que.empty()) {
	    auto [x, y] = que.front();
	    que.pop();
	    static constexpr std::array<std::array<int, 2>, 4> delta {
		{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	    };
	    for (size_t i = 0; i < delta.size(); ++i) {
		auto [dx, dy] = delta[i];
		size_t new_x = x + static_cast<size_t>(dx);
		size_t new_y = y + static_cast<size_t>(dy);
		if (new_x < row && new_y < col &&
			res[new_x][new_y] > res[x][y] + 1) {
		    res[new_x][new_y] = res[x][y] + 1;
		    que.push({new_x, new_y});
		}
	    }
	}

	return res;
    }

private:
    // TLE
    // time: O((r * c)^2)
    std::vector<std::vector<int>> brute_force_bfs(std::vector<std::vector<int>>& mat)
    {
	std::vector<std::vector<int>> res(mat.size(),
		std::vector<int>(mat.front().size()));;
	for (size_t i = 0; i < mat.size(); ++i) {
	    for (size_t j = 0; j < mat[i].size(); ++j) {
		if (mat[i][j])
		    res[i][j] = bfs(mat, i, j);
	    }
	}

	return res;
    }

    int bfs(std::vector<std::vector<int>>& mat, size_t i, size_t j)
    {
	int distance = 0;
	std::vector<std::pair<std::pair<size_t, size_t>, int>> visited;
	std::queue<std::pair<size_t, size_t>> que;
	que.push({i, j});
	while (!que.empty()) {
	    size_t size = que.size();
	    while (size-- > 0) {
		auto [x, y] = que.front();
		que.pop();
		if (mat[x][y] == -1)
		    continue;
		if (!mat[x][y])
		    goto found;
		visited.emplace_back(std::pair{x, y}, mat[x][y]);
		mat[x][y] = -1;
		static constexpr std::array<std::array<int, 2>, 4> delta {
		    {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
		};
		for (const auto& [dx, dy] : delta) {
		    size_t new_x = x + static_cast<size_t>(dx);
		    size_t new_y = y + static_cast<size_t>(dy);
		    if (new_x < mat.size() && new_y < mat[new_x].size())
			que.push({new_x, new_y});
		}
	    }
	    ++distance;
	}

found:
	for (const auto& p : visited) {
	    auto [x, y] = p.first;
	    mat[x][y] = p.second;
	}

	return distance;
    }
};

int main(int argc, char** argv)
{
}
