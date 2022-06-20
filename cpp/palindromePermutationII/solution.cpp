// https://leetcode.com/problems/palindrome-permutation-ii/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    // TODO optimize the hell out of this
    vector<string> generatePalindromes(string s) 
    {
	auto alph = [&s] {
	    auto alph = std::array<size_t, 26>();
	    for (char c : s)
		++alph[static_cast<size_t>(c) - 'a'];
	    return alph;
	}();

	auto odd_idx = alph.size();
	for (size_t i = 0; i < alph.size(); ++i) {
	    if (alph[i] & 1) {
		if (odd_idx != alph.size())
		    return {};
		odd_idx = i;
	    }
	}

	auto base = std::string();
	if (odd_idx < alph.size()) {
	    base += static_cast<char>(odd_idx + 'a');
	    --alph[odd_idx];
	}

	auto res = std::unordered_set<std::string>();
	backtrack(alph, res.size(), std::unordered_set<size_t>(), res, base, "", "", s.size());
	return std::vector<std::string>(begin(res), end(res));
    }

private:
    void backtrack(std::array<size_t, 26> alph, size_t idx,
	    std::unordered_set<size_t> seen, std::unordered_set<std::string>& res,
	    std::string& base, std::string left, std::string right, size_t total)
    {
	if (base.size() + left.size() + right.size() == total) {
	    std::reverse(left.begin(), left.end());
	    res.insert(std::move(left) + base + std::move(right));
	    return;
	}

	for (auto i = size_t(0); i < alph.size(); ++i) {
	    if (!alph[i])
		continue;
	    left += static_cast<char>(i + 'a');
	    right += static_cast<char>(i + 'a');
	    alph[i] -= 2;
	    if (!alph[i])
		seen.insert(i);
	    backtrack(alph, i, seen, res, base, left, right, total);
	    left.pop_back();
	    right.pop_back();
	    if (!alph[i])
		seen.erase(i);
	    alph[i] += 2;
	}
    }
};

void test(const std::string& s)
{
    auto rs = Solution().generatePalindromes(s);
    print_container(rs);
}

int main(int argc, char** argv)
{
    test("aabb");
    test("aaaaaa");
}
