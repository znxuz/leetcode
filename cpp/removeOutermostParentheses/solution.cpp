// https://leetcode.com/problems/remove-outermost-parentheses/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    string removeOuterParentheses(string s) 
    {
	return just_count(s);
    }

private:
    std::string just_count(const std::string& s)
    {
	auto opened = 0;
	auto res = std::string();
	for (char c : s) {
	    if (c == '(' && opened++)
		res.push_back(c);
	    if (c == ')' && --opened)
		res.push_back(c);
	}
	return res;
    }

    std::string use_stack(const std::string& s)
    {
	auto res = std::string();
	auto stk = std::stack<char>();
	for (auto c : s) {
	    if (stk.empty()) {
		stk.push(c);
		continue;
	    }

	    if (c == '(')
		stk.push(c);
	    else
		stk.pop();
	    if (!stk.empty())
		res.push_back(c);
	}

	return res;
    }
};

int main(int argc, char** argv)
{
    Solution().removeOuterParentheses("()()");
}
