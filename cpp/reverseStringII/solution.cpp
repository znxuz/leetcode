// https://leetcode.com/problems/reverse-string-ii/

#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	string reverseStr(string s, size_t k)
	{
		std::stack<char> stk;
		std::string res;
		size_t cnt = 0;
		for (size_t i = 0; i < s.size(); ++i) {
			if (cnt < k)
				stk.push(s[i]);
			if (cnt == k || i + 1 == s.size())
				while (!stk.empty())
					res.push_back(stk.top()), stk.pop();
			if (cnt >= k)
				res.push_back(s[i]);
			cnt = ++cnt % (k * 2);
		}

		return res;
	}
};

int main(int argc, char** argv)
{
	std::string s = "abcdefg";
	std::cout << Solution().reverseStr(s, 2) << '\n';
}
