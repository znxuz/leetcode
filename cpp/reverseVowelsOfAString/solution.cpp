// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <cctype>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	string reverseVowels(string s)
	{
		return two_pointers(s);
	}

private:
	string two_pointers(const string& s)
	{
		if (s.empty())
			return s;

		string res(s);
		size_t i = 0;
		size_t j = res.size() - 1;
		while (i < j) {
			if (!is_vowel(res[i]))
				++i;
			else if (!is_vowel(res[j]))
				--j;
			else
				std::swap(res[i], res[j]), ++i, --j;
		}

		return res;
	}

	bool is_vowel(int c)
	{
		c = std::tolower(c);
		return c == 'a' || c == 'e' || c == 'i' ||c == 'o' || c == 'u';
	}
};

int main(int argc, char** argv)
{
	std::cout << Solution().reverseVowels("leetcode") << '\n';
}
