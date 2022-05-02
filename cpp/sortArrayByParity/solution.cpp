// https://leetcode.com/problems/sort-array-by-parity/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	// time: O(n)
	// space: O(1)
	vector<int> sortArrayByParity(vector<int>& nums)
	{
	    size_t i = 0;
	    for (size_t j = 0; j < nums.size(); ++j) {
		if (!(nums[j] & 1))
		    std::swap(nums[i++], nums[j]);
	    }

	    return nums;
	}
};

int main(int argc, char** argv)
{
}
