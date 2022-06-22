// https://leetcode.com/problems/h-index-ii/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
	auto n = citations.size();
	auto lo = 0ul;
	auto hi = n - 1;
	while (hi < n && lo <= hi) {
	    auto md = lo + (hi - lo) / 2;
	    auto diff = n - md;
	    if (citations[md] == diff)
		return diff;
	    if (citations[md] < diff)
		lo = md + 1;
	    else
		hi = md - 1;
	}

	return n - lo;
    }
};

void test(std::vector<int> c)
{
    std::sort(begin(c), end(c));
    std::cout << Solution().hIndex(c) << '\n';
}

int main(int argc, char** argv)
{
    test({3, 0, 6, 1, 5});
    test({1, 3, 1});
    test({100});
    test({4, 4, 0, 0});
    test({1, 2, 100});
    test({0});
    test({0, 1});
    test({11, 15});
}
