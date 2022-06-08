// https://leetcode.com/problems/product-of-array-except-self/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
	return optimal_space(nums);
    }

private:
    std::vector<int> optimal_space(std::vector<int>& nums)
    {
	std::vector<int> res(nums.size());
	int prod = 1;
	for (size_t i = 0; i < nums.size(); ++i) {
	    res[i] = prod;
	    prod *= nums[i];
	}

	prod = 1;
	for (size_t i = nums.size(); i-- > 0;) {
	    res[i] *= prod;
	    prod *= nums[i];
	}

	return res;
    }

    // time: O(n)
    // space: O(n)
    std::vector<int> via_rec_global_var(const std::vector<int>& nums)
    {
	std::vector<int> res(nums.size());
	int after_prod = 1;
	rec(nums, res, 0, 1, after_prod);
	return res;
    }

    void rec(const std::vector<int>& nums, std::vector<int>& res, size_t i,
	    int prev_prod, int& after_prod)
    {
	if (i >= nums.size())
	    return;

	rec(nums, res, i + 1, prev_prod * nums[i], after_prod);
	res[i] = prev_prod * after_prod;
	after_prod *= nums[i];
    }
    // 1 2 3 4
    // 24, 12, 8, 6
};

int main(int argc, char** argv)
{
    std::vector<int> nums{1, 2, 3, 4};
    print_container(Solution().productExceptSelf(nums));
}
