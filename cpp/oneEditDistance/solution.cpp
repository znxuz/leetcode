// https://leetcode.com/problems/one-edit-distance/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    bool isOneEditDistance(string s, string t)
    {
	return dp(s, t);
    }

private:
    bool dp(const std::string& s, const std::string& t)
    {
	size_t n = s.size();
	size_t m = t.size();
	if (n > m)
	    return dp(t, s);

	for (size_t i = 0; i < n; ++i) {
	    if (s[i] != t[i]) {
		if (n == m)
		    return s.substr(i + 1) == t.substr(i + 1);
		return s.substr(i) == t.substr(i + 1);
	    }
	}

	return n + 1 == m;
    }

    // time: O(n)
    // space: O(n)
    bool brute_force(const std::string& s, size_t i,
	    const std::string& t, size_t j, bool chance)
    {
	if (i == s.size() && j == t.size())
	    return !chance;
	if (i == s.size() || j == t.size())
	    return chance && i + 1 >= s.size() && j + 1 >= t.size(); // possible overflow
	if (s[i] == t[j])
	    return brute_force(s, ++i, t, ++j, chance);
	if ((chance = !chance))
	    return false;
	return brute_force(s, i + 1, t, j, chance)
	    || brute_force(s, i, t, j + 1, chance)
	    || brute_force(s, ++i, t, ++j, chance);
    }
};

int main(int argc, char** argv)
{
}
