// https://leetcode.com/problems/count-vowel-substrings-of-a-string/

#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		int countVowelSubstrings(string word)
		{
			int ret = 0;
			unordered_map<char, bool> flags {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
			for (int i = 0; i < word.size(); ++i) {
				if (!flags.count(word[i]))
					continue;
				for (int j = i; j < word.size() && flags.count(word[j]); ++j) {
					flags[word[j]] = 1;
					int cnt = 0;
					for (const pair<char, bool>& p : flags)
						cnt += p.second;
					if (cnt == 5)
						ret++;
				}
				for (unordered_map<char, bool>::iterator p = flags.begin(); p != flags.end(); ++p)
					p->second = 0;
			}
			return ret;
		}
};

int main(int argc, char** argv)
{
}
