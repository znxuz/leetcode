// https://leetcode.com/problems/largest-unique-number/

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    int largestUniqueNumber(vector<int> &nums)
    {
	return counting_sort(nums);
    }

private:
    // time: O(n)
    // space: O(1)
    int counting_sort(const std::vector<int> &nums)
    {
	auto arr = std::array<int, 2001>();
	for (auto n : nums)
	    ++arr[static_cast<size_t>(n)];
	for (auto i = arr.size() - 1; i < arr.size(); --i)
	    if (arr[i] == 1)
		return static_cast<int>(i);
	return -1;
    }

    // time: O(n)
    // space: O(n)
    int use_set(const std::vector<int> &nums)
    {
	auto uniqs = std::unordered_set<int>();
	auto dups = std::unordered_set<int>();
	for (auto n : nums) {
	    if (dups.insert(n).second)
		uniqs.insert(n);
	    else
		uniqs.erase(n);
	}

	auto max = -1;
	for (auto n : uniqs)
	    max = std::max(max, n);
	return max;
    }

    // time: O(n)
    // space: O(n)
    int use_map(const std::vector<int> &nums)
    {
	auto freq = std::unordered_map<int, size_t>();
	for (auto n : nums)
	    ++freq[n];
	auto max = -1;
	for (const auto &[val, freq] : freq) {
	    if (freq == 1)
		max = std::max(max, val);
	}

	return max;
    }
};

int main(int argc, char **argv)
{
}
