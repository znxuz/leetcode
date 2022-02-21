// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

#include <algorithm>
#include <functional>
#include <ios>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
	public:
		// time: O(n * log(k) + n) = O(n * logn)
		// space: O(n)
		vector<int> maxSubsequence(vector<int>& nums, int k)
		{
			vector<int> hp;
			for (auto n : nums) {
				if (hp.size() < k || hp.front() < n) {
					if (hp.size() == k) {
						pop_heap(hp.begin(), hp.end(), greater<int>{});
						hp.pop_back();
					}
					hp.push_back(n);
					push_heap(hp.begin(), hp.end(), greater<int>{});
				}
			}

			sort_heap(hp.begin(), hp.end(), greater<int>{});
			vector<int> ret;
			for (auto n : nums) {
				auto it = find(hp.begin(), hp.end(), n);
				if (it != hp.end()) {
					ret.push_back(*it);
					hp.erase(it);
				}
			}

			return ret;
		}
};

int main(int argc, char** argv)
{
	vector<int> v{1, 5, 3, -1, 9, 8};
	Solution().maxSubsequence(v, 3);
}
