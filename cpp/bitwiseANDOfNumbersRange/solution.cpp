// https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
	int cnt = 0;
	while (left != right) {
	    left >>= 1;
	    right >>= 1;
	    ++cnt;
	}
	return left << cnt;
    }
};

int main(int argc, char** argv)
{
}
