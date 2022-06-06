// https://leetcode.com/problems/maximal-square/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
	return dp_improved(matrix);
    }

private:
    // time: O(n * m)
    // space: O(2m)
    int dp_improved(const std::vector<std::vector<char>>& matrix)
    {
	std::vector<int> dp(matrix.front().size());
	int max = 0;
	for (size_t i = 0; i < matrix.size(); ++i) {
	    std::vector<int> cur_row(matrix[i].size());
	    for (size_t j = 0; j < matrix[i].size(); ++j) {
		if (matrix[i][j] == '0')
		    continue;
		int prev_row = dp[j];
		int prev_col = (j == 0 ? 0 : cur_row[j - 1]);
		int prev_row_col = (j == 0 ? 0 : dp[j - 1]);
		cur_row[j] = std::min(prev_row_col, std::min(prev_row, prev_col)) + 1;
		max = std::max(max, cur_row[j]);
		prev_col = cur_row[j];
	    }
	    dp = std::move(cur_row);
	}

	return max * max;
    }

    // time: O(n * m)
    // space: O(n * m)
    int dp(const std::vector<std::vector<char>>& matrix)
    {
	std::vector<std::vector<int>> dp(matrix.size(),
		std::vector<int>(matrix.front().size()));

	int max = 0;
	for (size_t i = 0; i < matrix.size(); ++i) {
	    for (size_t j = 0; j < matrix[i].size(); ++j) {
		if (matrix[i][j] == '0')
		    continue;
		int prev_row = (i == 0 ? 0 : dp[i - 1][j]);
		int prev_col = (j == 0 ? 0 : dp[i][j - 1]);
		int prev_row_col = (i == 0 || j == 0 ? 0 : dp[i - 1][j - 1]);
		dp[i][j] = std::min(prev_row_col, std::min(prev_row, prev_col)) + 1;
		max = std::max(max, dp[i][j]);
	    }
	}

	return max * max;
    }
};

int main(int argc, char** argv)
{
}
