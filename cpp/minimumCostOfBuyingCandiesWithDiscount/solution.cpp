// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		int minimumCost(vector<int>& cost)
		{
			int costs[101] {0};
			for (auto c : cost)
				costs[c]++;

			int total = 0;
			int cnt = 0;
			for (int i = 100; i >= 0; --i) {
				while (costs[i]-- > 0) {
					cnt = ++cnt % 3;
					if (cnt != 0)
						total += i;
				}
			}
			return total;
		}

};

int main(int argc, char** argv)
{
}
