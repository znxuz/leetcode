// https://leetcode.com/problems/valid-word-square/

#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool validWordSquare(vector<string>& words)
	{
		size_t n = words.size();
		if (n == 0)
			return true;

		for (size_t i = 0; i < n; ++i) {
			for (size_t j = 0; j < words[i].size(); ++j) {
				if (j >= n || i >= words[j].size() || words[i][j] != words[j][i])
					return false;
			}
		}

		return true;
	}
};

int main(int argc, char** argv)
{
	std::vector<std::string> vec1{"ball","asee","let","lep"};
	std::vector<std::string> vec2{"ball","asee","lett","le"};
	std::vector<std::string> vec3{"abc", "b"};
	std::cout << Solution().validWordSquare(vec1) << '\n';
	std::cout << Solution().validWordSquare(vec2) << '\n';
	std::cout << Solution().validWordSquare(vec3) << '\n';
}
