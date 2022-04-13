// https://leetcode.com/problems/restore-ip-addresses/

#include <numeric>
#include <array>
#include <iostream>
#include <string>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		std::vector<std::string> res;
		std::vector<int> cmb;
		backtrack(s, 0, cmb, res);

		return res;
	}

private:
	void backtrack(const std::string& s, size_t idx, std::vector<int>& cmb,
			std::vector<std::string>& res)
	{
		if (cmb.size() == 4) {
			if (idx == s.size()) {
				std::string ip;
				for (size_t i = 0; i < cmb.size(); ++i) {
					ip += std::to_string(cmb[i]);
					if (i + 1 != cmb.size())
						ip.push_back('.');
				}
				res.push_back(std::move(ip));
			}
			return;
		}

		cmb.push_back(0);
		for (size_t i = idx; i < std::min(s.size(), idx + 3); ++i) {
			auto& num = cmb.back();
			num = num * 10 + (s[i] - '0');
			if (num <= 255)
				backtrack(s, i + 1, cmb, res);
			if (i == idx && s[i] == '0')
				break;
		}
		cmb.pop_back();
	}
};

void test(const std::string& s)
{
	auto res = Solution().restoreIpAddresses(s);
	iter_print(begin(res), end(res));
}

int main(int argc, char** argv)
{
	// test("25525511135");
	test("101023");
}
