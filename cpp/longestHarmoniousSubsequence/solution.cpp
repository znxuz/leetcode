// https://leetcode.com/problems/longest-harmonious-subsequence/

#include <unordered_map>
#include <limits>
#include <map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int findLHS(vector<int>& nums)
	{
		return hashmap_improved(nums);
	}

private:
	int hashmap_improved(const std::vector<int>& nums)
	{
		std::unordered_map<int, int> freq;
		for (int n : nums)
			++freq[n];

		int longest = 0;
		for (const auto& [n, cnt] : freq) {
			if (freq.count(n + 1))
				longest = std::max(longest, cnt + freq[n + 1]);
		}

		return longest;
	}

	int map(const std::vector<int>& nums)
	{
		std::map<int, int> freq;
		for (int n : nums)
			++freq[n];

		int longest = 0;
		std::map<int, int>::const_iterator prev = freq.begin();
		for (std::map<int, int>::const_iterator it = freq.begin(); it != freq.end(); ++it) {
			if (it != prev && std::abs(it->first - prev->first) == 1)
				longest = std::max(longest, prev->second + it->second);
			prev = it;
		}

		return longest;
	}
};

int main(int argc, char** argv)
{
}
