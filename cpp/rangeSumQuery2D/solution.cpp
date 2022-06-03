// https://leetcode.com/problems/range-sum-query-2d-immutable/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class NumMatrix
{
public:
    NumMatrix(vector<vector<int>>& matrix) :
	dp(matrix.size() + 1, std::vector<int>(matrix.front().size() + 1))
    {
	for (size_t i = 0; i < matrix.size(); ++i)
	    for (size_t j = 0; j < matrix[i].size(); ++j)
		dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + matrix[i][j];
    }

    int sumRegion(size_t row1, size_t col1, size_t row2, size_t col2)
    {
	return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }

private:
    std::vector<std::vector<int>> dp;
};

// time:
//  O(n * m) for constructor
//  O(m) for query
class NumMatrixCacheRow
{
public:
    NumMatrixCacheRow(vector<vector<int>>& matrix) :
	dp(matrix.size(), std::vector<int>(matrix.front().size()))
    {
	for (size_t i = 0; i < matrix.size(); ++i) {
	    for (size_t j = 0; j < matrix[i].size(); ++j) {
		dp[i][j] = matrix[i][j] + (j ? dp[i][j - 1] : 0);
	    }
	}
    }

    int sumRegion(size_t row1, size_t col1, size_t row2, size_t col2)
    {
	int sum = 0;
	for (size_t i = row1; i <= row2; ++i)
	    sum += dp[i][col2] - (col1 ? dp[i][col1 - 1] : 0);

	return sum;
    }

private:
    std::vector<std::vector<int>> dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(int argc, char** argv)
{
}
