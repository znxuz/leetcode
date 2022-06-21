// https://leetcode.com/problems/verifying-an-alien-dictionary/

#include <algorithm>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
	return manual(words, order);
    }

private:
    bool manual(const std::vector<std::string>& words, const std::string& order)
    {
	auto order_mp = [&order] {
	    auto mp = std::array<unsigned, 26>();
	    for (size_t i = 0; i < order.size(); ++i)
		mp[order[i] - 'a'] = i;
	    return mp;
	}();
	for (size_t i = 1; i < words.size(); ++i)
	    if (!alien_less(words[i - 1], words[i], order_mp))
		return false;
	return true;
    }

    bool alien_less(const std::string& lhs, const std::string& rhs,
	    const std::array<unsigned, 26>& order_mp)
    {
	for (size_t i = 0; i < lhs.size(); ++i) {
	    if (i >= rhs.size())
		return false;
	    if (order_mp[lhs[i] - 'a'] < order_mp[rhs[i] - 'a'])
		return true;
	    else if (order_mp[lhs[i] - 'a'] > order_mp[rhs[i] - 'a'])
		return false;
	}

	return true;
    }

    bool built_in(const std::vector<std::string>& words, const std::string& order)
    {
	const auto order_mp = [&order] {
	    auto mp = std::unordered_map<char, size_t>();
	    for (size_t i = 0; i < order.size(); ++i)
		mp[order[i]] = i;
	    return mp;
	}();

	return std::is_sorted(begin(words), end(words),
		[&order_mp](const std::string& lhs, const std::string& rhs) {
		    return std::lexicographical_compare(begin(lhs), end(lhs),
			    begin(rhs), end(rhs),
			    [&order_mp](char llhs, char rrhs) {
				return order_mp.at(llhs) < order_mp.at(rrhs);
			    });
		});
    }
};

int main(int argc, char** argv)
{
}
