// https://leetcode.com/problems/unique-binary-search-trees/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int numTrees(size_t n)
	{
		std::vector<int> dp(n + 1);
		dp[0] = 1;
		dp[1] = 1;
		// T[2] = T[1] + T[1]
		for (size_t i = 2; i <= n; ++i) {
			for (size_t j = 0; j < i; ++j) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}

		return dp[n];
	}
};

int main(int argc, char** argv)
{
}
