// https://leetcode.com/problems/toeplitz-matrix/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
	return follow_up1(matrix);
    }

    bool compare_upper_left(const std::vector<std::vector<int>>& matrix)
    {
	for (size_t i = 0; i < matrix.size(); ++i) {
	    for (size_t j = 0; j < matrix[i].size(); ++j) {
		if (i != 0 && j != 0 && matrix[i][j] != matrix[i - 1][j - 1])
		    return false;
	    }
	}

	return true;
    }

    bool follow_up1(const std::vector<std::vector<int>>& matrix)
    {
	std::vector<int> prev;
	for (size_t i = 0; i < matrix.size(); ++i) {
	    if (!prev.empty()) {
		for (size_t j = 1; j < matrix[i].size(); ++j)
		    if (prev[j - 1] != matrix[i][j])
			return false;
	    }
	    prev = matrix[i];
	}

	return true;
    }
};

int main(int argc, char** argv)
{
}
