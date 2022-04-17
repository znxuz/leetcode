// https://leetcode.com/problems/interleaving-string/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		return dp(s1, s2, s3);
	}

private:
	bool dp(const std::string& s1, const std::string& s2, const std::string& s3)
	{
		if (s1.size() + s2.size() != s3.size())
			return false;

		std::vector<std::vector<bool>> dp(s1.size() + 1, std::vector<bool>(s2.size() + 1));
		for (size_t i = 0; i <= s1.size(); ++i) {
			for (size_t j = 0; j <= s2.size(); ++j) {
				if (i == 0 && j == 0)
					dp[i][j] = true;
				else if (i == 0)
					dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
				else if (j == 0)
					dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
				else
					dp[i][j] = ((dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]));
			}
		}

		return dp.back().back();
	}

	bool brute_force_TLE(const std::string& s1, size_t i,
			const std::string& s2, size_t j,
			const std::string& cmp, size_t k)
	{
		if (k == cmp.size())
			return i == s1.size() && j == s2.size();
		if (i == s1.size() && j == s2.size())
			return false;
		if (i == s1.size() && s2[j] == cmp[k])
			return brute_force_TLE(s1, i, s2, j + 1, cmp, k + 1);
		if (j == s2.size() && s1[i] == cmp[k])
			return brute_force_TLE(s1, i + 1, s2, j, cmp, k + 1);
		if (s1[i] != cmp[k] && s2[j] != cmp[k])
			return false;

		bool res = false;
		if (s1[i] == cmp[k])
			res |= brute_force_TLE(s1, i + 1, s2, j, cmp, k + 1);
		if (s2[j] == cmp[k])
			res |= brute_force_TLE(s1, i, s2, j + 1, cmp, k + 1);
		return res;
	}
};

int main(int argc, char** argv)
{
	std::string s1 = "aabcc";
	std::string s2 = "dbbca";
	std::string s3 = "aadbbcbcac";
	std::cout << Solution().isInterleave(s1, s2, s3) << '\n';
}
