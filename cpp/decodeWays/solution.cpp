// https://leetcode.com/problems/decode-ways/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int numDecodings(string s)
	{
		return dp_const_space(s);
	}

private:
	// time: O(n)
	// space: O(1)
	int dp_const_space(const std::string& s)
	{
		int cur = 1;
		int prev = 1;
		size_t n = s.size();
		for (size_t i = n; i-- > 0; ) {
			int sum;
			if (s[i] == '0') {
				sum = 0;
			} else {
				sum = cur;
				if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
					sum += prev;
			}
			prev = cur;
			cur = sum;
		}

		return cur;
	}
	
	// time: O(n)
	// space: O(n)
	int dp_iter(const std::string& s)
	{
		if (s.empty() || s.front() == '0')
			return 0;

		size_t n = s.size();
		std::vector<int> dp(n + 1, 0);
		dp.back() = 1;
		for (size_t i = n; i-- > 0;) {
			if (s[i] == '0') {
				dp[i] = 0;
			} else {
				dp[i] = dp[i + 1];
				if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
					dp[i] += dp[i + 2];
			}
		}

		return dp.front();
	}

	// time: O(n)
	// space: O(n)
	int dp_memoi(const std::string& s, size_t i, std::vector<int>& memoi)
	{
		if (i == s.size())
			return 1;
		if (s[i] == '0')
			return 0;
		int res = (memoi[i + 1] ? memoi[i + 1] : memoi[i + 1] = dp_memoi(s, i + 1, memoi));
		if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
			res += (memoi[i + 2] ? memoi[i + 2] : memoi[i + 2] = dp_memoi(s, i + 2, memoi));
		return res;
	}
};

int main(int argc, char** argv)
{
	std::string s = "12";
	std::cout << Solution().numDecodings(s) << '\n';
}
