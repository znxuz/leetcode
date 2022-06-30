// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int minMoves(vector<int>& nums) 
    {
	std::sort(begin(nums), end(nums));

	auto cnt = 0;
	for (auto i = nums.size() - 1; i > 0 && i < nums.size(); --i)
	    cnt += nums[i] - nums.front();

	return cnt;
    }
};

int main(int argc, char** argv)
{
}
