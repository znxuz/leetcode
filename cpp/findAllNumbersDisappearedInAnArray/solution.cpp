// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<int> findDisappearedNumbers(vector<int>& nums)
	{
		for (size_t i = 0; i < nums.size(); ++i) {
			size_t present = static_cast<size_t>(std::abs(nums[i])) - 1;
			nums[present] = std::min(nums[present], -nums[present]);
		}

		std::vector<int> res;
		for (size_t i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0)
				res.push_back(static_cast<int>(i + 1));
		}

		return res;
	}
};

int main(int argc, char** argv)
{
}
