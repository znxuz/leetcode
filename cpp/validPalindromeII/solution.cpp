// https://leetcode.com/problems/valid-palindrome-ii/

#include <iostream>
#include <iterator>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool validPalindrome(string s)
	{
		return (s.empty() ? true : backtrack(s, 0, s.size() - 1, 1));
	}

private:
	// time: O(n)
	// space: O(n)
	bool backtrack(const std::string& s, size_t lo, size_t hi, size_t chance)
	{
		if (lo >= hi)
			return true;
		else if (s[lo] == s[hi])
			return backtrack(s, lo + 1, hi - 1, chance);
		return chance && (backtrack(s, lo + 1, hi, 0) || backtrack(s, lo, hi - 1, 0));
	}
};

int main(int argc, char** argv)
{
	std::string s = "abc";
	std::cout << Solution().validPalindrome(s) << '\n';
}
