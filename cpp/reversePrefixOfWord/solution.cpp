// https://leetcode.com/problems/reverse-prefix-of-word

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
		string reversePrefix(string word, char ch)
		{
			int idx = word.find(ch);
			for (int i = 0; i < idx; ++i, --idx)
				swap(word[i], word[idx]);

			// reverse(word.begin(), word.begin() + word.find(ch) + 1);
			return word;
		}
};

int main(int argc, char** argv)
{
}
