// https://leetcode.com/problems/first-bad-version/

#include <iostream>
#include <vector>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

bool isBadVersion(int version);

class Solution
{
	public:
		int firstBadVersion(int n)
		{
			int lo = 1;
			int hi = n;
			while (lo < hi) {
				int md = lo + (hi - lo) / 2;
				if (isBadVersion(md))
					hi = md;
				else
					lo = md + 1;
			}

			return lo;
		}
};

int main(int argc, char** argv)
{
}
