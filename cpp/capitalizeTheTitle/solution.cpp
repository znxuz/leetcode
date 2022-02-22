// https://leetcode.com/problems/capitalize-the-title/

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
	public:
		string capitalizeTitle(string title)
		{
			stringstream ss{title};
			string w;
			string res;
			while (getline(ss, w, ' ')) {
				for (int i = 0; i < w.size(); ++i)
					w[i] = (i == 0 && w.size() > 2)
						? std::toupper(w[i]) : std::tolower(w[i]);
				res += w + ' ';
			}

			res.pop_back();
			return res;
		}

		// time: O(n)
		// space: O(1)
		string capitalizeTitleLoop(string title)
		{
			int i = 0;
			int j = 0;
			while (i < title.size() || j < title.size()) {
				if (j < title.size() && title[j] != ' ') {
					j++;
					continue;
				}
				if (j - i > 2) {
					title[i] = std::toupper(title[i]);
					i++;
				}
				while (i < j) {
					title[i] = std::tolower(title[i]);
					i++;
				}
				i++;
				j++;
			}

			return title;
		}
};

int main(int argc, char** argv)
{
}
