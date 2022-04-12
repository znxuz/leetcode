// https://leetcode.com/problems/game-of-life/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	void gameOfLife(vector<vector<int>>& board)
	{
		const_space(board);
	}

private:
	void const_space(std::vector<std::vector<int>>& board)
	{
		for (size_t i = 0; i < board.size(); ++i)
			for (size_t j = 0; j < board[i].size(); ++j)
				board[i][j] |= next_state(board, i, j) << 1;

		for (size_t i = 0; i < board.size(); ++i)
			for (size_t j = 0; j < board[i].size(); ++j)
				board[i][j] = board[i][j] >> 1;
	}

	void extra_space(std::vector<std::vector<int>>& board)
	{
		std::vector<std::vector<int>> next(board.size(), std::vector<int>(board[0].size()));
		for (size_t i = 0; i < board.size(); ++i) {
			for (size_t j = 0; j < board[i].size(); ++j) {
				next[i][j] = next_state(board, i, j);
			}
		}

		board = next;
	}

	int next_state(const std::vector<std::vector<int>>& board, size_t row, size_t col)
	{
		size_t dead = 0;
		size_t alive = 0;
		for (size_t i = std::min(row - 1, row); i < std::min(board.size(), row + 2); ++i) {
			for (size_t j = std::min(col - 1, col); j < std::min(board[i].size(), col + 2); ++j) {
				if (i == row && j == col)
					continue;
				if (board[i][j] & 1)
					++alive;
				else
					++dead;
			}
		}

		if (!(board[row][col] & 1))
			return (alive == 3);
		return (alive == 2 || alive == 3);
	}
};

int main(int argc, char** argv)
{
	std::vector<std::vector<int>> board{{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
	for (const auto& row : board)
		iter_print(begin(row), end(row));
	Solution().gameOfLife(board);
	std::cout << '\n';
	for (const auto& row : board)
		iter_print(begin(row), end(row));
}
