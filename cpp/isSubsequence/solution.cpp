// https://leetcode.com/problems/is-subsequence/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool isSubsequence(string s, string t)
	{
		return two_ptrs(s, t);
	}

private:
	bool two_ptrs(const std::string& s, const std::string& t)
	{
		size_t i = 0;
		size_t j = 0;
		while (i < s.size() && j < t.size()) {
			if (s[i] == t[j])
				++i;
			++j;
		}

		return i == s.size();
	}
};

int main(int argc, char** argv)
{
}
