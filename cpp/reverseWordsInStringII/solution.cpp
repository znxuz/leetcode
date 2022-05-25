// https://leetcode.com/problems/reverse-words-in-a-string-ii/

#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    void reverseWords(vector<char>& s)
    {
	reverse_builtin(s);
    }

private:
    void reverse_builtin(std::vector<char>& s)
    {
	std::reverse(begin(s), end(s));
	for (unsigned i = 0; i < s.size(); ++i) {
	    unsigned j = i + 1;
	    while (j < s.size() && s[j] != ' ')
		++j;
	    std::reverse(s.begin() + i, s.begin() + j);
	    i = j;
	}
    }

    void no_reverse_builtin(std::vector<char>& s)
    {
	for (size_t i = 0; i < s.size(); ++i) {
	    size_t j = i;
	    while (j + 1 < s.size() && s[j + 1] != ' ')
		++j;
	    size_t next = j + 1;
	    while (i < j)
		std::swap(s[i++], s[j--]);
	    i = next;
	}

	for (size_t i = 0, j = s.size() - 1; i < j && j < s.size(); ++i, --j)
	    std::swap(s[i], s[j]);
    }
};

int main(int argc, char** argv)
{
}
