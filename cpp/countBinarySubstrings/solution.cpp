// https://leetcode.com/problems/count-binary-substrings/

#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	int countBinarySubstrings(string s)
	{
	    int res = 0;
	    int prev = 0;
	    int cur = 1;
	    for (size_t i = 1; i < s.size(); ++i) {
		if (s[i] == s[i - 1])
		    ++cur;
		else
		    res += std::min(std::exchange(prev, cur), std::exchange(cur, 1));
	    }

	    return res + std::min(prev, cur);
	}
};

int main(int argc, char** argv)
{
}
