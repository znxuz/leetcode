// https://leetcode.com/problems/wiggle-sort/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    void wiggleSort(vector<int>& nums) 
    {
	linear_time(nums);
    }

private:
    void linear_time(std::vector<int>& nums)
    {
	for (auto i = 1ul; i < nums.size(); i += 2) {
	    if (nums[i] < nums[i - 1])
		std::swap(nums[i], nums[i - 1]);
	    if (i + 1 < nums.size() && nums[i] < nums[i + 1])
		std::swap(nums[i], nums[i + 1]);
	}
    }

    void use_sort(std::vector<int>& nums)
    {
	auto sorted = nums;
	std::sort(begin(sorted), end(sorted));
	for (auto i = 0ul, lo = 0ul, hi = sorted.size() - 1; lo <= hi; ++i) {
	    if (lo == hi)
		nums[i] = sorted[lo++];
	    else
		nums[i] = (i & 1 ? sorted[hi--] : sorted[lo++]);
	}
    }
};

int main(int argc, char** argv)
{
}
