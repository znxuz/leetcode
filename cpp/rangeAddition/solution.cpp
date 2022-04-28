// https://leetcode.com/problems/range-addition-ii/

#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int maxCount(int m, int n, vector<vector<int>>& ops)
	{
		for (const auto& op : ops) {
			m = std::min(m, op[0]);
			n = std::min(n, op[1]);
		}
		return m * n;
	}
};

int main(int argc, char** argv)
{
}
