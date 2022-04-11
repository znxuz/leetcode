// https://leetcode.com/problems/assign-cookies/

#include <functional>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace util;

class Solution
{
public:
	// time: O(n * log(n) + n * log(m))
	// space: O(n * log(n) + n * log(m))
	int findContentChildren(std::vector<int>& children, std::vector<int>& cookies)
	{
		return sort(children, cookies);
	}

private:
	int sort(std::vector<int>& children, std::vector<int>& cookies)
	{
		std::sort(begin(children), end(children));
		std::sort(begin(cookies), end(cookies), std::greater<int>());

		int cnt = 0;
		for (auto c : children) {
			while (!cookies.empty() && cookies.back() < c)
				cookies.pop_back();
			if (cookies.empty())
				break;
			cookies.pop_back();
			++cnt;
		}

		return cnt;
	}
};

int main(int argc, char** argv)
{
}
