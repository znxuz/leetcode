// https://leetcode.com/problems/add-strings/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	string addStrings(string num1, string num2)
	{
		string res;
		int carry = 0;
		int i = num1.size();
		int j = num2.size();
		while (i || j || carry) {
			int sum = 0;
			sum += (i ? num1[--i] - '0' : 0);
			sum += (j ? num2[--j] - '0' : 0);
			sum += carry;
			carry = std::exchange(sum, sum % 10) / 10;
			res.push_back(static_cast<char>(sum + '0'));
		}

		std::reverse(std::begin(res), std::end(res));
		return res;
	}
};

int main(int argc, char** argv)
{
	std::string n1 = "11";
	std::string n2 = "123";
	std::cout << Solution().addStrings(n1, n2) << '\n';
}
