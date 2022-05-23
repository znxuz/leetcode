// https://leetcode.com/problems/valid-perfect-square/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
	return binary_search(num);
    }

private:
    bool binary_search(int num)
    {
	long lo = 1;
	long hi = num;
	while (lo <= hi) {
	    long md = lo + (hi - lo) / 2;
	    long res = md * md;
	    if (res == num)
		return true;
	    if (res < num)
		lo = md + 1;
	    else
		hi = md - 1;
	}

	return false;
    }
};

int main(int argc, char** argv)
{
}
