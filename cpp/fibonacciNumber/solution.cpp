// https://leetcode.com/problems/fibonacci-number/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int fib(int n) 
    {
	auto memo = std::vector<int>(n + 1);
	return memoization(n, memo);
    }

private:
    int memoization(int n, std::vector<int>& memo)
    {
	if (n < 2)
	    return n;
	if (memo[n])
	    return memo[n];
	memo[n] = memoization(n - 1, memo) + memoization(n - 2, memo);
	return memo[n];
    }

    int dp(int n)
    {
	if (n < 2)
	    return n;

	int pp = 0;
	int p = 1;
	while (n-- - 1) {
	    auto tmp = p + pp;
	    pp = p;
	    p = tmp;
	}
	return p;
    }
};

int main(int argc, char** argv)
{
    auto s = Solution();
    for (auto i = 0; i < 10; ++i)
	std::cout << s.fib(i) << '\n';
}
