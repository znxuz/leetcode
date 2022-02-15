// https://leetcode.com/problems/convert-1d-array-into-2d-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		vector<vector<int>> construct2DArray(vector<int>& original, int row, int col)
		{
			vector<vector<int>> v;
			if (row * col != original.size())
				return v;

			for (auto n : original) {
				if (v.empty() || v.back().size() == col)
					v.push_back({});
				v.back().push_back(n);
			}
			return v;
		}
};

int main(int argc, char** argv)
{
}
