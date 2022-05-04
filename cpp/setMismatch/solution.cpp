// https://leetcode.com/problems/set-mismatch/

#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	vector<int> findErrorNums(vector<int>& nums)
	{
	    return optimal(nums);
	}

    private:
	std::vector<int> optimal(std::vector<int>& nums)
	{
	    int dup;
	    for (size_t i = 0; i < nums.size(); ++i) {
		if (nums[std::abs(nums[i]) - 1] < 0)
		    dup = std::abs(nums[i]);
		else
		    nums[std::abs(nums[i]) - 1] *= -1;
	    }
	    for (size_t i = 0; i < nums.size(); ++i) {
		if (nums[i] > 0)
		    return {dup, static_cast<int>(i + 1)};
	    }

	    return {};
	}

	// time: O(n)
	// space: O(n)
	std::vector<int> st(const std::vector<int>& nums)
	{
	    std::unordered_set<int> st;
	    int dup;
	    int sum = 0;
	    for (auto n : nums) {
		if (!st.insert(n).second)
		    dup = n;
		sum += n;
	    }
	    size_t n = nums.size();
	    int missing = (n * n + n) / 2 - (sum - dup);
	    return {dup, missing};
	}
};

int main(int argc, char** argv)
{
}
