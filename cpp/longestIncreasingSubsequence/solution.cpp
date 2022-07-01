// https://leetcode.com/problems/longest-increasing-subsequence/

#include "helper.h"

using namespace std;
using namespace util;

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
	return improved(nums);
    }

private:
    // TODO swap lower_bound with binary search
    int improved(const std::vector<int>& nums)
    {
	auto sorted = std::vector<int>();
	for (auto n : nums) {
	    auto bound = std::lower_bound(begin(sorted), end(sorted), n);
	    if (bound == end(sorted))
		sorted.push_back(n);
	    else
		*bound = n;
	}

	return static_cast<int>(sorted.size());
    }

    // time: O(nlog(n))
    int dp(const std::vector<int>& nums)
    {
	auto cur_max = std::map<int, int>();
	for (auto n : nums) {
	    const auto bound = cur_max.lower_bound(n);
	    auto max = 0;
	    for (auto i = cbegin(cur_max); i != bound; ++i)
		max = std::max(max, i->second);
	    cur_max[n] = max + 1;
	}

	return std::max_element(begin(cur_max), end(cur_max),
		[](const auto& lhs, const auto& rhs) {
		    return lhs.second < rhs.second;
		})->second;
    }
};

template<typename... types>
void test(types&&... args)
{
    auto res = Solution().lengthOfLIS(std::forward<types>(args)...);
    std::cout << res << '\n';
}

int main(int argc, char** argv)
{
    auto vec1 = std::vector<int>{10,9,2,5,3,7,101,18};
    test(vec1);
    auto vec2 = std::vector<int>{3, 1, 2};
    test(vec2);
}
