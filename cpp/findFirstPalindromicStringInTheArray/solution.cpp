// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	// time: O(n * m)
	// space: O(1)
    string firstPalindrome(vector<string>& words)
	{
		for (auto& w : words) {
			int i = 0;
			int j = w.size() - 1;
			while (i < j && w[i] == w[j]) {
				i++;
				j--;
			}
			if (i >= j)
				return w;
		}
		return "";
    }
};

int main(int argc, char** argv)
{
}
