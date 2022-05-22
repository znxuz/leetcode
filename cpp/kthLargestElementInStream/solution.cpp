// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class KthLargest
{
public:
    // time: O(n * log(n))
    KthLargest(size_t k, vector<int>& nums) : capacity(k), pq(begin(nums), end(nums))
    {
	while (pq.size() > capacity)
	    pq.pop();
    }

    // time: O(log(n))
    int add(int val)
    {
	if (pq.size() < capacity)
	    pq.push(val);
	else if (val > pq.top()) {
	    pq.push(val);
	    pq.pop();
	}

	return pq.top();
    }

private:
    size_t capacity;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char** argv)
{
}
