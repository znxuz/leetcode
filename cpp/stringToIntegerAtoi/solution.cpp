// https://leetcode.com/problems/string-to-integer-atoi/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
	public:
		// time: O(n)
		// space: O(1)
		int myAtoi(string s)
		{
			int res = 0;
			int i = 0;
			while (s[i] == ' ')
				++i;
			bool neg = false;
			if (s[i] == '-' || s[i] == '+')
				neg = s[i++] == '-' ? true : false;
			while (s[i] == '0')
				++i;
			while (isdigit(s[i])) {
				int cur = s[i] - '0';
				if (res > INT_MAX / 10 || (res == INT_MAX / 10 && cur > 7)) {
					res = INT_MAX;
					break;
				}
				if (res < INT_MIN / 10 || (res == INT_MIN / 10 && cur > 8)) {
					res = INT_MIN;
					break;
				}
				res = res * 10 + ((neg) ? -cur : cur);
				++i;
			}

			return res;
		}
};

int main(int argc, char** argv)
{
}
