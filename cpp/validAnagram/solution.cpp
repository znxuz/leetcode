// https://leetcode.com/problems/valid-anagram/

#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		return freq_table(s, t);
	}

	bool freq_table(const string& s, const string& t)
	{
		unordered_map<char, int> freq;
		size_t i = 0;
		for (; i < s.size() && i < t.size(); ++i) {
			++freq[s[i]];
			--freq[t[i]];
		}

		if (i != s.size() || i != t.size())
			return false;
		return std::none_of(begin(freq), end(freq), [](const auto& p) { return p.second != 0; });
	}

	bool counting_sort(const string& s, const string& t)
	{
		int cnts[26]{};
		for (size_t i = 0; i < s.size() || i < t.size(); ++i) {
			if (i == s.size() || i == t.size())
				return false;
			++cnts[s[i] - 'a'];
			--cnts[t[i] - 'a'];
		}
		for (auto c : cnts)
			if (c)
				return false;
		return true;
	}
};

int main(int argc, char** argv)
{
	if (-1)
		std::cout << "reached\n";
}
