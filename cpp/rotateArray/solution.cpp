// https://leetcode.com/problems/rotate-array/

#include <queue>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    void rotate(vector<int>& nums, size_t k)
    {
	reverses(nums, k);
    }

private:
    void reverses(std::vector<int>& nums, size_t k)
    {
	k %= nums.size();
	if (!k)
	    return;

	reverse(nums, 0, nums.size() - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, nums.size() - 1);
    }

    void reverse(std::vector<int>& nums, size_t lo, size_t hi)
    {
	while (lo < hi)
	    std::swap(nums[lo++], nums[hi--]);
    }

    void extra_space(std::vector<int>& nums, size_t k)
    {
	auto n = nums.size();
	k = (n - k % n) % n;
	if (!k)
	    return;

	std::queue<int> que;
	for (size_t i = 0, j = k; i < n; ++i, j = ++j % n) {
	    que.push(nums[i]);
	    if (j < k) {
		nums[i] = que.front();
		que.pop();
	    } else {
		nums[i] = nums[j];
	    }
	}
    }
};

int main(int argc, char** argv)
{
    size_t n = 6;
    for (size_t i = 0; i < 7; ++i) {
	std::cout << "i: " << i << ", mod: " << (n - i % n) % n << '\n';
    }
}
