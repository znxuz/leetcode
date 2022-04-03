// https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <unordered_map>
#include <iostream>
#include <typeinfo>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		return hash_map(nums1, nums2);
	}

private:
	// time: O(n + m)
	// space: O(max(n, m))
	std::vector<int> hash_map(const std::vector<int>& nums1, const std::vector<int>& nums2)
	{
		std::vector<int> res;
		std::unordered_map<int, int> freq;
		const auto& smaller = (nums1.size() < nums2.size() ? nums1 : nums2);
		const auto& bigger = (nums1.size() >= nums2.size() ? nums1 : nums2);
		for (int n : smaller)
			++freq[n];
		for (int n : bigger) {
			if (freq.empty())
				break;
			if (freq.count(n)) {
				res.push_back(n);
				if (--freq[n] == 0)
					freq.erase(n);
			}
		}

		return res;
	}

	// time: O(n * log(n) + m * log(m)) = O((n + m) * log(n * m))
	// space: O(n + m)
	std::vector<int> two_ptr_sort(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::vector<int> res;
		std::sort(std::begin(nums1), std::end(nums1));
		std::sort(std::begin(nums2), std::end(nums2));
		size_t i = 0;
		size_t j = 0;
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] < nums2[j])
				++i;
			else if (nums1[i] > nums2[j])
				++j;
			else
				res.push_back(nums1[i]), ++i, ++j;
		}

		return res;
	}
};

int main(int argc, char** argv)
{
	std::vector<int> nums1{4, 9, 5};
	std::vector<int> nums2{9, 4, 9, 8, 4};
	std::vector<int> res(Solution().intersect(nums1, nums2));
	iter_print(std::begin(res), std::end(res));
}
