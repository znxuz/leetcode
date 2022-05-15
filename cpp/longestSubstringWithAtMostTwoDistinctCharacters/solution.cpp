// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
	return sliding_window(s);
    }

private:
    // time: O(n)
    // space: O(1)
    int sliding_window(const std::string& s)
    {
	size_t n = s.size();
	if (n < 3)
	    return n;

	std::unordered_map<char, size_t> freq;
	size_t lf = 0;
	size_t rt = 0;
	size_t max = 0;
	while (rt < n) {
	    freq[s[rt]] = rt;
	    ++rt;
	    if (freq.size() > 2) {
		size_t del_idx = n;
		for (const auto& [chr, idx] : freq)
		    del_idx = std::min(del_idx, idx);
		lf = del_idx + 1;
		freq.erase(s[del_idx]);
	    }
	    max = std::max(max, rt - lf);
	}

	return max;
    }
};

void test(const std::string& s)
{
    std::cout << "s: " << s << '\n';
    std::cout << Solution().lengthOfLongestSubstringTwoDistinct(s) << '\n';
}

int main(int argc, char** argv)
{
    test("eceba");
    test("ccaabbb");
}
