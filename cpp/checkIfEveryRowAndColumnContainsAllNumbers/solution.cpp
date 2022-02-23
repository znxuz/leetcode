// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <bitset>

using namespace std;

class Solution
{
	public:
		// time: O(n^2)
		// space: O(n)
		bool checkValid(vector<vector<int>>& mtrx)
		{
			int n = mtrx.size();
			for (int i = 0; i < n; ++i) {
				bitset<101> row;
				bitset<101> col;
				for (int j = 0; j < n; ++j)
					row[mtrx[i][j]] = col[mtrx[j][i]] = true;
				if (min(row.count(), col.count()) < n)
					return false;
			}

			return true;
		}

};

int main()
{
}
