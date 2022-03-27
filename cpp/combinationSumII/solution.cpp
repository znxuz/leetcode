// https://leetcode.com/problems/combination-sum-ii/

#include <limits>
#include <unordered_set>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	// TIME: O(2^n)
	// space: O(n)
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		std::sort(begin(candidates), end(candidates));
		vector<vector<int>> res;
		backtrack(candidates, 0, res, {}, target);
		return res;
	}

private:
	bool backtrack(const vector<int>& candidates, size_t idx, vector<vector<int>>& res, vector<int> cmb, int target)
	{
		if (target <= 0) {
			if (target == 0)
				res.push_back(std::move(cmb));
			return true;
		}

		bool stop = false;
		for (size_t i = idx; i < candidates.size() && !stop; ++i) {
			if (i == idx || candidates[i] != candidates[i - 1]) {
				cmb.push_back(candidates[i]);
				stop = backtrack(candidates, i + 1, res, cmb, target - candidates[i]);
				cmb.pop_back();
			}
		}
		return false;
	}
};

// TIME: O(2^n)
void backtrack(const vector<int>& arr, size_t idx)
{
	for (; idx < arr.size(); ++idx) {
		std::cout << arr[idx] << '\n';
		backtrack(arr, idx + 1);
	}
}

int main(int argc, char** argv)
{
	std::vector<int> arr{1, 2 ,3, 4, 5};
	backtrack(arr, 0);
}
