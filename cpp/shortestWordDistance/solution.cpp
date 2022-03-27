// https://leetcode.com/problems/shortest-word-distance/

#include <ios>
#include <iostream>
#include <limits>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	// time: O(n)
	// space: O(1)
	int shortestDistance(vector<string>& wordsDict, string word1, string word2)
	{
		return improved(wordsDict, word1, word2);
	}

	int mine(const vector<string>& words, const string& w1, const string& w2)
	{
		string anchor;
		size_t pos;
		size_t min = std::numeric_limits<size_t>::max();
		for (size_t i = 0; i < words.size(); ++i) {
			const auto& word = words[i];
			if (word == w1 || word == w2) {
				if (!anchor.empty() && word != anchor)
					min = std::min(min, i - pos);
				anchor = word;
				pos = i;
			}
		}

		return static_cast<int>(min);
	}

	int improved(const vector<string>& words, const string w1, const string w2)
	{
		size_t max, i1, i2, min;
		i1 = i2 = max = std::numeric_limits<size_t>::max();
		for (size_t i = 0; i < words.size(); ++i) {
			const auto& w = words[i];
			if (w == w1)
				i1 = i;
			if (w == w2)
				i2 = i;
			if (i1 != max && i2 != max)
				min = std::min(min, (i1 >= i2 ? i1 - i2 : i2 - i1));
		}

		return static_cast<int>(min);
	}
};

int main(int argc, char** argv)
{
}
