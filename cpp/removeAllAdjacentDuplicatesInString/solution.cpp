// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    string removeDuplicates(string s) 
    {
	return in_place(s);
    }

private:
    std::string in_place(std::string& s)
    {
	auto top = std::numeric_limits<size_t>::max();
	for (auto i = 0ul; i < s.size(); ++i) {
	    if (top >= s.size() || s[i] != s[top])
		s[++top] = s[i];
	    else
		--top;
	}

	return s.substr(0, top + 1);
    }

    std::string use_deque(const std::string& s)
    {
	auto deq = std::deque<char>();
	for (auto c : s) {
	    if (empty(deq) || deq.back() != c)
		deq.push_back(c);
	    else
		deq.pop_back();
	}
	return std::string(begin(deq), end(deq));
    }
};

int main(int argc, char **argv)
{
}
