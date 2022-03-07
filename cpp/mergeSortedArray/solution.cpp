// https://leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <vector>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
		{
			int idx = nums1.size() - 1;
			--m, --n;
			while (idx >= 0) {
				if (m >= 0 && n >= 0)
					nums1[idx--] = (nums1[m] >= nums2[n] ? nums1[m--] : nums2[n--]);
				else if (m >= 0)
					nums1[idx--] = nums1[m--];
				else
					nums1[idx--] = nums2[n--];
			}
		}
};

int main(int argc, char** argv)
{
}
