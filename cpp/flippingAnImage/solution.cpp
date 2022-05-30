// https://leetcode.com/problems/flipping-an-image/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
    {
	for (auto& row : image) {
	    size_t n = row.size();
	    for (size_t i = 0; i < (n + 1) / 2; ++i) {
		int tmp = (row[i] == 0); // row[i] ^ 1
		row[i] = (row[n - i - 1] == 0);
		row[n - i - 1] = tmp;
	    }
	}

	return image;
    }

private:
    void flip(std::vector<std::vector<int>>& image)
    {
	for (auto& row : image) {
	    for (size_t i = 0, j = row.size() - 1; i < j; ++i, --j)
		std::swap(row[i], row[j]);
	}
    }

    void invert(std::vector<std::vector<int>>& image)
    {
	for (auto& row : image) {
	    for (auto& cell : row)
		cell = (cell == 0);
	}
    }
};

int main(int argc, char** argv)
{
}
