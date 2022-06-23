// https://leetcode.com/problems/largest-perimeter-triangle/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int largestPerimeter(vector<int>& nums) 
    {
	std::sort(begin(nums), end(nums));
	for (auto i = nums.size() - 1; i > 1; --i)
	    if (nums[i] < nums[i - 1] + nums[i - 2])
		return nums[i] + nums[i - 1] + nums[i - 2];
	return 0;
    }
};

int main(int argc, char** argv)
{
}
