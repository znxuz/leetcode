// https://leetcode.com/problems/brace-expansion/

#include <cctype>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<string> expand(string s)
	{
		std::vector<std::string> res;
		std::string cmb;
		backtrack(s, 0, res, cmb);
		std::sort(begin(res), end(res));

		return res;
	}

private:
	void backtrack(const std::string& s, size_t idx,
			std::vector<std::string>& res, std::string& cmb)
	{
		if (idx == s.size()) {
			res.push_back(cmb);
			return;
		}

		std::vector<char> list;
		if (std::isalpha(s[idx])) {
			list.push_back(s[idx]);
		} else {
			while (s[idx] != '}') {
				if (std::isalpha(s[idx]))
					list.push_back(s[idx]);
				++idx;
			}
		}

		for (char c : list) {
			cmb.push_back(c);
			backtrack(s, idx + 1, res, cmb);
			cmb.pop_back();
		}
	}
};

static void test(const std::string& s)
{
	auto res = Solution().expand(s);
	iter_print(begin(res), end(res));
}

int main(int argc, char** argv)
{
	test("{a,b}c{d,e}f");
	test("abcd");
}
