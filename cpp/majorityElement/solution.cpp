// https://leetcode.com/problems/majority-element/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		// Boyer-Moore Voting Algorithm
		// time: O(n)
		// space: O(1)
		int majorityElement(vector<int>& nums)
		{
			int cnt = 0;
			int max = -1;
			for (int n : nums) {
				if (cnt == 0)
					max = n;
				cnt += (max == n ? 1 : -1);
			}

			return max;
		}
};

int main(int argc, char** argv)
{
}
