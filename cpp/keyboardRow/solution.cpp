// https://leetcode.com/problems/keyboard-row/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	vector<string> findWords(vector<string>& words)
	{
		std::vector<std::string> rows{"qwertyuiop", "asdfghjkl", "zxcvbnm"};

		std::vector<std::string> res;
		for (const std::string& w : words) {
			for (const std::string& r : rows) {
				size_t i = 0;
				while (i < w.size() &&
						r.find(static_cast<char>(std::tolower(w[i]))) != std::string::npos)
					++i;
				if (i == w.size()) {
					res.push_back(w);
					break;
				}
			}
		}

		return res;
	}
};

int main(int argc, char** argv)
{
	std::vector<std::string> words{"Hello","Alaska","Dad","Peace"};
	auto res = Solution().findWords(words);
	iter_print(begin(res), end(res));
}
