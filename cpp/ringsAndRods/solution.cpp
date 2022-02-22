// https://leetcode.com/problems/rings-and-rods/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		int countPoints(string& rings)
		{
			vector<int> rods(10);
			for (int i = 0; i < rings.size(); i += 2)
				rods[rings[i + 1] - '0'] |= 1 << (rings[i] - 'A');

			int cnt = 0;
			for (int i = 0; i < rods.size(); ++i)
				if (rods[i] & (1 << ('R' - 'A')) && rods[i] & (1 << ('G' - 'A'))
						&& rods[i] & (1 << ('B' - 'A')))
					cnt++;
			return cnt;
		}

		// time: O(n)
		// space: O(1)
		int countPointsArray(string& rings)
		{
			int freq[10][3] = {0};
			for (int i = 0; i < rings.size(); i += 2) {
				int pos = (rings[i] == 'R') ? 0 : (rings[i] == 'G') ? 1 : 2;
				freq[rings[i + 1] - '0'][pos] = 1;
			}

			int cnt = 0;
			for (int i = 0; i < 10; ++i)
				if (freq[i][0] && freq[i][1] && freq[i][2])
					cnt++;
			return cnt;
		}
};

int main(int argc, char** argv)
{
}
