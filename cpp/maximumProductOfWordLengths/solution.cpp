// https://leetcode.com/problems/maximum-product-of-word-lengths/

#include <algorithm>
#include <array>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    // time: O(n^2)
    // space: O(n)
    int maxProduct(vector<string>& words)
    {
	std::unordered_map<std::bitset<26>, size_t> mp;
	for (const auto& s : words) {
	    std::bitset<26> bits;
	    for_each(begin(s), end(s), [&bits](char c) { bits[c - 'a'] = true; });
	    mp[bits] = std::max(mp[bits], s.size());
	}

	size_t max = 0;
	for (const auto& [k1, v1] : mp) {
	    for (const auto& [k2, v2] : mp) {
		if ((k1 & k2) == std::bitset<26>())
		    max = std::max(max, v1 * v2);
	    }
	}

	return static_cast<int>(max);
    }
};

int main(int argc, char** argv)
{
}
