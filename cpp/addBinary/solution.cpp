// https://leetcode.com/problems/add-binary/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// time: O(n + m)
		// space: O(1)
		string addBinary(string a, string b)
		{
			int i = a.size() - 1;
			int j = b.size() - 1;
			string ret;
			int carry = 0;
			while (i >= 0 || j >= 0) {
				int res = carry;
				res += (i >= 0) ? a[i--] - '0' : 0;
				res += (j >= 0) ? b[j--] - '0' : 0;
				carry = (res / 2);
				res = res % 2 + '0';
				ret.push_back(res);
			}

			if (carry)
				ret.push_back('1');
			reverse(ret.begin(), ret.end());
			return ret;
		}
};

int main(int argc, char** argv)
{
}
