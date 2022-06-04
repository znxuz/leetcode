// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
	return stl_builtin(nums, k);
    }

private:
    int stl_builtin(std::vector<int>& nums, unsigned k)
    {
	std::nth_element(begin(nums), end(nums) - k, end(nums));
	return nums[nums.size() - k];
    }

    // time: O(n * log(k))
    // space: O(n)
    int priority_queue(const std::vector<int>& nums, unsigned k)
    {
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int n : nums) {
	    pq.push(n);
	    if (pq.size() > k)
		pq.pop();
	}

	return pq.top();
    }
};

void test()
{
    std::vector<int> arr{3,2,3,1,2,4,5,5,6};
    std::cout << Solution().findKthLargest(arr, 4) << '\n';
}

int main(int argc, char** argv)
{
    test();
}
