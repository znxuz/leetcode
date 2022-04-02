// https://leetcode.com/problems/simplify-path/

#include <sstream>
#include <deque>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	string simplifyPath(string path)
	{
		std::deque<string> deq;
		std::string tmp;
		std::istringstream ss(path);
		while (std::getline(ss, tmp, '/')) {
			if (!tmp.empty() && tmp != "." && tmp != "..") {
				deq.push_back(tmp);
			} else if (tmp == ".." && !deq.empty()) {
				deq.pop_back();
			}
		}

		std::string res;
		std::for_each(begin(deq), end(deq), [&res](const auto& p) { res += "/" + p; });
		return (!res.empty() ? res : "/");
	}
};

int main(int argc, char** argv)
{
}
