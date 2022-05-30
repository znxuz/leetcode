// https://leetcode.com/problems/positions-of-large-groups/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
	std::vector<std::vector<int>> res;
	for (int i = 0, j = 0; j < s.size(); ++j) {
	    if (j < s.size() + 1 && s[i] != s[j + 1]) {
		if (j - i > 1)
		    res.emplace_back(std::initializer_list<int>{i, j});
		i = j + 1;
	    }
	}

	return res;
    }
};

int main(int argc, char** argv)
{
    std::string s = "abcdddeeeeaabbbcd";
    for (auto res = Solution().largeGroupPositions(s); const auto& c : res)
	print_container(c);
}
