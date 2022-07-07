// https://leetcode.com/problems/find-common-characters/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    vector<string> commonChars(vector<string>& words) 
    {
	return use_arr(words);
    }

private:
    // time: O(n * m)
    // space: O(1)
    std::vector<std::string> use_arr(const std::vector<std::string>& words)
    {
	auto freq = std::array<unsigned, 26>();
	std::fill(begin(freq), end(freq), std::numeric_limits<unsigned>::max());
	for (const auto& w : words) {
	    auto cnts = std::array<unsigned, 26>();
	    for (auto c : w)
		++cnts[static_cast<size_t>(c - 'a')];
	    for (auto i = 0ul; i < cnts.size(); ++i)
		freq[i] = std::min(freq[i], cnts[i]);
	}

	auto res = std::vector<std::string>();
	for (auto i = 0ul; i < freq.size(); ++i)
	    while (freq[i]--)
		res.push_back(std::string(1, static_cast<char>(i + 'a')));
	return res;
    }
};

int main(int argc, char** argv)
{
}
