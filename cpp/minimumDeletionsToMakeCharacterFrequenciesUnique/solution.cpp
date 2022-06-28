// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int minDeletions(string s) 
    {
	return use_set(s);
    }

private:
    // time: O(n + k), k = unique counts of chars
    // space: O(k)
    int use_set(const std::string& s)
    {
	auto cnts = std::array<size_t, 26>();
	for (auto c : s)
	    ++cnts[static_cast<size_t>(c - 'a')];

	auto used = std::unordered_set<size_t>();
	auto res = 0;
	for (auto i = 0ul; i < cnts.size(); ++i) {
	    while (cnts[i] && !used.insert(cnts[i]--).second)
		++res;
	}

	return res;
    }

    // time: O(n + klog(k))
    // space: O(k)
    int sort(const std::string& s)
    {
	auto cnts = std::array<size_t, 26>();
	for (auto c : s)
	    ++cnts[static_cast<size_t>(c - 'a')];

	auto sorted = std::vector<size_t>();
	std::for_each(begin(cnts), end(cnts),
		[&sorted](size_t elem) { if (elem) sorted.push_back(elem); });
	std::sort(begin(sorted), end(sorted));

	auto stk = std::stack<size_t>();
	auto free_idx = 0ul;
	auto prev = std::numeric_limits<size_t>::max();
	auto res = 0;
	for (auto cnt : sorted) {
	    while (free_idx < cnt)
		stk.push(free_idx++);
	    if (prev == cnt) {
		if (!stk.empty())
		    res += cnt - stk.top(), stk.pop();
		else
		    res += cnt;
	    }
	    if (free_idx == cnt)
		++free_idx;
	    prev = cnt;
	}

	return res == -1 ? 0 : res;
    }
};

void test(std::string s)
{
    auto res = Solution().minDeletions(s);
    std::cout << "res: " << res << '\n';
}

int main(int argc, char** argv)
{
    test("aab");
    test("abbccddeee");
    test("aaabbbcc");
    test("ceabaacb");
    test("bogoidmdkbllehemdkfofcieckdoffiokflejeeffhihfbbfffboklaoochielobmcekaeoajicke");
}
