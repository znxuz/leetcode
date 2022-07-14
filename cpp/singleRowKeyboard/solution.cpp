// https://leetcode.com/problems/single-row-keyboard/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int calculateTime(string keyboard, string word) 
    {
	auto indices = std::array<int, 26>();
	for (size_t i = 0; i < keyboard.size(); ++i)
	    indices[static_cast<size_t>(keyboard[i] - 'a')] = static_cast<int>(i);

	auto cnt = 0;
	auto prev = 0;
	for (auto c : word) {
	    auto idx = indices[static_cast<size_t>(c - 'a')];
	    cnt += std::abs(idx - std::exchange(prev, idx));
	}

	return cnt;
    }
};

int main(int argc, char **argv)
{
}
