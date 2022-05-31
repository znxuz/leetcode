// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

#include <cmath>
#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    bool hasAllCodes(string s, unsigned k)
    {
	return rolling_hash(s, k);
    }

private:
    // time: O(n)
    // space: O(2^k)
    bool rolling_hash(const std::string& s, unsigned k)
    {
	unsigned total = 1 << k;
	std::vector<bool> flags(total);
	unsigned mask = total - 1;
	unsigned hash = 0;
	for (size_t i = 0; i < s.size(); ++i) {
	    hash = ((hash << 1) & mask) | (s[i] - '0');
	    if (i >= k - 1 && !flags[hash]) {
		flags[hash] = true;
		if (!--total)
		    return true;
	    }
	}

	return false;
    }

    bool use_set(const std::string& s, unsigned k)
    {
	std::unordered_set<std::string> codes;
	for (size_t i = k - 1; i < s.size(); ++i)
	    codes.insert(s.substr(i + 1 - k, k));

	return static_cast<unsigned>(codes.size()) == (1 << k);
    }
};

int main(int argc, char** argv)
{
}
