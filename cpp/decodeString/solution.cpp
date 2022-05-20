// https://leetcode.com/problems/decode-string/solution/

#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    string decodeString(string s)
    {
	return iter_char_stk(s);
    }

private:
    std::string iter_char_stk(const std::string& s)
    {
	if (s.empty())
	    return "";

	std::stack<char> stk;
	for (char c : s) {
	    if (c != ']') {
		stk.push(c);
		continue;
	    }

	    std::string substr;
	    while (stk.top() != '[') {
		substr.push_back(stk.top());
		stk.pop();
	    }
	    stk.pop();
	    int cnt = 0;
	    int base = 1;
	    while (!stk.empty() && std::isdigit(stk.top())) {
		cnt += (stk.top() - '0') * base;
		base *= 10;
		stk.pop();
	    }

	    std::string decoded;
	    while (cnt-- > 0)
		decoded += substr;
	    for (size_t i = decoded.size(); i-- > 0;)
		stk.push(decoded[i]);
	}

	std::string res;
	while (!stk.empty())
	    res.push_back(stk.top()), stk.pop();
	std::reverse(begin(res), end(res));

	return res;
    }

    size_t substr_len(const std::string& s, size_t i)
    {
	std::stack<char> stk;
	size_t len = 0;
	stk.push('[');
	while (!stk.empty()) {
	    if (s[i] == '[')
		stk.push(s[i]);
	    if (s[i] == ']')
		stk.pop();
	    ++len;
	    ++i;
	}

	return len - 1;
    }

    std::string rec(const std::string& s)
    {
	if (s.empty())
	    return s;

	std::string res;
	for (size_t i = 0; i < s.size(); ++i) {
	    if (std::isalpha(s[i]))
		res.push_back(s[i]);
	    if (std::isdigit(s[i])) {
		int cnt = 0;
		while (std::isdigit(s[i])) {
		    cnt = cnt * 10 + (s[i] - '0');
		    ++i;
		}

		size_t start = ++i;
		size_t len = substr_len(s, start);
		std::string substr = rec(s.substr(start, len));
		while (cnt-- > 0)
		    res += substr;

		i += len;
	    }
	}

	return res;
    }
};

int main(int argc, char** argv)
{
    std::string s = "3[a2[c]]";
    std::cout << Solution().decodeString(s) << '\n';
}
