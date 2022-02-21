// https://leetcode.com/problems/two-furthest-houses-with-different-colors/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		int maxDistance(vector<int>& colors)
		{
			int i = colors.size() - 1;
			while (i >= 0 && colors[i] == colors[0])
				i--;

			int j = 0;
			while (j < colors.size() && colors[j] == colors.back())
				j++;

			return std::max(i, static_cast<int>(colors.size()) - 1 - j);
		}

		// time: O(n^2)
		// space: O(1)
		int maxDistanceBrute(vector<int>& colors)
		{
			int max = -1;
			for (int i = 0; i < colors.size(); i++) {
				for (int j = i + 1; j < colors.size(); ++j) {
					if (colors[i] != colors[j])
						max = std::max(max, std::abs(i - j));
				}
			}

			return max;
		}
};

int main(int argc, char** argv)
{
}
