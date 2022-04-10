// https://leetcode.com/problems/baseball-game/

#include <numeric>
#include <deque>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	int calPoints(vector<string>& ops)
	{
		std::deque<int> stk;
		for (const auto& op : ops) {
			if (op.front() == '+') {
				auto prev = stk.back();
				stk.pop_back();
				auto sum = prev + stk.back();
				stk.push_back(prev);
				stk.push_back(sum);
			} else if (op.front() == 'D') {
				stk.push_back(stk.back() * 2);
			} else if (op.front() == 'C') {
				stk.pop_back();
			} else {
				int multiplier = 1;
				int score = 0;
				for (char c : op) {
					if (c == '-')
						multiplier = -1;
					else
						score = score * 10 + c - '0';
				}
				score *= multiplier;
				stk.push_back(score);
			}
		}

		return std::accumulate(begin(stk), end(stk), 0, std::plus<int>());
	}
};

int main(int argc, char** argv)
{
	std::vector<std::string> ops{"1","C","-62","-45","-68"};
	std::cout << Solution().calPoints(ops) << '\n';
}
