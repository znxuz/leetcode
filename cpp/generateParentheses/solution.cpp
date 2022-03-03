// https://leetcode.com/problems/generate-parentheses/

#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_set>

#include "helper.h"

#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

class Solution
{
	public:
		vector<string> generateParenthesis(int n)
		{
			vector<string> res;
			back_track(res, string(), 0, 0, n * 2);

			return res;
		}

		void back_track(vector<string>& res, string s, int open, int close, int len)
		{
			if (s.size() == len) {
				res.push_back(s);
				return;
			}

			if (open < len / 2)
				back_track(res, s + '(', open + 1, close, len);
			if (close < open)
				back_track(res, s + ')', open, close + 1, len);
		}

		// brute force
		// time: O(2^(2n)n)
		// space: O(n)
		vector<string> generateParenthesisBruteForce(int n)
		{
			vector<string> res;
			generate(string(), res, n * 2);

			return res;
		}

		void generate(string s, vector<string>& res, int len)
		{
			if (s.size() == len) {
				if (valid_parens(s))
					res.push_back(s);
				return;
			}

			generate(s + '(', res, len);
			generate(s + ')', res, len);
		}

		bool valid_parens(string& s)
		{
			int balance = 0;
			for (char c : s) {
				if (balance < 0)
					return false;
				balance += (c == '(' ? 1 : -1);
			}
			return balance == 0;
		}
};

int main(int argc, char** argv)
{
	int n = 3;
	v_print(Solution().generateParenthesis(n));
}
