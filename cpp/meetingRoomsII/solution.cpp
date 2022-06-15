// https://leetcode.com/problems/meeting-rooms-ii/

#include <queue>

#include "helper.h"

using namespace std;
using namespace util;

struct cmp
{
    bool operator()(const std::vector<int>& i1, const std::vector<int>& i2) {
	return i1.back() > i2.back();
    }
};

class Solution 
{
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
	return min_heap(intervals);
    }

private:
    // TODO two ptrs

    int min_heap(std::vector<std::vector<int>>& intervals)
    {
	std::sort(begin(intervals), end(intervals),
		[](const std::vector<int>& i1, const std::vector<int>& i2) {
		return i1.front() <= i2.front();
		});

	// auto cmp_end_time =
	    // [](const std::vector<int>& i1, const std::vector<int>& i2) {
		// return i1.back() > i2.back();
	    // };

	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
	    cmp> pq;

	size_t max = 0;
	for (const auto& i : intervals) {
	    if (!pq.empty() && pq.top().back() <= i.front())
		pq.pop();
	    pq.push(i);
	    max = std::max(max, pq.size());
	}

	return static_cast<int>(max);
    }
};

int main(int argc, char** argv)
{
    std::vector<std::vector<int>> intervals{{0,30},{5,10},{15,20}};
    std::cout << Solution().minMeetingRooms(intervals) << '\n';
}
