// https://leetcode.com/problems/minimum-moves-to-convert-string/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		int minimumMoves(string s)
		{
			int cnt = 0;
			for (int i = 0; i < s.size(); i += (s[i] == 'X' ? 3 : 1))
				cnt += s[i] == 'X' ? 1 : 0;
			return cnt;
		}
};

int main(int argc, char** argv)
{
}
