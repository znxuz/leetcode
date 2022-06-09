// https://leetcode.com/problems/reverse-only-letters/

#include <stack>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    string reverseOnlyLetters(string s) 
    {
	return stk(s);
    }

private:
    std::string stk(std::string s)
    {
	std::stack<char> stk;
	for (char c : s)
	    if (std::isalpha(c))
		stk.push(c);

	for (char& c : s) {
	    if (std::isalpha(c))
		c = stk.top(), stk.pop();
	}

	return s;
    }

    std::string two_ptr(std::string s)
    {
	size_t lo = 0;
	size_t hi = s.size() - 1;
	while (hi < s.size() && lo < hi) {
	    if (!std::isalpha(s[lo]))
		++lo;
	    else if (!std::isalpha(s[hi]))
		--hi;
	    else
		std::swap(s[lo++], s[hi--]);
	}

	return s;
    }
};

int main(int argc, char** argv)
{
}
