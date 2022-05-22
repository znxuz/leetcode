// https://leetcode.com/problems/rotate-string/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
	return s.size() == goal.size() && (goal + goal).find(s) != std::string::npos;
    }

private:
    // time: O(n^2)
    // spcae: O(1)
    bool check_by_shift(std::string s, std::string goal)
    {
	if (s.size() != goal.size())
	    return false;
	if (s.empty())
	    return true;

	auto sz = s.size();
	for (size_t i = 0; i < sz; ++i) {
	    size_t j = 0;
	    while (j < sz && s[(i + j) % sz] == goal[j])
		++j;
	    if (j == sz)
		return true;
	}

	return false;
    }
};

int main(int argc, char** argv)
{
}
