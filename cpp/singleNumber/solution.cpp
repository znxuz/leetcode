// https://leetcode.com/problems/single-number/

#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		int singleNumber(vector<int>& nums)
		{
			return set(nums);
		}

	private:
		int optimal(const vector<int>& nums)
		{
			return std::accumulate(begin(nums), end(nums), 0, [](int x, const int n) { return x ^ n; });
		}

		int set(const vector<int>& nums)
		{
			std::unordered_set<int> s;
			for(int n : nums) {
				if (!s.insert(n).second)
					s.erase(n);
			}
			return *s.begin();
		}
};

int main(int argc, char** argv)
{
	Solution s;
	vector<int> vec{2, 2, 1, 1, 3, 3, 5, 7, 5};
	cout << s.singleNumber(vec) << '\n';
}
