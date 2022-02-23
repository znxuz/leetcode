// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		vector<string> divideString(string s, int k, char fill)
		{
			vector<string> res((s.size() + k - 1) / k, string(k, fill));
			for (int i = 0; i < s.size(); ++i)
				res[i / k][i % k] = s[i];

			return res;
		}
};

int main(int argc, char** argv)
{
}
