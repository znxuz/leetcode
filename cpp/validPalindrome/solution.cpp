// https://leetcode.com/problems/valid-palindrome/

#include <cctype>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		bool isPalindrome(string s)
		{
			std::size_t lo = 0;
			std::size_t hi = s.size() - 1;
			while (lo < hi) {
				if (!isalnum(s[lo]))
					++lo;
				else if (!isalnum(s[hi]))
					--hi;
				else if (tolower(s[lo++]) != tolower(s[hi--]))
					return false;
			}

			return true;
		}
};

int main(int argc, char** argv)
{
}
