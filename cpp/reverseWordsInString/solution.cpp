// https://leetcode.com/problems/reverse-words-in-a-string/

#include <stack>
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
	return in_place(s);
    }

private:
    void reverse(std::string& s, size_t begin, size_t end)
    {
	while (end < s.size() && begin < end)
	    std::swap(s[begin++], s[end--]);
    }

    std::string in_place(std::string& s)
    {
	size_t i = 0;
	size_t j = 0;
	while (j < s.size()) {
	    if (s[i] == ' ' && s[j] == ' ')
		++i, ++j;
	    else if (s[j] != ' ')
		++j;
	    else
		reverse(s, i, j - 1), i = j;
	}
	if (s.back() != ' ')
	    reverse(s, i, j - 1);

	reverse(s, 0, s.size() - 1);
	i = j = 0;
	while (j < s.size()) {
	    s[i] = s[j];
	    if (s[i] != ' ' || (i > 0 && s[i - 1] != ' '))
		++i;
	    ++j;
	}
	if (s.back() == ' ')
	    --i;
	s.resize(i);

	return s;
    }

    std::string extra_space(const std::string& s)
    {
	std::stack<std::string> stk;
	std::string buf;
	for (size_t i = 0; i < s.size(); ++i) {
	    if (s[i] == ' ') {
		if (!buf.empty())
		    stk.push(buf), buf.clear();
	    } else {
		buf.push_back(s[i]);
	    }
	}
	if (!buf.empty())
	    stk.push(std::move(buf));

	std::string res;
	while (!stk.empty()) {
	    res += std::move(stk.top());
	    stk.pop();
	    if (!stk.empty())
		res.push_back(' ');
	}

	return res;
    }
};

int main(int argc, char** argv)
{
    std::string s = "  the sky   is blue  ";
    std::cout << "original: " << s << '\n';
    std::cout << "size: " << s.length() << '\n';
    std::string res = Solution().reverseWords(s);
    std::cout << "reversed: " << res << '\n';
    std::cout << "size: " << res.length() << '\n';
}
