// https://leetcode.com/problems/group-shifted-strings/

#include <functional>
#include <numeric>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    vector<vector<string>> groupStrings(vector<string>& strings) 
    {
	std::unordered_map<std::string, std::vector<std::string>> str_mp;
	for (const auto& s : strings)
	    str_mp[normalize(s)].push_back(s);

	std::vector<std::vector<std::string>> res;
	res.reserve(str_mp.size());
	for (const auto& [str, vec] : str_mp)
	    res.push_back(std::move(vec));

	return res;
    }

private:
    std::string normalize(std::string s)
    {
	if (s.empty())
	    return s;

	int sw = s.front() - 'a';
	for (auto& c : s) {
	    c -= sw;
	    if (c < 'a')
		c += 'z' - 'a' + 1;
	}

	return s;
    }
};

int main(int argc, char** argv)
{
}
