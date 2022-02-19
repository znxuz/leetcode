// https://leetcode.com/problems/number-of-valid-words-in-a-sentence/submissions/

#include <cctype>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Solution
{
	public:
		int countValidWords(string s)
		{
			int cnt = 0;
			regex reg {"(([a-zA-Z]*)|([a-zA-Z]+-[a-zA-Z]+))[,.!]?"};
			stringstream ss {s};
			string w;
			for (string w; getline(ss, w, ' '); ) {
				if (!w.empty() && regex_match(w, reg))
					cnt++;
			}

			return cnt;
		}

		// time complexity: O(n)
		// space copmlexity: O(n)
		int countValidWordsScan(string s)
		{
			int cnt = 0;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == ' ')
					continue;

				int j = 0;
				while (i + j < s.size() && s[i + j] != ' ')
					j++;
				cnt += (valid(s.substr(i, j))) ? 1 : 0;
				i += j;
			}

			return cnt;
		}

		bool valid(string w)
		{
			int hyphen = 0;
			int punct = 0;
			for (int i = 0; i < w.size(); ++i) {
				if (isdigit(w[i]))
					return false;
				if (w[i] == '-'
						&& (hyphen++ > 0 || i == 0 || i == w.size() - 1
							|| !isalpha(w[i - 1]) || !isalpha(w[i + 1])))
					return false;
				if ((w[i] == '!' || w[i] == ',' || w[i] == '.')
						&& (punct++ > 0 || i != w.size() - 1))
					return false;
			}

			return true;
		}
};

int main(int argc, char** argv)
{
	string s = "!this  1-s b8d!";
	cout << Solution().countValidWords(s) << endl;
}
