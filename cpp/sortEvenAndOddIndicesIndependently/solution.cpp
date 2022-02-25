// https://leetcode.com/problems/sort-even-and-odd-indices-independently/

#include <functional>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution
{
	public:
		struct greater
		{
			bool operator()(const int& a, const int& b)
			{
				return a > b;
			}
		};

		// time: O(n * log(n))
		// space: O(n)
		vector<int> sortEvenOdd(vector<int>& nums)
		{
			priority_queue<int, vector<int>, greater> even;
			priority_queue<int> odd;

			for (int i = 0; i < nums.size(); ++i) {
				if (i & 1)
					odd.push(nums[i]);
				else
					even.push(nums[i]);
			}

			for (int i = 0; i < nums.size(); ++i) {
				if (i & 1) {
					nums[i] = odd.top();
					odd.pop();
				} else {
					nums[i] = even.top();
					even.pop();
				}
			}

			return nums;
		}

		vector<int> sortEvenOddSort(vector<int>& nums)
		{
			vector<int> even;
			vector<int> odd;
			for (int i = 0; i < nums.size(); ++i) {
				if (i & 1)
					odd.push_back(nums[i]);
				else
					even.push_back(nums[i]);
			}
			sort(even.begin(), even.end());
			sort(odd.begin(), odd.end(), greater());
			int odd_idx = 0;
			int even_idx = 0;
			for (int i = 0; i < nums.size(); ++i) {
				nums[i] = (i & 1) ? odd[odd_idx++] : even[even_idx++];
			}

			return nums;
		}
};

int main(int argc, char** argv)
{
}
