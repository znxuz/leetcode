// https://leetcode.com/problems/backspace-string-compare/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	// time: O(n)
	// space: O(1)
	bool backspaceCompare(string s, string t)
	{
	    size_t i = s.size() - 1;
	    size_t j = t.size() - 1;
	    while (i < s.size() || j < t.size()) {
		size_t s_cnt = 0;
		size_t t_cnt = 0;
		while (i < s.size() && (s[i] == '#' || s_cnt))
		    s_cnt = (s[i--] == '#' ? ++s_cnt : --s_cnt);
		while (j < t.size() && (t[j] == '#' || t_cnt))
		    t_cnt = (t[j--] == '#' ? ++t_cnt : --t_cnt);

		if (i >= s.size() || j >= t.size())
		    break;
		if (s[i--] != t[j--])
		    return false;
	    }

	    return i >= s.size() && j >= t.size();
	}
};

int main(int argc, char** argv)
{
    std::string s = "ab##";
    std::string t = "c#d#";
    std::cout << Solution().backspaceCompare(s, t);
}
