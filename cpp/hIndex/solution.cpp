// https://leetcode.com/problems/h-index/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    // h-index: h papers have at least h citations
    int hIndex(vector<int>& citations) 
    {
	return sort(citations);
    }

private:
    // time: O(nlog(n))
    // space: O(n)
    int sort(std::vector<int>& citations)
    {
	std::sort(begin(citations), end(citations));

	auto n = citations.size();
	auto i = size_t(0);
	while (i < n && n - i > citations[i])
	    ++i;

	return n - i;
    }
};

void test(std::vector<int> c)
{
    std::cout << Solution().hIndex(c) << '\n';
}

int main(int argc, char** argv)
{
    test({3, 0, 6, 1, 5});
    test({1, 3, 1});
    test({100});
    test({4, 4, 0, 0});
}
