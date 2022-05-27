// https://leetcode.com/problems/shortest-distance-to-a-character/

#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
	return two_ways(s, c);
    }

private:
    std::vector<int> two_ways(const std::string& s, char c)
    {
	std::vector<int> res(s.size(), std::numeric_limits<int>::max());
	size_t prev = s.size();
	auto valid = [size = s.size()](size_t idx) { return idx < size; };
	for (size_t i = 0; i < s.size(); ++i) {
	    if (s[i] == c)
		prev = i;
	    if (valid(prev))
		res[i] = static_cast<int>(i - prev);
	}
	prev = s.size();
	for (size_t i = s.size(); i-- > 0;) {
	    if (s[i] == c)
		prev = i;
	    if (valid(prev))
		res[i] = std::min(res[i], static_cast<int>(prev - i));
	}

	return res;
    }

    std::vector<int> two_ptrs(const std::string& s, char c)
    {
	std::vector<int> res(s.size(), std::numeric_limits<int>::max());
	size_t lo = s.size();
	size_t hi = 0;
	while (hi < s.size() && s[hi] != c)
	    ++hi;
	for (size_t i = 0; i < s.size(); ++i) {
	    if (lo < s.size())
		res[i] = std::min(res[i], static_cast<int>(i - lo));
	    if (hi < s.size())
		res[i] = std::min(res[i], static_cast<int>(hi - i));
	    if (s[i] == c) {
		lo = hi++;
		while (hi < s.size() && s[hi] != c)
		    ++hi;
	    }
	}

	return res;
    }
};

int main(int argc, char** argv)
{
}
