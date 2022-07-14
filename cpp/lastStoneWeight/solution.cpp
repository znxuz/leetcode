// https://leetcode.com/problems/last-stone-weight/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
	return counting_sort(stones);
    }

private:
    // time: O(nlog(n))
    // space: O(n)
    int simulation(const std::vector<int>& stones)
    {
	auto pq = std::priority_queue(begin(stones), end(stones));
	while (pq.size() > 1) {
	    auto s1 = pq.top();
	    pq.pop();
	    auto s2 = pq.top();
	    pq.pop();
	    if (auto diff = s1 - s2; diff)
		pq.push(diff);
	}

	return (pq.empty() ? 0 : pq.top());
    }

    int counting_sort(const std::vector<int>& stones)
    {
	auto weights = std::array<int, 1001>();
	for (auto s : stones)
	    ++weights[static_cast<size_t>(s)];

	auto prev_weight = 0ul;
	for (auto i = size(weights) - 1; i > 0; --i) {
	    if (!weights[i])
		continue;

	    if (prev_weight) {
		++weights[prev_weight - i];
		--weights[i];
		i = std::exchange(prev_weight, 0);
	    } else if (weights[i] % 2) {
		prev_weight = i;
	    }
	}

	return static_cast<int>(prev_weight);
    }
};

int main(int argc, char **argv)
{
}
