// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/

#include <cstdint>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		int countElements(vector<int>& nums)
		{
			int lo = INT32_MAX;
			int lo_cnt = 0;
			int hi = INT32_MIN;
			int hi_cnt = 0;
			for (int n : nums) {
				if (n < lo) {
					lo = n;
					lo_cnt = 0;
				}
				if (n > hi) {
					hi = n;
					hi_cnt = 0;
				}
				lo_cnt += (lo == n) ? 1 : 0;
				hi_cnt += (hi == n) ? 1 : 0;
			}
			return nums.size() - lo_cnt - ((lo == hi) ? 0 : hi_cnt);
		}
};

int main(int argc, char** argv)
{
	vector<int> v {-71,-71,93,-71,40};
	cout << Solution().countElements(v);
}
