// https://leetcode.com/problems/max-number-of-k-sum-pairs/

#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	int maxOperations(vector<int>& nums, int k)
	{
	    return sort(nums, k);
	}

    private:
	// time: O(n)
	// space: O(n)
	int hashmap(const std::vector<int>& nums, int k)
	{
	    std::unordered_map<int, int> freq;
	    int cnt = 0;
	    for (int n : nums) {
		int complement = k - n;
		if (freq.count(complement)) {
		    ++cnt;
		    --freq[complement];
		    if (!freq[complement])
			freq.erase(complement);
		} else {
		    ++freq[n];
		}
	    }

	    return cnt;
	}

	// time: O(n * log(n))
	// space: O(n)
	int sort(std::vector<int>& nums, int k)
	{
	    std::sort(begin(nums), end(nums));
	    int cnt = 0;
	    for (size_t i = 0, j = nums.size() - 1; j < nums.size() && i < j;) {
		long sum = nums[i] + nums[j];
		if (sum <= k)
		    ++i;
		if (sum >= k)
		    --j;
		if (sum == k)
		    ++cnt;
	    }

	    return cnt;
	}
};

int main(int argc, char** argv)
{
}
