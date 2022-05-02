// https://leetcode.com/problems/palindrome-partitioning/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	vector<vector<string>> partition(string s)
	{
	    std::vector<std::vector<std::string>> res;
	    std::vector<std::string> cmb;
	    backtrack(s, 0, res, cmb);
	    return res;
	}

    private:
	bool palindrome(const std::string& s, size_t lo, size_t hi)
	{
	    while (lo < hi)
		if (s[lo++] != s[hi--])
		    return false;
	    return true;
	}

	void backtrack(const std::string& s, size_t start,
		std::vector<std::vector<std::string>>& res,
		std::vector<std::string>& cmb)
	{
	    if (start >= s.size()) {
		if (!cmb.empty())
		    res.push_back(cmb);
		return;
	    }

	    for (size_t end = start; end < s.size(); ++end) {
		if (palindrome(s, start, end)) {
		    cmb.emplace_back(s, start, end + 1 - start);
		    backtrack(s, end + 1, res, cmb);
		    cmb.pop_back();
		}
	    }
	}
};

void test()
{
    std::string s = "aaa";
    auto res = Solution().partition(s);
    for (const auto& p : res)
	iter_print(begin(p), end(p));
}

int main(int argc, char** argv)
{
    test();
}
