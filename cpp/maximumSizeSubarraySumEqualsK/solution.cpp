// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int maxSubArrayLen(vector<int>& nums, int k) 
    {
	return dp(nums, k);
    }

private:
    int dp(const std::vector<int>& nums, int k)
    {
	std::unordered_map<long, int> sum_mp;
	long sum = 0;
	int max = 0;
	for (size_t i = 0; i < nums.size(); ++i) {
	    sum += nums[i];
	    if (sum == k)
		max = i + 1;
	    else if (sum_mp.count(sum - k))
		max = std::max(max, static_cast<int>(i) - sum_mp[sum - k]);

	    if (!sum_mp.count(sum))
		sum_mp[sum] = i;
	}

	return max;
    }
};

int main(int argc, char** argv)
{
}
