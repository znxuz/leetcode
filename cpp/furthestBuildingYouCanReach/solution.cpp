// https://leetcode.com/problems/furthest-building-you-can-reach/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
	return bi_search(heights, bricks, ladders);
    }

private:


    // time: O(nlog(n))
    // space: O(n)
    // improve: binary search for the last reachable building, bool reachable()
    // for checking if current building is reachable by using the prio_que func.
    // below
    int prio_que(const std::vector<int>& heights, int bricks, int ladders)
    {
	std::priority_queue<int> pq;
	int used_bricks = 0;
	for (size_t i = 1; i < heights.size(); ++i) {
	    auto climb = heights[i] - heights[i - 1];
	    if (climb > 0) {
		used_bricks += climb;
		pq.push(climb);
		std::cout << "used: " << used_bricks << '\n';
		while (used_bricks > bricks && !pq.empty() && ladders--) {
		    used_bricks -= pq.top();
		    pq.pop();
		}
		if (used_bricks > bricks)
		    return i - 1;
	    }
	}

	return heights.size() - 1;
    }
};

void test(std::vector<int> heights, int bricks, int ladders)
{
    std::cout << Solution().furthestBuilding(heights, bricks, ladders) << '\n';
}

int main(int argc, char** argv)
{
    test({4, 2, 7, 6, 9, 14, 12}, 5, 1);
    test({4, 12, 2, 7, 3, 18, 20, 3, 19},  10,  2);
}
