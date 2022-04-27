// https://leetcode.com/problems/array-partition-i/

#include <array>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int arrayPairSum(vector<int>& nums)
	{
		return counting_sort(nums);
	}

private:
	int counting_sort(const std::vector<int>& nums)
	{
		std::array<int, 20001> cnts{};
		for (int n : nums)
			++cnts[n + 10000];

		int res = 0;
		bool flag = true;
		for (size_t i = 0; i < cnts.size(); ++i) {
			while (cnts[i]) {
				if (flag)
					res += i - 10000;
				flag = !flag;
				--cnts[i];
			}
		}

		return res;
	}

	int sort(std::vector<int>& nums)
	{
		std::sort(begin(nums), end(nums));
		int sum = 0;
		for (size_t i = 0; i < nums.size(); i += 2)
			sum += std::min(nums[i], nums[i + 1]);
		return sum;
	}
};

int main(int argc, char** argv)
{
}
