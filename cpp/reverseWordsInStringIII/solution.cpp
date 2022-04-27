// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <stack>
#include <sstream>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	string reverseWords(string s)
	{
		return split(s);
	}

private:
	std::string split(const std::string& s)
	{
		std::stack<char> stk;
		std::string res;
		for (char c : s) {
			if (c != ' ') {
				stk.push(c);
				continue;
			}
			while (!stk.empty())
				res.push_back(stk.top()), stk.pop();
			res.push_back(c);
		}
		while (!stk.empty())
			res.push_back(stk.top()), stk.pop();

		return res;
	}

	std::string string_stream_split(const std::string& s)
	{
		std::stringstream ss(s);
		std::string w;
		std::string res;
		while (std::getline(ss, w, ' ')) {
			std::reverse(begin(w), end(w));
			res += w + ' ';
		}
		res.pop_back();

		return res;
	}
};

int main(int argc, char** argv)
{
}
