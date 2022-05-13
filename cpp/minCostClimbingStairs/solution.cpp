// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
	if (cost.size() < 2)
	    return cost.empty() ? 0 : cost.front();

	int prev2 = cost[0];
	int prev1 = cost[1];
	for (size_t i = 2; i < cost.size(); ++i) {
	    int min = cost[i] + std::min(prev1, prev2);
	    prev2 = prev1;
	    prev1 = min;
	}

	return std::min(prev1, prev2);
    }
};

int main(int argc, char** argv)
{
}
