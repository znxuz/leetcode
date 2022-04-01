// https://leetcode.com/problems/word-pattern/

#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool wordPattern(string pattern, string s)
	{
		return manual_split(pattern, s);
	}

private:
	bool manual_split(const std::string& pat, const std::string& s)
	{
		std::unordered_map<char, std::string> map;
		std::unordered_set<std::string> mapped;

		string word;
		size_t idx = 0;
		for (size_t i = 0; i < s.size() || !word.empty(); ++i) {
			if (i < s.size() && s[i] != ' ') {
				word.push_back(s[i]);
			} else {
	 			if (map.count(pat[idx])) {
					if (map.at(pat[idx]) != word)
						return false;
				} else if (!mapped.insert(word).second)
					return false;
				map[pat[idx]] = word;
				++idx;
				word.clear();
			}
		}

		return idx == pat.size();
	}
};

int main(int argc, char** argv)
{
	std::string pat = "abba";
	std::string s = "dog cat cat dog";
	std::cout << std::boolalpha << Solution().wordPattern(pat, s) << '\n';
}
