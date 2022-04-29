// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int max = 0;
		for (size_t i = 1; i < prices.size(); ++i) {
			int diff = prices[i] - prices[i - 1];
			max += (diff > 0 ? diff : 0);
		}

		return max;
	}
};

int main(int argc, char** argv)
{
}
