// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    // time: O(nlog(n))
    // space: O(n)
    int repeatedNTimes(vector<int>& nums) 
    {
	return use_rand(nums);
    }

private:
    int use_rand(const std::vector<int>& nums)
    {
	auto i = 0ul, n = nums.size();
	for (auto j = 0ul; i == j || nums[i] != nums[j]; i = rand() % n, j = rand() % n);
	return nums[i];
    }

    int st(const std::vector<int>& nums)
    {
	auto st = std::unordered_set<int>();
	for (int n : nums)
	    if (!st.insert(n).second)
		return n;
	return -1;
    }

    int sort(vector<int>& nums)
    {
	std::sort(begin(nums), end(nums));
	auto cnt = 0u;
	for (size_t i = 0; i < nums.size(); ++i) {
	    if (cnt && nums[i] != nums[i - 1])
		cnt = 0;
	    ++cnt;
	    if (cnt == nums.size() / 2)
		return nums[i];
	}

	return -1;
    }
};

int main(int argc, char** argv)
{
}
