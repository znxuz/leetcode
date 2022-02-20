// https://leetcode.com/problems/time-needed-to-buy-tickets/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		int timeRequiredToBuy(vector<int>& tickets, int k)
		{
			int cnt = 0;
			for (int i = 0; i < tickets.size(); ++i)
				cnt += std::min((i <= k) ? tickets[k] : tickets[k] - 1, tickets[i]);

			return cnt;
		}
};

int main(int argc, char** argv)
{
}
