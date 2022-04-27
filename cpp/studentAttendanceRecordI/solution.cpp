// https://leetcode.com/problems/student-attendance-record-i/

#include <regex>
#include <iostream>
#include <vector>

#include "helper.h"

using namespace std;
using namespace util;

class Solution
{
public:
	bool checkRecord(string s)
	{
		return regex(s);
	}

private:
	bool regex(const std::string& s)
	{
		return !std::regex_search(s, std::regex(".*(A.*A|LLL).*"));
	}

	bool one_pass(const std::string& s)
	{
		size_t absent = 0;
		size_t late = 0;
		size_t late_streak = 0;
		for (char a : s) {
			if (a == 'L') {
				late_streak = std::max(late_streak, ++late);
			} else {
				if (a == 'A')
					++absent;
				late = 0;
			}
		}

		return absent < 2 && late_streak < 3;
	}
};

int main(int argc, char** argv)
{
}
