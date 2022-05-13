// https://leetcode.com/problems/shortest-completing-word/

#include <array>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    // time: O(n * m)
    // space: O(1) ?
    string shortestCompletingWord(string license_plate, vector<string>& words)
    {
	auto cnts = get_counts(license_plate);

	std::string res;
	for (const auto& w : words) {
	    auto cmp = get_counts(w);
	    size_t i = 0;
	    while (i < cnts.size()) {
		if (cnts[i] > 0 && cmp[i] < cnts[i])
		    break;
		++i;
	    }
	    if (i == cnts.size() && (res.empty() || res.size() > w.size()))
		res = w;
	}

	return res;
    }

private:
    std::array<int, 26> get_counts(const std::string& w)
    {
	std::array<int, 26> cnts{};
	for (char c : w) {
	    if (std::isalpha(c))
		++cnts[std::tolower(c) - 'a'];
	}

	return cnts;
    }
};

int main(int argc, char** argv)
{

}
