// https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
	public:
		int maxArea(vector<int>& height)
		{
			int max = -1;
			int l = 0;
			int r = height.size() - 1;
			while (l < r) {
				max = std::max(max, std::min(height[r], height[l]) * (r - l));
				if (height[l] < height[r])
					l++;
				else
					r--;
			}

			return max;
		}

		int maxAreaBruteForce(vector<int>& height)
		{
			int max = -1;

			for (int i = 0; i < height.size(); ++i)
				for (int j = 1; j < height.size(); ++j)
					max = std::max(max, std::min(height[i], height[j]) * (j - i));

			return max;
		}
};

int main(int argc, char** argv)
{
}
