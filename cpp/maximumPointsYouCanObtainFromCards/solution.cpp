// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <numeric>

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int maxScore(vector<int>& cards, int k) 
    {
	return sliding_window(cards, k);
    }

private:
    int sliding_window(const std::vector<int>& cards, unsigned k)
    {
	if (k >= cards.size())
	    return std::accumulate(begin(cards), end(cards), 0, std::plus<int>());

	auto sum = 0;
	auto lo = 0ul;
	auto hi = cards.size() - 1;
	while (lo < k)
	    sum += cards[lo++];
	auto max = sum;
	while (k--)
	    max = std::max(max, (sum = sum - cards[--lo] + cards[hi--]));
	return max;
    }
};

int main(int argc, char** argv)
{
}
