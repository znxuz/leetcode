// https://leetcode.com/problems/sort-array-by-parity-ii/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    // time: O(n)
    // space: O(1)
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
	size_t n = nums.size();
	size_t even = 0;
	size_t odd = 1;

	while (even < n && odd < n) {
	    if (!(nums[even] & 1))
		even += 2;
	    else if (nums[odd] & 1)
		odd += 2;
	    else {
		std::swap(nums[even], nums[odd]);
		even += 2;
		odd += 2;
	    }
	}

	return nums;
    }
};

int main(int argc, char** argv)
{
}
