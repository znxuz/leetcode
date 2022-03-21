// https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <limits>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		void rotate(vector<vector<int>>& matrix)
		{
			transpose(matrix);
			horizontal_invert(matrix);
		}

		void transpose(vector<vector<int>>& matrix)
		{
			for (size_t i = 0; i < matrix.size(); ++i)
				for (size_t j = i; j < matrix.size(); ++j)
					std::swap(matrix[i][j], matrix[j][i]);
		}

		void horizontal_invert(vector<vector<int>>& matrix)
		{
			size_t n = matrix.size();
			for (size_t i = 0; i < n; ++i)
				for (size_t j = 0; j < n / 2; ++j)
					std::swap(matrix[i][j], matrix[i][n - j - 1]);
		}
};

static void print_matrix(const std::vector<std::vector<int>>& matrix)
{
	for (const auto& row : matrix)
		iter_print(begin(row), end(row));
}

int main(int argc, char** argv)
{
	Solution s;
	std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	print_matrix(matrix);
	s.horizontal_invert(matrix);
	print_matrix(matrix);
}
