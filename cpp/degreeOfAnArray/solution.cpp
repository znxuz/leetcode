// https://leetcode.com/problems/degree-of-an-array/

#include <limits>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
    public:
	int findShortestSubArray(vector<int>& nums)
	{
	    std::unordered_map<int, int> freq;
	    std::unordered_map<int, size_t> first;
	    int min = 0;
	    int max_degree = 0;
	    for (size_t i = 0; i < nums.size(); ++i) {
		if (!first.count(nums[i]))
		    first[nums[i]] = i;
		if (++freq[nums[i]] > max_degree) {
		    max_degree = freq[nums[i]];
		    min = i - first[nums[i]] + 1;
		} else if (freq[nums[i]] == max_degree) {
		    min = std::min(min, static_cast<int>(i - first[nums[i]] + 1));
		}
	    }

	    return min;
	}
};

int main(int argc, char** argv)
{
}
