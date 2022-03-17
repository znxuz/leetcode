// https://leetcode.com/problems/multiply-strings/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "helper.h"

using namespace std;

class Solution
{
	public:
		// time: O(n * m)
		// space: O(n)
		string multiply(string num1, string num2)
		{
			std::reverse(begin(num1), end(num1));
			std::reverse(begin(num2), end(num2));

			std::string res;
			res.resize(num1.size() + num2.size());
			for (size_t i = 0; i < num2.size(); ++i) {
				int n2 = num2[i] - '0';
				for (size_t j = 0; j < num1.size(); ++j) {
					int n1 = num1[j] - '0';
					int prod = n1 * n2;
					res[i + j] += prod % 10;
					res[i + j + 1] += prod / 10 + res[i + j] / 10;
					res[i + j] %= 10;
				}
			}
			while (!res.empty() && res.back() == 0)
				res.pop_back();

			if (res.empty())
				return "0";
			for (auto& digit : res)
				digit += '0';
			reverse(begin(res), end(res));
			return res;
		}
};

int main(int argc, char** argv)
{
	Solution s;
	for (size_t i = 0; i < 200; ++i) {
		for (size_t j = 0; j < 200; ++j) {
			if (static_cast<int>(i * j) != std::stoi(s.multiply(to_string(i), to_string(j))))
				cout << "wrong answer\n";
		}
	}
}
