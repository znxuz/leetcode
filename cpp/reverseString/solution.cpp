// https://leetcode.com/problems/reverse-string/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	void reverseString(vector<char>& s)
	{
		size_t n = s.size();
		for (size_t i = 0; i < n / 2; ++i)
			std::swap(s[i], s[n - i - 1]);
		// std::reverse(begin(s), end(s));
	}
};

int main(int argc, char** argv)
{
}
