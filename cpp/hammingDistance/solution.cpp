// https://leetcode.com/problems/hamming-distance/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int hammingDistance(int x, int y)
	{
		int cnt = 0;
		while (x || y) {
			cnt += (x & 1) ^ (y & 1);
			x >>= 1;
			y >>= 1;
		}

		return cnt;
	}

	int better_xor(int x, int y)
	{
		int res = x ^ y;
		int cnt = 0;
		while (res)
			cnt += res & 1, res >>= 1;

		return cnt;
	}
};

int main(int argc, char** argv)
{
}
