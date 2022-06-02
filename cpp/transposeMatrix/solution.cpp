// https://leetcode.com/problems/transpose-matrix/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
	if (matrix.size() == matrix.front().size()) {
	    in_place(matrix);
	    return matrix;
	}

	std::vector<std::vector<int>> res(matrix.front().size(),
		std::vector<int>(matrix.size()));

	for (size_t i = 0; i < matrix.size(); ++i) {
	    for (size_t j = 0; j < matrix[i].size(); ++j)
		res[j][i] = matrix[i][j];
	}

	return res;
    }

private:
    void in_place(std::vector<std::vector<int>>& matrix)
    {
	for (size_t i = 0; i < matrix.size(); ++i) {
	    for (size_t j = i + 1; j < matrix.size(); ++j)
		std::swap(matrix[i][j], matrix[j][i]);
	}
    }
};

int main(int argc, char** argv)
{
}
