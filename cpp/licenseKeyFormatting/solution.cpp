// https://leetcode.com/problems/license-key-formatting/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	string licenseKeyFormatting(string s, size_t k)
	{
		std::string res;
		for (size_t i = s.size(), cnt = 0; i-- > 0;) {
			if (s[i] == '-')
				continue;
			if (!res.empty() && cnt % k == 0)
				res.push_back('-');
			res.push_back(static_cast<char>(std::toupper(s[i])));
			++cnt;
		}

		std::reverse(begin(res), end(res));
		return res;
	}
};

int main(int argc, char** argv)
{
	std::string s = "5F3Z-2e-9-w";
	std::cout << Solution().licenseKeyFormatting(s, 4) << '\n';
}
