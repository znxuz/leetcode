// https://leetcode.com/problems/most-common-word/

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
    string mostCommonWord(string s, vector<string>& banned)
    {
	std::unordered_set<std::string> st(begin(banned), end(banned));
	std::unordered_map<std::string, size_t> freq;
	std::string res;
	size_t max = 0;
	std::string buf;
	for (size_t i = 0; i < s.size(); ++i) {
	    if (std::isalpha(s[i]))
		buf.push_back(static_cast<char>(std::tolower(s[i])));
	    if (!std::isalpha(s[i]) || i + 1 == s.size()) {
		if (!buf.empty() && !st.count(buf) && ++freq[buf] > max) {
		    max = freq[buf];
		    res = std::move(buf);
		}
		buf.clear();
	    }
	}

	return res;
    }
};

int main(int argc, char** argv)
{
}
