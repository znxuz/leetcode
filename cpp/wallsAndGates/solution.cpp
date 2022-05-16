// https://leetcode.com/problems/walls-and-gates/

#include <array>
#include <queue>
#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    void wallsAndGates(vector<vector<int>>& rooms)
    {
	std::queue<std::pair<size_t, size_t>> que;
	for (size_t i = 0; i < rooms.size(); ++i)
	    for (size_t j = 0; j < rooms[i].size(); ++j)
		if (rooms[i][j] == this->gate)
		    que.push(pair(i, j));

	while (!que.empty()) {
	    auto [x, y] = que.front();
	    que.pop();
	    if (rooms[x][y] == obstacle)
		continue;

	    constexpr static std::array<std::array<int, 2>, 4> directions {{
		{1, 0}, {-1, 0}, {0, 1}, {0, -1}
	    }};
	    for (const auto& [dx, dy] : directions) {
		auto new_x = x + static_cast<size_t>(dx);
		auto new_y = y + static_cast<size_t>(dy);
		if (new_x >= rooms.size() || new_y >= rooms[new_x].size() ||
			rooms[new_x][new_y] == obstacle ||
			rooms[new_x][new_y] == gate ||
			rooms[new_x][new_y] != empty)
		    continue;
		rooms[new_x][new_y] = rooms[x][y] + 1;
		que.push(pair(new_x, new_y));
	    }
	}
    }

private:
    constexpr static int empty = std::numeric_limits<int>::max();
    constexpr static int gate = 0;
    constexpr static int obstacle = -1;
};

int main(int argc, char** argv)
{
}
