// https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/

#include <numeric>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int countLetters(string s) 
    {
	return dp(s);
    }

    int dp(const std::string& s)
    {
	auto dp = std::vector<unsigned>(s.size());
	for (auto i = 0ul; i < s.size(); ++i)
	    dp[i] = (!i || s[i] != s[i - 1] ? 1 : dp[i - 1] + 1);

	return std::accumulate(begin(dp), end(dp), 0, std::plus<int>());
    }

    int gauss_formula(const std::string& s)
    {
	auto res = 0;
	auto prev = 0;
	auto cnt = 0;
	for (auto i = 0ul; i < s.size(); ++i) {
	    if (!i || s[i] == prev) {
		++cnt;
	    } else {
		res += gauss(std::exchange(cnt, 1));
	    }
	    prev = s[i];
	}

	return res + gauss(cnt);
    }

private:
    int gauss(int n)
    {
	return n * (n + 1) / 2;
    }
};

int main(int argc, char **argv)
{
}
