// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/submissions/

#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		bool areNumbersAscending(string s)
		{
			int cur = 0;
			int prev = 0;
			for (char c : s) {
				if (std::isdigit(c)) {
					cur = cur * 10 + (c - '0');
				} else if (cur != 0) {
					if (prev >= cur)
						return false;
					prev = cur;
					cur = 0;
				}
			}
			return cur == 0 || cur > prev;
		}
};

int main(int argc, char** argv)
{
}
