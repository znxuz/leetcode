// https://leetcode.com/problems/sqrtx/

#include <iostream>
#include <vector>
#include <cmath>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		int mySqrt(int x)
		{
			return my_sqrt_rec(x);
		}

		int my_sqrt_binary_search(int x)
		{
			if (x < 2)
				return x;

			int lo = 2;
			int hi = x / 2;
			while (lo <= hi) {
				int md = lo + (hi - lo) / 2;
				long sq = static_cast<long>(md) * md;
				if (sq == x)
					return md;
				if (sq < x)
					lo = md + 1;
				else
					hi = md - 1;
			}

			return hi;
		}

		// top down recursion
		int my_sqrt_rec(int x)
		{
			if (x < 2)
				return x;

			int lo = my_sqrt_rec(x >> 2) << 1;
			int hi = lo + 1;
			return (static_cast<long>(hi) * hi > x ? lo : hi);
		}
};

int main(int argc, char** argv)
{
}
