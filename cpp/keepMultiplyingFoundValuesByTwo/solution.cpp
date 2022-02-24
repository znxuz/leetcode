// https://leetcode.com/problems/keep-multiplying-found-values-by-two/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(n)
		int findFinalValueSet(vector<int>& nums, int original)
		{
			unordered_set<int> set{nums.begin(), nums.end()};
			while (set.count(original))
				original *= 2;
			return original;
		}

		// time: O(n)
		// space: O(1)
		int findFinalValue(vector<int>& nums, int original)
		{
			bool cnts[1001] = {0};
			for (int n : nums)
				cnts[n] = true;
			while (original <= 1000 && cnts[original])
				original *= 2;
			return original;
		}
};

int main(int argc, char** argv)
{
}
