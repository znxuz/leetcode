// https://leetcode.com/problems/132-pattern/

#include <stack>
#include <limits>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	bool find132pattern(vector<int>& nums)
	{
	    return min_w_stk(nums);
	}

    private:
	// time: O(n)
	// space: O(n)
	bool min_w_stk(const std::vector<int>& nums)
	{
	    if (nums.size() < 3)
		return false;

	    std::vector<int> mins(nums.size());
	    mins[0] = nums[0];
	    for (size_t i = 1; i < nums.size(); ++i)
		mins[i] = std::min(mins[i - 1], nums[i]);

	    std::stack<int> stk;
	    for (size_t i = nums.size(); i-- > 1;) {
		if (nums[i] <= mins[i])
		    continue;
		while (!stk.empty() and stk.top() <= mins[i])
		    stk.pop();
		if (!stk.empty() and stk.top() < nums[i])
		    return true;
		stk.push(nums[i]);
	    }

	    return false;
	}

	// time: O(n^2)
	// space: O(1)
	bool brute(const std::vector<int>& nums)
	{
	    for (size_t i = 0; i < nums.size(); ++i) {
		int lmin = std::numeric_limits<int>::max();
		for (size_t j = i - 1; j < nums.size(); --j) {
		    if (nums[j] < nums[i] && nums[j] < lmin)
			lmin = nums[j];
		}
		int rmax = std::numeric_limits<int>::min();
		for (size_t j = i + 1; j < nums.size(); ++j) {
		    if (nums[j] < nums[i] && nums[j] > rmax)
			rmax = nums[j];
		}
		if (rmax > lmin)
		    return true;
	    }

	    return false;
	}
};

int main(int argc, char** argv)
{
}
