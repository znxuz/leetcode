// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		int maxProfit(vector<int>& prices)
		{
			int min_price = prices[0];
			int max_profit = 0;
			for (size_t i = 0; i < prices.size(); ++i) {
				min_price = std::min(min_price, prices[i]);
				max_profit = std::max(max_profit, prices[i] - min_price);
			}

			return max_profit;
		}
};

int main(int argc, char** argv)
{
}
