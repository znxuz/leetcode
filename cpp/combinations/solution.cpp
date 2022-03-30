// https://leetcode.com/problems/combinations/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> res;
		vector<int> cmb(k, 0);
		backtrack(res, 0, cmb, n, k);
		return res;
	}

private:
	// time: O(n! / (n - k)!k!)
	// space: O(k)
	void backtrack(vector<vector<int>>& res, int num, vector<int>& cmb, int n, int k)
	{
		if (cmb.size() == k) {
			res.push_back(cmb);
			return;
		}

		for (int i = num + 1; i <= n; ++i) {
			cmb.push_back(i);
			backtrack(res, i, cmb, n, k);
			cmb.pop_back();
		}
	}
};

int main(int argc, char** argv)
{
	int n = 4;
	int k = 2;
	auto res = Solution().combine(n, k);
	std::for_each(begin(res), end(res), [](const auto& row) { iter_print(begin(row), end(row)); });
}
