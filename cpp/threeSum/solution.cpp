// https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		// time: O(n^2)
		// space: O(n)
		vector<vector<int>> threeSum(vector<int>& nums)
		{
			return set(nums);
		}

		vector<vector<int>> no_sort(vector<int>& nums)
		{
			std::set<vector<int>> res;
			unordered_set<int> dups;
			unordered_map<int, int> seen;
			for (int i = 0; i < nums.size(); ++i) {
				if (!dups.insert(nums[i]).second)
					continue;
				for (int j = i + 1; j < nums.size(); ++j) {
					int complement = -nums[i] - nums[j];
					if (seen[complement] == i) {
						vector<int> triplets = {nums[i], complement, nums[j]};
						sort(begin(triplets), end(triplets));
						res.insert(triplets);
					}
					seen[complement] = i;
				}
			}

			return vector<vector<int>>{begin(res), end(res)};
		}

		vector<vector<int>> two_pointers(vector<int>& nums)
		{
			vector<vector<int>> res;

			sort(nums.begin(), nums.end());
			int n = nums.size();
			for (int i = 0; i < n; ++i) {
				if (i != 0 && nums[i] == nums[i - 1])
					continue;
				int lo = i + 1;
				int hi = n - 1;
				while (lo < hi) {
					int sum = nums[i] + nums[lo] + nums[hi];
					if (sum < 0)
						++lo;
					else if (sum > 0)
						--hi;
					else {
						res.push_back({nums[i], nums[lo], nums[hi]});
						++lo;
						--hi;
						while (lo < hi && nums[lo] == nums[lo - 1])
							++lo;
						while (lo < hi && nums[hi] == nums[hi + 1])
							--hi;
					}
				}
			}

			return res;
		}

		vector<vector<int>> set(vector<int>& nums)
		{
			vector<vector<int>> res;

			sort(nums.begin(), nums.end());
			int n = nums.size();
			unordered_set<int> seen;
			for (int i = 0; i < n && nums[i] <= 0; ++i) {
				if (i != 0 && nums[i] == nums[i - 1])
					continue;
				seen.clear();
				for (int j = i + 1; j < n; ++j) {
					int complement = -nums[i] - nums[j];
					if (seen.count(complement)) {
						res.push_back({nums[i], complement, nums[j]});
						while (j + 1 < n && nums[j + 1] == nums[j])
							++j;
					}
					seen.insert(nums[j]);
				}
			}

			return res;
		}
};

int main(int argc, char** argv)
{
}
