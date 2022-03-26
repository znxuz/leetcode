// https://leetcode.com/problems/combination-sum-iii/

#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<vector<int>> combinationSum3(size_t k, int n)
	{
		return rec(k, n);
	}

private:
	// TIME: O((9! * k) / (9 - k)!)
	// 	9! for the worst case which k = 9 & n = 9 without (9 - k)! combinations
	// 		==> 9! / (9 - k)!
	// 	k time for copy `cmb` at each call
	// 		==> 9! / (9 - k)! * k
	// SPACE: O(k): maximum k recursion depth
	vector<vector<int>> rec(size_t k, int n)
	{
		std::vector<std::vector<int>> res;
		backtrack(res, {}, k, n);
		return res;
	}

	void backtrack(std::vector<std::vector<int>>& res, std::vector<int> cmb, size_t k, int n)
	{
		if (cmb.size() == k) {
			if (n == 0)
				res.push_back(cmb);
			return;
		}

		for (int i = (cmb.empty() ? 1 : cmb.back() + 1); i < 10; ++i) {
			cmb.push_back(i);
			backtrack(res, cmb, k, n - i);
			cmb.pop_back();
		}
	}
};

int main(int argc, char** argv)
{
	Solution s;
	const auto res = s.combinationSum3(2, 18);
	for (const auto& row : res)
		iter_print(begin(row), end(row));
}
