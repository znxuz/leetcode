// https://leetcode.com/problems/word-search/

#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		if (pruning(board, word))
			return false;

		for (size_t i = 0; i < board.size(); ++i) {
			for (size_t j = 0; j < board[i].size(); ++j) {
				if (backtrack_dfs(board, i, j, word, 0))
					return true;
			}
		}

		return false;
	}

private:
	// N = n * m
	// L = word length
	// time: O(N * 3^L):
	// 	each cell has 4 directions but omit one for not going back
	// space: O(L)
	bool backtrack_dfs(std::vector<std::vector<char>>& board, int i, int j, const std::string& word, size_t idx)
	{
		if (idx == word.size())
			return true;
		if (i < 0 || j < 0 || i == board.size() || j == board[i].size()
				|| word[idx] != board[i][j])
			return false;

		auto cached = board[i][j];
		board[i][j] = '\0';

		bool res = false;
		++idx;
		res |= backtrack_dfs(board, i - 1, j, word, idx) || backtrack_dfs(board, i + 1, j, word, idx)
			|| backtrack_dfs(board, i, j - 1, word, idx) || backtrack_dfs(board, i, j + 1, word, idx);

		board[i][j] = cached;

		return res;
	}

	bool pruning(const std::vector<std::vector<char>>& board, const std::string& word)
	{
		if (word.size() > board.size() * board.back().size())
			return false;

		array<int, 256> cnts{};
		for (const auto& row : board) {
			for (auto c : row) {
				++cnts[c];
			}
		}
		for (auto c : word)
			--cnts[c];

		return any_of(begin(cnts), end(cnts), [](auto n) { return n < 0; });
	}
};

int main(int argc, char** argv)
{
	std::vector<std::vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	std::string word = "ABCCED";
	std::cout << Solution().exist(board, word) << '\n';
}
