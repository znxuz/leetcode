// https://leetcode.com/problems/non-decreasing-array/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    bool checkPossibility(vector<int>& nums) 
    {
	return non_modify(nums);
    }

private:
    bool non_modify(const std::vector<int>& nums)
    {
	if (nums.size() < 2)
	    return true;

	auto bad_idx = nums.size();
	for (auto i = 0ul; i < nums.size() - 1; ++i) {
	    if (nums[i] > nums[i + 1]) {
		if (bad_idx < nums.size())
		    return false;
		bad_idx = i;
	    }
	}

	if (!bad_idx || bad_idx >= nums.size() - 2)
	    return true;
	return nums[bad_idx - 1] <= nums[bad_idx + 1] ||
	    nums[bad_idx] <= nums[bad_idx + 2];
    }

    bool modify_array(std::vector<int>& nums)
    {
	for (auto i = 1ul, cnt = 0ul; i < nums.size(); ++i) {
	    if (nums[i] < nums[i - 1]) {
		if (++cnt == 2)
		    return false;
		// if current is greater or equal to nums[i - 2],
		//  make previous the same as current
		if (i < 2 || nums[i - 2] <= nums[i])
		    nums[i - 1] = nums[i];
		// if current is less than nums[i - 2],
		//  make current the same as previous
		else
		    nums[i] = nums[i - 1];
	    }
	}

	return true;
    }
};

int main(int argc, char** argv)
{
}
