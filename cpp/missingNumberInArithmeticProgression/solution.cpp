// https://leetcode.com/problems/missing-number-in-arithmetic-progression/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int missingNumber(vector<int>& arr) 
    {
	return bsearch(arr);
    }

private:
    int bsearch(const std::vector<int> &arr)
    {
	auto progression = (arr.back() - arr.front()) / static_cast<int>(arr.size());
	auto lo = 0ul, hi = arr.size() - 1;
	while (hi < arr.size() && lo < hi) {
	    auto md = lo + (hi - lo) / 2;
	    if (arr[md] == arr.front() + progression * md)
		lo = md + 1;
	    else
		hi = md;
	}
	
	return arr.front() + progression * lo;
    }

    int linear(const std::vector<int> &arr)
    {
	auto progression = (arr.back() - arr.front()) / static_cast<int>(arr.size());
	auto prev = arr.front();
	for (auto i = 1ul; i < arr.size(); ++i) {
	    auto next = prev + progression;
	    if (arr[i] != next)
		return next;
	    prev = next;
	}
	return arr.front();
    }
};

int main(int argc, char **argv)
{
}
