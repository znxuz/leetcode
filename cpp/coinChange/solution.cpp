// https://leetcode.com/problems/coin-change/

#include <limits>
#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
	return dp_bottomup(coins, amount);
    }

private:
    int dp_bottomup(const std::vector<int>& coins, int amount)
    {
	int limit = amount + 1;
	std::vector<int> dp(static_cast<size_t>(limit), limit);
	dp[0] = 0;
	for (int rem = 1; rem <= amount; ++rem) {
	    for (int c : coins) {
		if (c <= rem)
		    dp[rem] = std::min(dp[rem], dp[rem - c] + 1);
	    }
	}

	return (dp.back() == limit ? -1 : dp.back());
    }

    int dp_topdown(const std::vector<int>& coins, int amount, std::vector<int>& cnts)
    {
	if (!amount)
	    return 0;
	if (amount < 0)
	    return -1;
	if (cnts[amount - 1])
	    return cnts[amount - 1];

	int min = std::numeric_limits<int>::max();
	for (auto c : coins) {
	    int res = dp_topdown(coins, amount - c, cnts);
	    if (res != -1 && res < min)
		min = res + 1;
	}

	cnts[amount - 1] = (min == std::numeric_limits<int>::max() ? -1 : min);
	return cnts[amount - 1];
    }

    // TLE
    int brute_force_backtrack(const std::vector<int>& coins, size_t idx, int amount)
    {
	int min = std::numeric_limits<int>::max();
	for (size_t i = idx; i < coins.size(); ++i) {
	    int rest = amount % coins[i];
	    int cnt = amount / coins[i];
	    if (!rest)
		min = std::min(min, cnt);
	    while (cnt > 0 && cnt < min) {
		int search = brute_force_backtrack(coins, i + 1, rest);
		if (search != -1) {
		    min = std::min(min, cnt + search);
		}

		--cnt;
		rest += coins[i];
	    }
	}

	return (min != std::numeric_limits<int>::max() ? min : -1);
    }
};

void test(std::vector<int> coins, int amount)
{
    Solution s;
    std::cout << s.coinChange(coins, amount) << '\n';
}

int main(int argc, char** argv)
{
    test({1, 2, 5}, 11);
}
