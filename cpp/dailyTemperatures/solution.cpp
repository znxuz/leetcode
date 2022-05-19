// https://leetcode.com/problems/daily-temperatures/

#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
	return optimal(temperatures);
    }

private:
    std::vector<int> optimal(const std::vector<int>& temperatures)
    {
	std::vector<int> res(temperatures.size());
	int hottest;
	for (size_t i = temperatures.size(); i-- > 0;) {
	    if (i + 1 == temperatures.size() || temperatures[i] >= hottest) {
		hottest = temperatures[i];
		continue;
	    }

	    size_t jump = 1;
	    while (temperatures[i + jump] <= temperatures[i])
		jump += res[i + jump];
	    res[i] = jump;
	}

	return res;
    }

    std::vector<int> use_stack(const std::vector<int>& temperatures)
    {
	std::vector<int> res(temperatures.size(), 0);
	std::stack<std::pair<int, size_t>> stk;
	for (size_t i = 0; i < temperatures.size(); ++i) {
	    while (!stk.empty() && stk.top().first < temperatures[i]) {
		res[stk.top().second] = i - stk.top().second;
		stk.pop();
	    }
	    stk.push(std::pair(temperatures[i], i));
	}

	return res;
    }
};

int main(int argc, char** argv)
{
}
