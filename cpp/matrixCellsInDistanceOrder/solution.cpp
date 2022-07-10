// https://leetcode.com/problems/matrix-cells-in-distance-order/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r_center, int c_center) 
    {
	auto res = std::vector<std::vector<int>>();
	for (auto i = 0; i < rows; ++i)
	    for (auto j = 0; j < cols; ++j)
		res.push_back({i, j});

	auto c_dist = [r_center, c_center](const std::vector<int>& coor) {
	    return std::abs(r_center - coor.front()) + std::abs(c_center - coor.back());
	};
	auto cmp = [c_dist](const auto &lhs, const auto &rhs) {
	    return c_dist(lhs) < c_dist(rhs);
	};

	std::sort(begin(res), end(res), cmp);
	return res;
    }
};

int main(int argc, char** argv)
{
}
