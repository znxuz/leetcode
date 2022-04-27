// https://leetcode.com/problems/reshape-the-matrix/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	// time: O(n * m)
	// space: O(1)
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, size_t r, size_t c)
	{
		return divide_mod(mat, r, c);
	}

private:
	std::vector<std::vector<int>> divide_mod(const std::vector<std::vector<int>>& mat,
			size_t r, size_t c)
	{
		size_t total = 0;
		for (const auto& row : mat)
			total += row.size();
		if (total != r * c)
			return mat;

		std::vector<std::vector<int>> res(r, std::vector<int>(c, 0));
		size_t cnt = 0;
		for (size_t i = 0; i < mat.size(); ++i) {
			for (size_t j = 0; j < mat[i].size(); ++j) {
				res[cnt / c][cnt % c] = mat[i][j];
				++cnt;
			}
		}

		return res;
	}

	std::vector<std::vector<int>> sep_idx(const std::vector<std::vector<int>>& mat,
			size_t r, size_t c)
	{
		size_t total = 0;
		for (const auto& row : mat)
			total += row.size();
		if (total != r * c)
			return mat;

		std::vector<std::vector<int>> res(r, std::vector<int>(c, 0));
		r = c = 0;
		for (size_t i = 0; i < mat.size(); ++i) {
			for (size_t j = 0; j < mat[i].size(); ++j) {
				res[r][c] = mat[i][j];
				c = ++c % res[r].size();
				if (!c)
					++r;
			}
		}

		return res;
	}
};

int main(int argc, char** argv)
{
}
