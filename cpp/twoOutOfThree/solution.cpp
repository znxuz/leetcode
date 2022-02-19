// https://leetcode.com/problems/two-out-of-three/submissions/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
		{
			vector<vector<bool>> flags(3, vector<bool>(101));
			for (auto n : nums1)
				flags[0][n] = true;
			for (auto n : nums2)
				flags[1][n] = true;
			for (auto n : nums3)
				flags[2][n] = true;

			vector<int> v;
			for (int i = 0; i < flags[0].size(); ++i)
				if (flags[0][i] + flags[1][i] + flags[2][i] > 1)
					v.push_back(i);

			return v;
		}
};

int main(int argc, char** argv)
{
}
