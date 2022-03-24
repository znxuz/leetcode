// https://leetcode.com/problems/power-of-two/

#include <iostream>
#include <limits>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	// time: O(1)
	bool isPowerOfTwo(int n)
	{
		return no_loop(n);
	}

	bool no_loop(int n)
	{
		return n > 0 && !(n & (n - 1));
	}

	bool bit_check(int n)
	{
		int cnt = 0;
		while (n > 0 && cnt < 2)
			cnt += (n & 1), n >>= 1;

		return n == 0 && cnt == 1;
	}
};

int main(int argc, char** argv)
{
	Solution s;
	int n = 3;
	for (size_t i = 0; i < 10; ++i)
		std::cout << s.isPowerOfTwo(n) << '\n', n <<= 1;
}
