// https://leetcode.com/problems/perfect-squares/

#include <limits>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int numSquares(int n)
    {
	return dp(n);
    }

private:
    int dp(int n)
    {
	std::vector<int> squares(get_square_nums(n));
	std::vector<int> dp(static_cast<size_t>(n) + 1,
		std::numeric_limits<int>::max());

	dp[0] = 0;
	for (size_t i = 1; i < dp.size(); ++i) {
	    for (size_t j = 1; j < squares.size() && squares[j] <= i; ++j) {
		dp[i] = std::min(dp[i], dp[i - squares[j]] + 1);
	    }
	}

	return dp.back();
    }

    // TLE
    int brute_force(int n)
    {
	return rec(n, get_square_nums(n));
    }

    int rec(int n, const std::vector<int>& squares)
    {
	if (std::binary_search(begin(squares), end(squares), n))
	    return 1;

	int min = std::numeric_limits<int>::max();
	for (int sqr : squares) {
	    if (sqr > n)
		break;
	    int cnt = rec(n - sqr, squares) + 1;
	    min = std::min(min, cnt);
	}

	return min;
    }

    std::vector<int> get_square_nums(int n)
    {
	std::vector<int> squares(static_cast<size_t>(std::sqrt(n) + 1));
	for (size_t i = 1; i < squares.size(); ++i)
	    squares[i] = static_cast<int>(std::pow(i, 2));
	return squares;
    }
};

int main(int argc, char** argv)
{
    Solution s;
    for (int i = 1; i < 5; ++i)
	std::cout << s.numSquares(i) << '\n';
}
