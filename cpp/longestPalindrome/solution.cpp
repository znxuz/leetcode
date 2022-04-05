// https://leetcode.com/problems/longest-palindrome/

#include <array>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int longestPalindrome(string s)
	{
		return counting(s);
	}

private:
	int counting(const string& s)
	{
		std::array<int, 128> cnts{};
		for_each(begin(s), end(s), [&cnts](char c) { ++cnts[c]; });

		int max_len = 0;
		for (int cnt : cnts)
			max_len += cnt + (cnt & 1 ? -1 : 0);

		if (max_len < s.size())
			++max_len;
		return max_len;
	}
};

int main(int argc, char** argv)
{
}
