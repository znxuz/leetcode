// https://leetcode.com/problems/sort-colors/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		void sortColors(vector<int>& nums)
		{
			dijkstra(nums);
		}

		void dijkstra(vector<int>& nums)
		{
			int i = 0;
			int j = 0;
			int k = nums.size() - 1;
			int md = 1;
			while (j <= k) {
				if (nums[j] < md) {
					std::swap(nums[i], nums[j]);
					++i;
					++j;
				} else if (nums[j] > md) {
					std::swap(nums[j], nums[k]);
					--k;
				} else {
					++j;
				}
			}
		}
};

int main(int argc, char** argv)
{
	vector<int> vec{2, 0, 1};
	Solution().dijkstra(vec);
	iter_print(begin(vec), end(vec));
}
