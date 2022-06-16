// https://leetcode.com/problems/paint-house/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int minCost(vector<vector<int>>& costs) 
    {
	auto prev_costs = std::array<int, 3>();
	for (size_t i = 0; i < costs.size(); ++i) {
	    auto current_costs = std::array<int, 3>();
	    for (size_t j = 0; j < current_costs.size(); ++j)
		current_costs[j] = std::min(prev_costs[(j + 1) % 3], prev_costs[(j + 2) % 3])
		    + costs[i][j];
	    prev_costs = std::move(current_costs);
	}

	return *std::min_element(begin(prev_costs), end(prev_costs));
    }
};

int main(int argc, char** argv)
{
}
