// https://leetcode.com/problems/surrounded-regions/

#include <array>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	void solve(vector<vector<char>>& board)
	{
	    if (board.empty() || board.front().empty())
		return;

	    size_t first_row = 0;
	    size_t last_row = board.size() - 1;
	    for (size_t j = 0; j < board[0].size(); ++j) {
		mark_invalid(board, first_row, j);
		mark_invalid(board, last_row, j);
	    }

	    size_t first_col = 0;
	    size_t last_col = board[0].size() - 1;
	    for (size_t i = 0; i < board.size(); ++i) {
		mark_invalid(board, i, first_col);
		mark_invalid(board, i, last_col);
	    }

	    for (auto& row : board)
		for (auto& cell : row)
		    cell = (cell == '#' ? 'O' : 'X');
	}

    private:
	void mark_invalid(std::vector<std::vector<char>>& board,
		size_t i, size_t j)
	{
	    if (i >= board.size() || j >= board[i].size() ||
		    board[i][j] == 'X' || board[i][j] == '#')
		return;

	    board[i][j] = '#';
	    mark_invalid(board, i - 1, j);
	    mark_invalid(board, i + 1, j);
	    mark_invalid(board, i, j - 1);
	    mark_invalid(board, i, j + 1);
	}
};

int main()
{
    std::vector<std::vector<char>> board = {
	{'O','X','X','O','X'},
	{'X','O','O','X','O'},
	{'X','O','X','O','X'},
	{'O','X','O','O','O'},
	{'X','X','O','X','O'}};
    for_each(begin(board), end(board), [](const auto& row) {
	    iter_print(begin(row), end(row));
	    });
    std::cout << "======================\n";
    Solution().solve(board);
    for_each(begin(board), end(board), [](const auto& row) {
	    iter_print(begin(row), end(row));
	    });
}
