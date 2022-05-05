// https://leetcode.com/problems/image-smoother/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& img)
	{
	    if (img.empty() || img.front().empty())
		return img;

	    std::vector<std::vector<int>> res(img.size(), std::vector<int>(img[0].size()));
	    for (size_t i = 0; i < img.size(); ++i) {
		for (size_t j = 0; j < img[i].size(); ++j) {
		    res[i][j] = smooth(img, i, j);
		}
	    }

	    return res;
	}

    private:
	int smooth(const std::vector<std::vector<int>>& img, size_t i, size_t j)
	{
	    size_t row = std::min(i - 1, i);
	    size_t col = std::min(j - 1, j);
	    size_t cnt = 0;
	    double sum = 0;
	    for (size_t k = row; k < std::min(i + 2, img.size()); ++k) {
		for (size_t l = col; l < std::min(j + 2, img[i].size()); ++l) {
		    sum += img[k][l];
		    ++cnt;
		}
	    }

	    return sum / cnt;
	}
};

int main(int argc, char** argv)
{
}
