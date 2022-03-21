// https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		// time: O(n * m)
		// space: O(1)
		vector<int> spiralOrder(vector<vector<int>>& matrix)
		{
			size_t n = matrix.size();
			size_t m = matrix[0].size();
			int direction = 1;
			int i = 0;
			int j = -1;
			vector<int> res;
			while (n > 0 && m > 0) {
				for (size_t k = 0; k < m; ++k) {
					j += direction;
					res.push_back(matrix[i][j]);
				}
				--n;
				for (size_t k = 0; k < n; ++k) {
					i += direction;
					res.push_back(matrix[i][j]);
				}
				--m;
				direction *= -1;
			}

			return res;
		}
};

int main(int argc, char** argv)
{
}
