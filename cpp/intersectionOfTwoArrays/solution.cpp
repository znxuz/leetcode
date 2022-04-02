// https://leetcode.com/problems/intersection-of-two-arrays/

#include <array>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		return follow_up(nums1, nums2);
	}

private:
	// assume arrays are sorted
	// O(n) time & O(1) space as constraints
	std::vector<int> follow_up(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::sort(begin(nums1), end(nums1));
		std::sort(begin(nums2), end(nums2));
		std::vector<int> res;
		size_t i = 0;
		size_t j = 0;
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] < nums2[j]) {
				++i;
			} else if (nums1[i] > nums2[j]) {
				++j;
			} else {
				if (res.empty() || res.back() != nums1[i])
					res.push_back(nums1[i]);
				++i, ++j;
			}
		}

		return res;
	}

	vector<int> counting_sort(const std::vector<int>& nums1, const std::vector<int>& nums2)
	{
		int cnts[1001]{};
		for (int i : nums1)
			cnts[i] = 1;
		for (int i : nums2)
			cnts[i] |= 2;

		vector<int> res;
		for (size_t i = 0; i < 1001; ++i)
			if (cnts[i] == 3)
				res.push_back(i);
		return res;
	}
};

int main(int argc, char** argv)
{
}
