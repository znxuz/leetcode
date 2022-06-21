// https://leetcode.com/problems/valid-mountain-array/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    bool validMountainArray(vector<int>& arr) 
    {
	if (arr.size() < 3)
	    return false;

	auto lo = 0ul;
	auto hi = arr.size() - 1;
	while (lo < hi) {
	    if (arr[lo + 1] > arr[lo])
		++lo;
	    else if (arr[hi - 1] > arr[hi])
		--hi;
	    else
		break;
	}
	return lo > 0 && hi < arr.size() - 1 && lo == hi;
    }
};

int main(int argc, char** argv)
{
}
