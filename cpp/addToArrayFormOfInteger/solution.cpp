// https://leetcode.com/problems/add-to-array-form-of-integer/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) 
    {
	auto carry = 0;
	for (auto i = nums.size() - 1; i < nums.size() || k; --i) {
	    auto cur = (i < nums.size() ? nums[i] : 0) + k % 10 + carry;
	    k /= 10;
	    carry = cur / 10;
	    cur %= 10;
	    if (i < nums.size())
		nums[i] = cur;
	    else
		nums.insert(begin(nums), cur);
	}
	if (carry)
	    nums.insert(begin(nums), 1);

	return nums;
    }
};

int main(int argc, char** argv)
{
}
