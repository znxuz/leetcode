// https://leetcode.com/problems/jewels-and-stones/

#include <array>
#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
	return arr(jewels, stones);
    }

private:
    int arr(const std::string& jewels, const std::string& stones)
    {
	auto offset = [](char c) {
	    return static_cast<size_t>(std::isupper(c) ? 'A' - 26 : 'a');
	};
	auto arr = std::array<char, 52>();
	std::for_each(begin(jewels), end(jewels),
		[&arr,&offset](char c) {
		    arr[static_cast<size_t>(c) - offset(c)] = true;
		});

	return static_cast<int>(std::count_if(begin(stones), end(stones),
		    [&arr,&offset](char c) {
			return arr[static_cast<size_t>(c) - offset(c)];
		    }));
    }

    int st(const std::string& jewels, const std::string& stones)
    {
	std::unordered_set<char> hits(begin(jewels), end(jewels));
	return static_cast<int>(std::count_if(begin(stones), end(stones),
		    [&hits](char c) {
			return hits.count(c);
		    }));
    }
};

int main(int argc, char** argv)
{
    std::string jewels = "aA", stones = "aAAbbbb";
    std::cout << Solution().numJewelsInStones(jewels, stones);
}
