// https://leetcode.com/problems/length-of-last-word/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	// time: O(n)
	// space: O(1)
    int lengthOfLastWord(string s)
	{
		int len = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] == ' ' && len != 0)
				return len;
			len += s[i] == ' ' ? 0 : 1;
		}

		return len;
    }
};

int main(int argc, char** argv)
{
}
