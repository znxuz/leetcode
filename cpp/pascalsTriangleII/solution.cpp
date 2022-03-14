// https://leetcode.com/problems/pascals-triangle-ii/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		// time: O(n^2)
		// space: O(n)
		vector<int> getRow(int rowIndex)
		{
			vector<int> res{1};
			for (int i = 1; i <= rowIndex; ++i) {
				int prev = 0;
				int n = res.size();
				for (int j = 0; j <= n; ++j) {
					int tmp = (j < n ? res[j] : 0);
					int cur = prev + tmp;
					if (j < n)
						res[j] = cur;
					else
						res.push_back(cur);
					prev = tmp;
				}
			}

			return res;
		}
};

int main(int argc, char** argv)
{
	for (int i = 1; i < 4; ++i) {
		const auto res = Solution().getRow(i);
		iter_print(begin(res), end(res));
	}
}
