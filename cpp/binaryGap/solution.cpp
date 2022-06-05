// https://leetcode.com/problems/binary-gap/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int binaryGap(int n)
    {
	int max = 0;
	int cur = 0;
	int prev = -1;
	while (n) {
	    if (n & 1) {
		if (prev != -1)
		    max = std::max(max, cur - prev);
		prev = cur;
	    }
	    ++cur;
	    n >>= 1;
	}

	return max;
    }
};

int main(int argc, char** argv)
{
}
