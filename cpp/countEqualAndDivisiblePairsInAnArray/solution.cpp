// https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		// time: O(n log(n))
		// space: O(n)
		int countPairs(vector<int>& nums, int k)
		{
			int n = nums.size();
			unordered_map<int, vector<int>> map;
			for (int i = 0; i < n; ++i)
				map[nums[i]].push_back(i);

			int cnt = 0;
			for (const auto& p : map) {
				unordered_map<int, int> gcds;
				// gcd check instead of brute force
				for (int idx : p.second) {
					int i_gcd = __gcd(idx, k);
					for (const auto& gcd_p : gcds)
						cnt += (i_gcd * gcd_p.first % k) ? 0 : gcd_p.second;
					++gcds[i_gcd];
				}
			}
			return cnt;
		}
};

int main(int argc, char** argv)
{
}
