// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include <stack>
#include <deque>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	string removeDuplicates(string s, int k)
	{
	    return two_pointers(s, k);
	}

    private:
	std::string two_pointers(std::string s, int k)
	{
	    std::stack<int> cnts;
	    size_t j = 0;
	    for (size_t i = 0; i < s.size(); ++i, ++j) {
		s[j] = s[i];
		if (i == 0 || s[i] != s[i - 1]) {
		    cnts.push(1);
		} else if (++cnts.top() == k) {
		    cnts.pop();
		    j -= k;
		}
	    }

	    return s.substr(0, j);
	}

	// time: O(n)
	// space: O(n)
	std::string deq(const std::string& s, int k)
	{
	    std::deque<char> stk;
	    std::stack<std::pair<char, int>> char_cnts;
	    for (char c : s) {
		if (char_cnts.empty() || char_cnts.top().first != c) {
		    stk.push_back(c);
		    char_cnts.push(std::make_pair(c, 1));
		} else if (char_cnts.top().second == k - 1) {
		    while (char_cnts.top().second--)
			stk.pop_back();
		    char_cnts.pop();
		} else {
		    stk.push_back(c);
		    ++char_cnts.top().second;
		}
	    }

	    std::string res;
	    while (!stk.empty())
		res.push_back(stk.front()), stk.pop_front();
	    return res;
	}
};

void test(const std::string& s, int k)
{
    std::cout << Solution().removeDuplicates(s, k) << '\n';
}

int main(int argc, char** argv)
{
    test("deeedbbcccbdaa", 3);
    test("pbbcggttciiippooaais", 2);
}
