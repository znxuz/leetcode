// https://leetcode.com/problems/contains-duplicate-iii/

#include <set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
	return sliding_window(nums, k, t);
    }

private:
    // time: O(n * log(min(n, k)))
    // space: O(min(n, k))
    bool sliding_window(const std::vector<int>& nums, size_t range, long diff)
    {
	if (!range)
	    return false;

	std::set<long> st;
	for (size_t i = 0; i < nums.size(); ++i) {
	    long lower = nums[i] - diff;
	    long upper = nums[i] + diff;
	    auto lower_bound = st.lower_bound(lower);
	    if (lower_bound != st.end() && *lower_bound <= upper)
		return true;

	    if (st.size() >= range)
		st.erase(nums[i - range]);
	    st.insert(nums[i]);
	}

	return false;
    }
};

int main(int argc, char** argv)
{
    Solution s;
    std::vector<int> arr3{2147483640, 2147483641};
    std::cout << s.containsNearbyAlmostDuplicate(arr3, 1, 100) << '\n';
}
