// https://leetcode.com/problems/set-matrix-zeroes/

#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		void setZeroes(vector<vector<int>>& matrix)
		{
			optimal(matrix);
		}

	private:
		// use first row and col as markers for clearing later
		// time: O(n * m)
		// space: O(1)
		void optimal(vector<vector<int>>& matrix)
		{
			size_t n = matrix.size();
			size_t m = matrix[0].size();
			bool clear_first_row = false;
			bool clear_first_col = false;

			for (size_t i = 0; i < n; ++i) {
				if (matrix[i][0] == 0)
					clear_first_row = true;
				for (size_t j = 0; j < m; ++j) {
					if (i == 0 && matrix[i][j] == 0)
						clear_first_col = true;
					if (matrix[i][j] == 0) {
						matrix[i][0] = 0;
						matrix[0][j] = 0;
					}
				}
			}

			for (size_t i = 1; i < n; ++i) {
				if (matrix[i][0] == 0)
					for (size_t j = 0; j < m; ++j)
						matrix[i][j] = 0;
			}
			for (size_t i = 1; i < m; ++i) {
				if (matrix[0][i] == 0)
					for (size_t j = 0; j < n; ++j)
						matrix[j][i] = 0;
			}

			if (clear_first_row)
				for (size_t i = 0; i < n; ++i)
					matrix[i][0] = 0;
			if (clear_first_col)
				for (size_t i = 0; i < m; ++i)
					matrix[0][i] = 0;
		}
		
		// time: O(n * m)
		// space: O(n + m)
		void improved(vector<vector<int>>& matrix)
		{
			size_t n = matrix.size();
			size_t m = matrix[0].size();
			unordered_set<size_t> rows;
			unordered_set<size_t> cols;

			for (size_t i = 0; i < n; ++i) {
				for (size_t j = 0; j < m; ++j) {
					if (matrix[i][j] == 0) {
						rows.insert(i);
						cols.insert(j);
					}
				}
			}
			for (auto row : rows)
				for (size_t i = 0; i < m; ++i)
					matrix[row][i] = 0;
			for (auto col : cols)
				for (size_t i{}; i < n; ++i)
					matrix[i][col] = 0;
		}

		// time: O(n * m)
		// space: O(n * m)
		void brute(vector<vector<int>>& matrix)
		{
			size_t n = matrix.size();
			size_t m = matrix[0].size();
			std::vector<std::pair<size_t, size_t>> indices;

			for (size_t i = 0; i < n; ++i) {
				for (size_t j = 0; j < m; ++j) {
					if (matrix[i][j] == 0)
						indices.push_back(std::make_pair(i, j));
				}
			}

			for (const auto& [row, col] : indices) {
				for (size_t i = (row + 1) % n; i != row; i = ++i % n)
					matrix[i][col] = 0;
				for (size_t i = (col + 1) % m; i != col; i = ++i % m)
					matrix[row][i] = 0;
			}
		}
};

int main(int argc, char** argv)
{
}
