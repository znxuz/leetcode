// https://leetcode.com/problems/zigzag-conversion/

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(n)
		string convert(string s, int numRows)
		{
			vector<string> arr(numRows);
			int j = 0;
			bool desc = false;
			for (int i = 0; i < s.size(); ++i) {
				if (j == 0 || j == numRows - 1)
					desc = !desc;
				arr[j].push_back(s[i]);
				j += (numRows == 1) ? 0 : (desc) ? 1 : -1;
			}

			string res;
			for (auto& row : arr)
				res += row;

			return res;
		}
};

int main(int argc, char** argv)
{
	string s = "AB";
	cout << Solution().convert(s, 1) << '\n';
}
