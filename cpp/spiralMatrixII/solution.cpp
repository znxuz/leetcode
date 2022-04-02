// https://leetcode.com/problems/spiral-matrix-ii/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		int row = n;
		int col = n;
		std::vector<std::vector<int>> res(row, std::vector<int>(col));
		int i = 0;
		int j = -1;
		int dir = 1;
		int cnt = 1;
		while (row > 0 && col > 0) {
			for (size_t k = 0; k < col; ++k) {
				j += dir;
				res[i][j] = cnt++;
			}
			--row;
			for (size_t k = 0; k < row; ++k) {
				i += dir;
				res[i][j] = cnt++;
			}
			--col;
			dir *= -1;
		}

		return res;
	}
};

int main(int argc, char** argv)
{
	auto res = Solution().generateMatrix(20);
	for (const auto& row : res)
		iter_print(begin(row), end(row));
}
