// https://leetcode.com/problems/find-the-difference-of-two-arrays/description/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
	{
		auto res = std::vector<std::vector<int>>{};
		auto set1 = std::unordered_set<int>{begin(nums1), end(nums1)};
		auto set2 = std::unordered_set<int>{begin(nums2), end(nums2)};

		auto func = [](auto& nums, std::unordered_set<int>& set) {
			std::for_each(begin(nums), end(nums), [& set](auto& n) { set.erase(n); });
		};
		func(nums1, set2);
		func(nums2, set1);

		res.push_back(std::vector<int>(begin(set1), end(set1)));
		res.push_back(std::vector<int>(begin(set2), end(set2)));

		return res;
	}
};

int main(int argc, char **argv)
{
}
