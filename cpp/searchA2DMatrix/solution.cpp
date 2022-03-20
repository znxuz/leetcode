// https://leetcode.com/problems/search-a-2d-matrix/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		// time: O(log(n) + log(m)) = O(log(n * m))
		// space: O(1)
		bool searchMatrix(const vector<vector<int>>& matrix, int target)
		{
			return single_search(matrix, target);
		}

		bool single_search(const std::vector<std::vector<int>>& matrix, int target)
		{
			int row = matrix.size();
			if (row == 0)
				return false;
			int col = matrix[0].size();

			int lo = 0;
			int hi = row * col - 1;
			while (lo <= hi) {
				int md = lo + (hi - lo) / 2;
				int val = matrix[md / col][md % col];
				if (val == target)
					return true;
				if (val < target)
					lo = md + 1;
				else
					hi = md - 1;
			}

			return false;
		}

		bool two_searches(const std::vector<std::vector<int>>& matrix, int target)
		{
			if (matrix.size() == 0)
				return false;

			int idx = 0;
			if (matrix.size() > 1) {
				size_t lo = 0;
				size_t hi = matrix.size() - 1;
				while (lo < hi - 1) {
					size_t md = lo + (hi - lo) / 2;
					if (matrix[md][0] == target)
						return md;
					if (matrix[md][0] < target)
						lo = md;
					else
						hi = md;
				}
				idx = (matrix[hi][0] <= target ? hi : lo);
			}

			const vector<int>& row = matrix[idx];
			int lo = 0;
			int hi = row.size() - 1;
			while (lo <= hi) {
				int md = lo + (hi - lo) / 2;
				if (row[md] == target)
					return true;
				if (row[md] < target)
					lo = md + 1;
				else
					hi = md - 1;
			}

			return false;
		}
};

static void test(const std::vector<std::vector<int>>& matrix, int target)
{
	Solution s;
	for (const auto& row : matrix)
		iter_print(begin(row), end(row));
	std::cout << s.searchMatrix(matrix, 3) << '\n';
}

int main(int argc, char** argv)
{
	// test({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 3);
	// test({{1}}, 3);
	test({{1}, {3}}, 3);
}
