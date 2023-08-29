// https://leetcode.com/problems/available-captures-for-rook/

#include "helper.h"

using namespace std;
using namespace util;

enum class direction {
	north, south, west, east
};

struct position {
	size_t i;
	size_t j;
	direction dir;
};

class Solution 
{
public:
	int numRookCaptures(vector<vector<char>>& board) 
	{
		auto cnt = 0;

		for (size_t i = 0; i < board.size(); ++i) {
			auto found = false;
			for (size_t j = 0; j < board[i].size() && !found; ++j) {
				if (board[i][j] == 'R') {
					found = true;
					cnt += solve(board, i - 1, j, 'u');
					cnt += solve(board, i + 1, j, 'd');
					cnt += solve(board, i, j - 1, 'l');
					cnt += solve(board, i, j + 1, 'r');
				}
			}
			if (found)
				break;
		}

		return cnt;
	}

private:
	int solve(const vector<vector<char>>& board, size_t i, size_t j, char dir)
	{
		if (i >= board.size() || j >= board[i].size() || board[i][j] == 'B')
			return 0;
		if (board[i][j] == 'p')
			return 1;

		switch (dir) {
			case 'u':
				return solve(board, i - 1, j, dir);
			case 'd':
				return solve(board, i + 1, j, dir);
			case 'l':
				return solve(board, i, j - 1, dir);
			case 'r':
				return solve(board, i, j + 1, dir);
			default:
				break;
		}

		return 0;
	}

	int iter(vector<vector<char>>& board)
	{
		auto indices = get_rock_indices(board).value();
		auto stk = std::stack<position>{};

		for (int i = -1; i <= 1; i += 2) {
			auto tmp_i = indices[0] + i;
			auto tmp_j = indices[1] + i;
			if (tmp_i < board.size())
				stk.push({tmp_i, indices[1], (i > 0) ? direction::south : direction::north});
			if (tmp_j < board.front().size())
				stk.push({indices[0], tmp_j, (i > 0) ? direction::east : direction::west});
		}

		auto cnt = 0;
		while (!stk.empty()) {
			auto cur = stk.top();
			stk.pop();
			if (cur.i >= board.size() || cur.j >= board[cur.i].size() ||
					board[cur.i][cur.j] == 'B')
				continue;
			if (board[cur.i][cur.j] == 'p') {
				++cnt;
				continue;
			}

			switch (cur.dir) {
				case direction::north:
					if (cur.i - 1 < board.size())
						stk.push({cur.i - 1, cur.j, cur.dir});
					break;
				case direction::south:
					if (cur.i != SIZE_MAX)
						stk.push({cur.i + 1, cur.j, cur.dir});
					break;
				case direction::west:
					if (cur.j - 1 < board.front().size())
						stk.push({cur.i, cur.j - 1, cur.dir});
					break;
				case direction::east:
					if (cur.j != SIZE_MAX)
						stk.push({cur.i, cur.j + 1, cur.dir});
					break;
			}
		}

		return cnt;
	}

	std::optional<std::array<size_t, 2>> get_rock_indices(vector<vector<char>>& board)
	{
		std::optional<std::array<size_t, 2>> indices;
		for (size_t i = 0; i < board.size(); ++i) {
			for (size_t j = 0; j < board.size(); ++j) {
				if (board[i][j] == 'R')
					indices = std::array<size_t, 2>{i, j};
			}
		}

		return indices;
	}
};

int main(int argc, char **argv)
{
	auto board = vector<vector<char>>{{'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'p', 'p', '.', 'R', '.', 'p', 'B', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', 'B', '.', '.', '.', '.'}, {'.', '.', '.', 'p', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}};

	std::cout << Solution().numRookCaptures(board) << '\n';
}
