// https://leetcode.com/problems/detect-capital/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool detectCapitalUse(string word)
	{
		size_t upper = 0;
		for (char c : word) {
			if (std::isupper(c))
				++upper;
		}

		return (upper == word.size() || upper == 0 ||
				(upper == 1 && std::isupper(word.front())));
	}
};

int main(int argc, char** argv)
{
}
