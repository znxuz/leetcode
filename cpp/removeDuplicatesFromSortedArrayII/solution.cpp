// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		size_t i = 0;
		for (int n : nums)
			if (i < 2 || n > nums[i - 2])
				nums[i++] = n;

		return i;
	}
};

int main(int argc, char** argv)
{
}
