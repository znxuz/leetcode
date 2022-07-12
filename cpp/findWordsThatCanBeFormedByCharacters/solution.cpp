// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

#include <numeric>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
	auto get_chars = [](const std::string &s) {
	    auto cnts = std::array<size_t, 26>();
	    for (auto c : s)
		++cnts[static_cast<size_t>(c - 'a')];
	    return cnts;
	};

	return std::accumulate(begin(words), end(words), 0,
	    [dict = get_chars(chars), &get_chars](int sum, const std::string &s) {
		const auto cnts = get_chars(s);
		for (auto i = 0ul; i < dict.size(); ++i)
		    if (dict[i] < cnts[i])
			return sum;
		return sum + static_cast<int>(s.size());
	    });
    }
};

int main(int argc, char **argv)
{
}
