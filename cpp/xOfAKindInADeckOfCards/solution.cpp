// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

#include <numeric>
#include <limits>
#include <array>
#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

template<typename T> constexpr T gcd_(T a, T b)
{
    return b > 0 ? gcd_(b, a % b) : a;
}

class Solution
{
public:
    bool hasGroupsSizeX(vector<int>& deck)
    {
	return cnt_gcd(deck);
    }

private:
    bool cnt_gcd(const std::vector<int>& deck)
    {
	auto cnts = std::array<unsigned, 10000>();
	std::for_each(begin(deck), end(deck),
		[&cnts](auto n) {
		    ++cnts[static_cast<unsigned>(n)];
		});
	unsigned gcd = 0;
	std::for_each(begin(cnts), end(cnts),
		[&gcd](auto cnt) { gcd = gcd_(gcd, cnt); });

	return gcd > 1;
    }

};

int main(int argc, char** argv)
{
    std::vector<int> arr1{1, 1, 2, 2, 2, 2};
    std::vector<int> arr2{1, 1};
    std::vector<int> arr3{0, 0, 0, 1, 1, 1, 2, 2, 2};
    std::cout << Solution().hasGroupsSizeX(arr3) << '\n';
}
