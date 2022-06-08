// https://leetcode.com/problems/remove-palindromic-subsequences/

#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int removePalindromeSub(string s)
    {
	if (s.empty())
	    return 0;
	return std::equal(begin(s), end(s), rbegin(s)) ? 1 : 2;
    }

private:
    bool is_palindrome(const std::string& s)
    {
	size_t lo = 0;
	size_t hi = s.size() - 1;
	while (lo < hi)
	    if (s[lo++] != s[hi--])
		return false;
	return true;
    }
};

int main(int argc, char** argv)
{
}
