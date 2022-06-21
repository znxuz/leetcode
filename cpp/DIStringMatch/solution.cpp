// https://leetcode.com/problems/di-string-match/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    vector<int> diStringMatch(string s) 
    {
	auto res = std::vector<int>(s.size() + 1);
	auto lo = 0ul;
	auto hi = s.size();
	for (size_t i = 0; i < s.size(); ++i)
	    res[i] = static_cast<int>(s[i] == 'D' ? hi-- : lo++);
	res.back() = static_cast<int>(s.back() == 'D' ? lo : hi);

	return res;
    }
};

int main(int argc, char** argv)
{
}
