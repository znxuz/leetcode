// https://leetcode.com/problems/height-checker/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int heightChecker(vector<int>& heights) 
    {
	return sort_and_compare(heights);
    }

private:
    int counting_sort(const std::vector<int>& heights)
    {
	auto sorted = std::array<int, 101>();
	for (auto h : heights)
	    ++sorted[h];

	auto min_idx = 0ul;
	auto cnt = 0;
	for (auto h : heights) {
	    while (!sorted[min_idx])
		++min_idx;
	    if (min_idx != h)
		++cnt;
	    --sorted[min_idx];
	}

	return cnt;
    }

    int sort_and_compare(const std::vector<int>& heights)
    {
	auto sorted = heights;
	std::sort(begin(sorted), end(sorted));
	auto res = 0;
	for (auto i = 0ul; i < sorted.size(); ++i)
	    res += (sorted[i] == heights[i] ? 0 : 1);
	return res;
    }
};

int main(int argc, char **argv)
{
}
