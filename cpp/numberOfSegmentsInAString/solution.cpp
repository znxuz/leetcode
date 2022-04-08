// https://leetcode.com/problems/number-of-segments-in-a-string/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int countSegments(string s)
	{
		int count = 0;
		bool isPrevSpace = true;
		for (char c : s) {
			if (c == ' ') {
				isPrevSpace = true;
			} else {
				if (isPrevSpace)
					count++;
				isPrevSpace = false;
			}
		}

		return count;
	}
};

int main(int argc, char** argv)
{
}
