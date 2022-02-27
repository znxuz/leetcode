// https://leetcode.com/problems/longest-palindromic-substring/solution/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		// check from center, skip duplicates and set new i for next iteration
		// time: O(n^2)
		// space: O(1)
		string longestPalindrome(string s)
		{
			if (s.empty() || s.size() == 1)
				return s;

			int n = s.size();
			int start = 0;
			int max_len = 1;
			for (int i = 0; i < n;) {
				if (n - i <= max_len / 2)
					break;
				int j = i;
				int k = i;
				while (k < n - 1 && s[k + 1] == s[j])
					k++;
				i = k + 1;
				while (j > 0 && k < n - 1 && s[j - 1] == s[k + 1])
					j--, k++;
				int new_len = k - j + 1; // get len by indices arithmetic + 1
				if (new_len > max_len)
					start = j, max_len = new_len;
			}

			return s.substr(start, max_len);
		}
};

int main(int argc, char** argv)
{
}
