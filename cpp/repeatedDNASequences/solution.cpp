// https://leetcode.com/problems/repeated-dna-sequences/

#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
	return sliding(s, 10);
    }

private:
    std::vector<std::string> sliding(const std::string& s, size_t cnt)
    {
	std::unordered_set<std::string> res;
	std::unordered_set<std::string> st;
	for (size_t i = 0; i + cnt - 1 < s.size(); ++i) {
	    auto substr = s.substr(i, cnt);
	    if (!st.insert(substr).second)
		res.insert(std::move(substr));
	}

	return std::vector<std::string>(begin(res), end(res));
    }
};

int main(int argc, char** argv)
{
}
