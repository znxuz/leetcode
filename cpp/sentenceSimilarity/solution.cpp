// https://leetcode.com/problems/sentence-similarity/

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
	bool areSentencesSimilar(vector<string>& sentence1,
		vector<string>& sentence2,
		vector<vector<string>>& pairs)
	{
	    if (sentence2.size() != sentence1.size())
		return false;

	    std::unordered_map<std::string, std::unordered_set<std::string>> dict;
	    for (const auto& p : pairs) {
		dict[p[0]].insert(p[1]);
		dict[p[1]].insert(p[0]);
	    }

	    for (size_t i = 0; i < sentence1.size(); ++i) {
		if (sentence1[i] != sentence2[i] &&
			!(dict[sentence1[i]].count(sentence2[i]) &&
			 dict[sentence2[i]].count(sentence1[i])))
		    return false;
	    }
	    return true;
	}
};

int main(int argc, char** argv)
{
}
