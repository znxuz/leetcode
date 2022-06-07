// https://leetcode.com/problems/majority-element-ii/

#include <optional>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
	return optimal_space(nums);
    }

private:
    std::vector<int> optimal_space(const std::vector<int>& nums)
    {
	std::optional<int> n1;
	int cnt1 = 0;
	std::optional<int> n2;
	int cnt2 = 0;

	for (int n : nums) {
	    if (n1.has_value() && *n1 == n) {
		++cnt1;
	    } else if (n2.has_value() && *n2 == n) {
		++cnt2;
	    } else if (!cnt1) {
		n1 = n;
		++cnt1;
	    } else if (!cnt2) {
		n2 = n;
		++cnt2;
	    } else {
		--cnt1, --cnt2;
	    }
	}

	std::vector<int> res;
	cnt1 = cnt2 = 0;
	for (int n : nums) {
	    if (n1.has_value() && *n1 == n)
		++cnt1;
	    else if (n2.has_value() && *n2 == n)
		++cnt2;
	}

	int limit = nums.size() / 3;
	if (cnt1 > limit)
	    res.push_back(*n1);
	if (cnt2 > limit)
	    res.push_back(*n2);
	return res;
    }

    // time: O(n)
    // space: O(n)
    std::vector<int> extra_space(const std::vector<int>& nums)
    {
	std::unordered_set<int> st;
	std::unordered_map<int, size_t> freq;
	size_t limit = nums.size() / 3;
	for (int n : nums) {
	    if (++freq[n] > limit)
		st.insert(n);
	}

	return std::vector<int>(begin(st), end(st));
    }
};

int main(int argc, char** argv)
{
}
