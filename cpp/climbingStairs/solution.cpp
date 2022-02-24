// https://leetcode.com/problems/climbing-stairs/ 

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		int climbStairs(int n)
		{
			vector<int> memo(n + 1);
			return climbStairsRec(n, memo);
		}

		// recursive memoization
		// time: O(n)
		// space: O(n)
		int climbStairsRec(int n, vector<int>& memo)
		{
			if (n < 0)
				return 0;

			if (n < 3)
				memo[n] = n;
			else if (memo[n] == 0)
				memo[n] = climbStairsRec(n - 1, memo) + climbStairsRec(n - 2, memo);
			return memo[n];
		}

		// time: O(n)
		// space: O(1)
		int climbStairsCounters(int n)
		{
			if (n < 3)
				return n;

			int prev1 = 1;
			int prev2 = 2;
			for (int i = 3; i <= n; ++i) {
				int cur = prev1 + prev2;
				prev1 = prev2;
				prev2 = cur;
			}
			return prev2;
		}
};

int main(int argc, char** argv)
{
	cout << Solution().climbStairs(45) << '\n';
}
