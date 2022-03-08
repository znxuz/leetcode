// https://leetcode.com/problems/valid-sudoku/

#include <ios>
#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_set>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		// n = board.length
		// time: O(n^2)
		// space: O(n)
		bool isValidSudoku(vector<vector<char>>& board)
		{
			return arr(board);
		}

		bool arr(const vector<vector<char>>& board)
		{
			array<bool, 9> cols;
			array<bool, 9> rows;
			array<array<array<bool, 9>, 3>, 3> subs;

			for (int i = 0; i < 9; ++i) {
				cols.fill(false);
				rows.fill(false);
				if (i % 3 == 0)
					for (int j = 0; j < subs.size(); ++j)
						for (int k = 0; k < subs[j].size(); ++k)
							subs[j][k].fill(false);

				int idx;
				for (int j = 0; j < 9; ++j) {
					if (board[i][j] != '.') {
						idx = board[i][j] - '1';
						if (!(cols[idx] ^= true))
							return false;
						if (j >= i && !(subs[i / 3][j / 3][idx] ^= true))
							return false;
					}
					if (board[j][i] != '.') {
						idx = board[j][i] - '1';
						if (!(rows[idx] ^= true))
							return false;
						if (j > i && !(subs[j / 3][i / 3][idx] ^= true))
							return false;
					}
				}
			}

			return true;
		}

		bool set(const vector<vector<char>>& board)
		{
			unordered_set<int> rows;
			unordered_set<int> cols;
			array<array<unordered_set<int>, 3>, 3> subs;
			for (int i = 0; i < 9; ++i) {
				rows.clear();
				cols.clear();
				if (i % 3 == 0)
					for (int j = 0; j < subs.size(); ++j)
						for (int k = 0; k < subs[j].size(); ++k)
							subs[j][k].clear();

				for (int j = 0; j < 9; ++j) {
					if (board[i][j] != '.') {
						if (!cols.insert(board[i][j]).second)
							return false;
						if (j >= i && !subs[i / 3][j / 3].insert(board[i][j]).second)
							return false;
					}
					if (board[j][i] != '.') {
						if (!rows.insert(board[j][i]).second)
								return false;
						if (j > i && !subs[j / 3][i / 3].insert(board[j][i]).second)
							return false;
					}
				}
			}

			return true;
		}
};

static void test()
{
	vector<vector<char>> board = 
	{{'5','3','.','.','7','.','.','.','.'}
	,{'6','.','.','1','9','5','.','.','.'}
	,{'.','9','8','.','.','.','.','6','.'}
	,{'8','.','.','.','6','.','.','.','3'}
	,{'4','.','.','8','.','3','.','.','1'}
	,{'7','.','.','.','2','.','.','.','6'}
	,{'.','6','.','.','.','.','2','8','.'}
	,{'.','.','.','4','1','9','.','.','5'}
	,{'.','.','.','.','8','.','.','7','9'}};

	cout << Solution().isValidSudoku(board) << '\n';
}

int main(int argc, char** argv)
{
	test();
}
