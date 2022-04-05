// https://leetcode.com/problems/valid-word-abbreviation/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool validWordAbbreviation(string word, string abbr)
	{
		size_t i = 0;
		size_t cnt = 0;
		for (char c : abbr) {
			if (std::isdigit(c)) {
				cnt = cnt * 10 + c - '0';
				if (cnt == 0)
					return false;
			} else {
				i += std::exchange(cnt, 0);
				if (i >= word.size() || word[i++] != c)
					return false;
			}
		}

		return i + cnt == word.size();
	}
};

int main(int argc, char** argv)
{
	// l2t
	// leet
	auto word = "internationalization";
	auto abbr = "i12iz4n";
	std::cout << Solution().validWordAbbreviation(word, abbr) << '\n';
}
