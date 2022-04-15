// https://leetcode.com/problems/next-greater-element-i/

#include <stack>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
	{
		return via_stack(nums1, nums2);
	}

private:
	// time : O(n)
	// space: O(n)
	std::vector<int> via_stack(const std::vector<int>& nums1, const std::vector<int>& nums2)
	{
		std::stack<int> stk;
		std::unordered_map<int, int> next_max;
		for (auto n : nums2) {
			while (!stk.empty() && stk.top() < n)
				next_max[stk.top()] = n, stk.pop();
			if (stk.empty() || stk.top() >= n)
				stk.push(n);
		}
		while (!stk.empty())
			next_max[stk.top()] = -1, stk.pop();

		for (const auto& [key, val] : next_max)
			std::cout << "n : " << key << ", next max: " << val << '\n';

		std::vector<int> res(nums1.size());
		for (size_t i = 0; i < nums1.size(); ++i)
			res[i] = next_max[nums1[i]];

		return res;
	}

	// time: O(n^2)
	// space: O(n)
	std::vector<int> brute_force(const std::vector<int>& nums1, const std::vector<int>& nums2)
	{
		std::unordered_map<int, int> next_max;
		for (size_t i = nums2.size(); i-- > 0;) {
			int next = -1;
			for (size_t j = i + 1; j < nums2.size() && next == -1; ++j) {
				if (nums2[j] > nums2[i])
					next = nums2[j];
			}
			next_max[nums2[i]] = next;
		}

		std::vector<int> res(nums1.size());
		for (size_t i = 0; i < nums1.size(); ++i) {
			res[i] = next_max[nums1[i]];
		}

		return res;
	}
};

int main(int argc, char** argv)
{
	std::vector<int> nums1{2,4};
	std::vector<int> nums2{1,2,3,4};
	auto res = Solution().nextGreaterElement(nums1, nums2);
	iter_print(begin(res), end(res));
}
