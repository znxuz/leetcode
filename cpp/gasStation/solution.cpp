// https://leetcode.com/problems/gas-station/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
	    size_t start = 0;
	    int tank = 0;
	    int debt = 0;
	    for (size_t i = 0; i < cost.size(); ++i) {
		tank += gas[i] - cost[i];
		if (tank < 0) {
		    debt += tank;
		    tank = 0;
		    start = i + 1;
		}
	    }

	    return (tank + debt >= 0 ? start : -1);
	}
};

int main(int argc, char** argv)
{
}
