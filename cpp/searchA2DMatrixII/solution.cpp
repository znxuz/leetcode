// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
	return optimal_space(matrix, target);
    }

private:
    // time: O(n + m)
    // space: O(1)
    bool optimal_space(const std::vector<std::vector<int>>& matrix, int target)
    {
	size_t n = matrix.size();
	size_t m = matrix.front().size();
	size_t i = 0;
	size_t j = m - 1;
	while (i < n && j < m) {
	    if (matrix[i][j] == target)
		return true;
	    if (matrix[i][j] > target)
		--j;
	    else
		++i;
	}

	return false;
    }

    // time: O(log(max(n, m)!))
    // space: O(1)
    bool binary_search(vector<vector<int>>& matrix, int target)
    {
	size_t n = matrix.size();
	size_t m = matrix.front().size();
	for (size_t i = 0, j = 0; i < n && j < m; ++i, ++j) {
	    if (matrix[i][j] > target)
		break;
	    if (matrix[i].back() >= target) {
		size_t lo = j;
		size_t hi = m - 1;
		while (hi < m && lo <= hi) {
		    size_t md = lo + (hi - lo) / 2;
		    if (matrix[i][md] == target)
			return true;
		    if (matrix[i][md] < target)
			lo = md + 1;
		    else
			hi = md - 1;
		}
	    }
	    if (matrix[n - 1][j] >= target) {
		size_t lo = i;
		size_t hi = n - 1;
		while (hi < n && lo <= hi) {
		    size_t md = lo + (hi - lo) / 2;
		    if (matrix[md][j] == target)
			return true;
		    if (matrix[md][j] < target)
			lo = md + 1;
		    else
			hi = md - 1;
		}
	    }
	}

	return false;
    }
};

int main(int argc, char** argv)
{
}
